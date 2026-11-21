// Pause menu: a column of icon buttons on the right, the time (plus Safari/Pyramid info) at the top left,
// and the hovered item's name at the bottom right.
// Structure follows Miriam's Unbound Style Start Menu (github.com/miriamlefae/pokeemerald-expansion, feat/usm/upcoming),
// and the art in graphics/unbound_start_menu comes from that branch (icons by Vol and Brendan).
// Link rooms and the Union Room still use the old menu in start_menu.c.
#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "debug.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "frontier_pass.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pause_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "rtc.h"
#include "safari_zone.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trainer_card.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/script_menu.h"
#include "constants/songs.h"

// Order matches the old start menu's MENU_ACTION_* values, which the Pokégear tutorial script checks in VAR_RESULT
enum PauseMenuItem
{
    PAUSE_ITEM_POKEDEX,
    PAUSE_ITEM_POKEMON,
    PAUSE_ITEM_BAG,
    PAUSE_ITEM_POKEGEAR,
    PAUSE_ITEM_TRAINER,
    PAUSE_ITEM_SAVE,
    PAUSE_ITEM_OPTIONS,
    PAUSE_ITEM_REST,
    PAUSE_ITEM_RETIRE,
    PAUSE_ITEM_DEBUG,
    PAUSE_ITEM_DEXNAV,
    PAUSE_ITEM_COUNT,
};

enum
{
    PAUSE_WIN_ICONS,
    PAUSE_WIN_INFO,
    PAUSE_WIN_LABEL,
    PAUSE_WIN_COUNT,
};

enum
{
    ICON_AFFINE_IDLE,
    ICON_AFFINE_HOVER,
};

#define PAUSE_MENU_MAX_ITEMS  9
#define PAUSE_MENU_PAL        13     // BG palette; weather doesn't tint 13-15
#define PAUSE_MENU_BASE_TILE  0x21D  // BG0 tiles after the std window frame, clear of the message box
#define TAG_PAUSE_ICONS       0x7A02 // + item
#define TAG_PAUSE_ICON_PAL    (0x7A02 | BLEND_IMMUNE_FLAG) // so weather doesn't tint the icons

// Icon column on the right
#define ICON_PANEL_LEFT   25 // tiles
#define ICON_PANEL_WIDTH  5  // tiles
#define ICON_PANEL_EDGE   2  // px, accent line down the panel's left side
#define SLOT_WIDTH        28 // px
#define SLOT_X            ((ICON_PANEL_WIDTH * 8 + ICON_PANEL_EDGE - SLOT_WIDTH) / 2) // px, inside the panel
#define SLOT_MAX_PITCH    24 // px from one slot's top to the next; shrinks to fit more items
#define ICON_X            (ICON_PANEL_LEFT * 8 + SLOT_X + SLOT_WIDTH / 2)

// Info (time) panel at the top left, label panel at the bottom right
#define INFO_WIDTH   9 // tiles
#define LABEL_WIDTH  7 // tiles

// Indexes into graphics/unbound_start_menu/bg/14.pal
#define COLOR_TEXT    1
#define COLOR_SHADOW  2
#define COLOR_PANEL   10
#define COLOR_SLOT    11
#define COLOR_ACCENT  13

struct PauseMenuItemInfo
{
    const u8 *label;
    const u32 *iconGfx; // 32x64: idle frame, then hover frame
    void (*open)(void);
    bool8 fadeFirst;    // open() runs once the screen is black and the overworld windows are freed
};

struct PauseMenu
{
    u8 items[PAUSE_MENU_MAX_ITEMS];
    u8 itemCount;
    u8 spriteIds[PAUSE_MENU_MAX_ITEMS];
    u8 windowIds[PAUSE_WIN_COUNT];
    bool8 inDarkness;
    bool8 forTutorial;
};

static EWRAM_DATA struct PauseMenu *sPauseMenu = NULL;
static EWRAM_DATA u8 sPauseMenuCursor = 0; // kept between openings, so the menu reopens where it was left

static void OpenPokedex(void);
static void OpenParty(void);
static void OpenBag(void);
static void OpenPokegear(void);
static void OpenTrainerCard(void);
static void OpenSave(void);
static void OpenOptions(void);
static void OpenRetire(void);
static void OpenDebug(void);
static void OpenDexNav(void);
static void Task_PauseMenu(u8 taskId);

static const u16 sPauseMenu_Pal[] = INCBIN_U16("graphics/unbound_start_menu/bg/14.gbapal");
static const u16 sPauseIcons_Pal[] = INCBIN_U16("graphics/unbound_start_menu/sprites/icons.gbapal");
static const u8 sStepIcon_Gfx[] = INCBIN_U8("graphics/unbound_start_menu/step.4bpp");
static const u8 sBallIcon_Gfx[] = INCBIN_U8("graphics/unbound_start_menu/ball.4bpp");
static const u8 sFloorIcon_Gfx[] = INCBIN_U8("graphics/unbound_start_menu/floor.4bpp");

static const u32 sIcon_Pokedex_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/pokedex.4bpp");
static const u32 sIcon_Party_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/party.4bpp");
static const u32 sIcon_Bag_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/bag.4bpp");
static const u32 sIcon_Pokenav_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/pokenav.4bpp");
static const u32 sIcon_Trainer_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/trainer.4bpp");
static const u32 sIcon_Save_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/save.4bpp");
static const u32 sIcon_Options_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/options.4bpp");
static const u32 sIcon_Retire_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/retire.4bpp");
static const u32 sIcon_Debug_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/debug.4bpp");
static const u32 sIcon_Dexnav_Gfx[] = INCBIN_U32("graphics/unbound_start_menu/sprites/dexnav.4bpp");

static const struct PauseMenuItemInfo sPauseMenuItems[PAUSE_ITEM_COUNT] =
{
    [PAUSE_ITEM_POKEDEX]  = {gText_MenuPokedex,          sIcon_Pokedex_Gfx, OpenPokedex,     TRUE},
    [PAUSE_ITEM_POKEMON]  = {gText_MenuPokemon,          sIcon_Party_Gfx,   OpenParty,       TRUE},
    [PAUSE_ITEM_BAG]      = {gText_MenuBag,              sIcon_Bag_Gfx,     OpenBag,         TRUE},
    [PAUSE_ITEM_POKEGEAR] = {gText_MenuPokenav,          sIcon_Pokenav_Gfx, OpenPokegear,    TRUE},
    [PAUSE_ITEM_TRAINER]  = {gText_MenuPlayer,           sIcon_Trainer_Gfx, OpenTrainerCard, TRUE},
    [PAUSE_ITEM_SAVE]     = {gText_MenuSave,             sIcon_Save_Gfx,    OpenSave,        FALSE},
    [PAUSE_ITEM_OPTIONS]  = {gText_MenuOption,           sIcon_Options_Gfx, OpenOptions,     TRUE},
    [PAUSE_ITEM_REST]     = {gText_MenuRest,             sIcon_Save_Gfx,    OpenSave,        FALSE},
    [PAUSE_ITEM_RETIRE]   = {gText_MenuRetire,           sIcon_Retire_Gfx,  OpenRetire,      FALSE},
    [PAUSE_ITEM_DEBUG]    = {COMPOUND_STRING("Debug"),   sIcon_Debug_Gfx,   OpenDebug,       FALSE},
    [PAUSE_ITEM_DEXNAV]   = {gText_MenuDexNav,           sIcon_Dexnav_Gfx,  OpenDexNav,      FALSE},
};

static const struct WindowTemplate sPauseMenuWindowTemplates[PAUSE_WIN_COUNT] =
{
    [PAUSE_WIN_ICONS] =
    {
        .bg = 0,
        .tilemapLeft = ICON_PANEL_LEFT,
        .tilemapTop = 0,
        .width = ICON_PANEL_WIDTH,
        .height = DISPLAY_TILE_HEIGHT,
        .paletteNum = PAUSE_MENU_PAL,
        .baseBlock = PAUSE_MENU_BASE_TILE,
    },
    [PAUSE_WIN_INFO] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 1,
        .width = INFO_WIDTH,
        .height = 4, // cut to 2 when there's no Safari/Pyramid line
        .paletteNum = PAUSE_MENU_PAL,
        .baseBlock = PAUSE_MENU_BASE_TILE + ICON_PANEL_WIDTH * DISPLAY_TILE_HEIGHT,
    },
    [PAUSE_WIN_LABEL] =
    {
        .bg = 0,
        .tilemapLeft = ICON_PANEL_LEFT - 1 - LABEL_WIDTH,
        .tilemapTop = DISPLAY_TILE_HEIGHT - 3,
        .width = LABEL_WIDTH,
        .height = 2,
        .paletteNum = PAUSE_MENU_PAL,
        .baseBlock = PAUSE_MENU_BASE_TILE + ICON_PANEL_WIDTH * DISPLAY_TILE_HEIGHT + INFO_WIDTH * 4,
    },
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, COLOR_TEXT, COLOR_SHADOW};

static const u8 *const sWeekdayNames[WEEKDAY_COUNT] =
{
    [WEEKDAY_SUN] = COMPOUND_STRING("Sun"),
    [WEEKDAY_MON] = COMPOUND_STRING("Mon"),
    [WEEKDAY_TUE] = COMPOUND_STRING("Tue"),
    [WEEKDAY_WED] = COMPOUND_STRING("Wed"),
    [WEEKDAY_THU] = COMPOUND_STRING("Thu"),
    [WEEKDAY_FRI] = COMPOUND_STRING("Fri"),
    [WEEKDAY_SAT] = COMPOUND_STRING("Sat"),
};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1, gText_Floor2, gText_Floor3, gText_Floor4, gText_Floor5, gText_Floor6, gText_Floor7, gText_Peak,
};

// Icons are 32x32. Double-size affine so they can grow/rotate without being clipped
static const struct OamData sOam_PauseIcon =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};

static const union AnimCmd sAnim_PauseIconIdle[] = {ANIMCMD_FRAME(0, 1), ANIMCMD_END};
static const union AnimCmd sAnim_PauseIconHover[] = {ANIMCMD_FRAME(16, 1), ANIMCMD_END}; // second 32x32 frame

static const union AnimCmd *const sAnims_PauseIcon[] =
{
    sAnim_PauseIconIdle,
    sAnim_PauseIconHover,
};

static const union AffineAnimCmd sAffineAnim_PauseIconIdle[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

// Scale 0x100 = 1x, rotation 1 = ~1.4 degrees per frame
static const union AffineAnimCmd sAffineAnim_PauseIconHover[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0), // reset
    AFFINEANIMCMD_FRAME(16, 16, 0, 4),       // pop up to 1.25x
    AFFINEANIMCMD_FRAME(-8, -8, 0, 4),       // settle at 1.125x
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),         // sway between about +/-5.6 degrees
    AFFINEANIMCMD_FRAME(0, 0, 0, 8),
    AFFINEANIMCMD_FRAME(0, 0, -1, 8),
    AFFINEANIMCMD_FRAME(0, 0, 0, 8),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_JUMP(3),
};

static const union AffineAnimCmd *const sAffineAnims_PauseIcon[] =
{
    [ICON_AFFINE_IDLE] = sAffineAnim_PauseIconIdle,
    [ICON_AFFINE_HOVER] = sAffineAnim_PauseIconHover,
};

static const struct SpriteTemplate sSpriteTemplate_PauseIcon =
{
    .tileTag = TAG_PAUSE_ICONS, // + item, set per icon
    .paletteTag = TAG_PAUSE_ICON_PAL,
    .oam = &sOam_PauseIcon,
    .anims = sAnims_PauseIcon,
    .affineAnims = sAffineAnims_PauseIcon,
    .callback = SpriteCallbackDummy,
};

// ---------------------------------------------------------------------------
// Menu item actions
// ---------------------------------------------------------------------------

static void OpenPokedex(void)
{
    IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
    SetMainCallback2(CB2_OpenPokedex);
}

static void OpenParty(void)
{
    SetMainCallback2(CB2_PartyMenuFromStartMenu);
}

static void OpenBag(void)
{
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);
    else
        SetMainCallback2(CB2_BagMenuFromStartMenu);
}

static void OpenPokegear(void)
{
    SetMainCallback2(CB2_InitPokeNav);
}

static void OpenTrainerCard(void)
{
    if (FlagGet(FLAG_SYS_FRONTIER_PASS))
        ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu);
    else
        ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu);
}

static void OpenSave(void)
{
    StartMenu_ShowSaveDialog(FALSE);
}

static void OpenOptions(void)
{
    SetMainCallback2(CB2_InitOptionMenu);
    gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
}

static void OpenRetire(void)
{
    if (GetSafariZoneFlag())
    {
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        SafariZoneRetirePrompt();
    }
    else
    {
        StartMenu_ShowSaveDialog(TRUE);
    }
}

static void OpenDebug(void)
{
    FreezeObjectEvents();
    Debug_ShowMainMenu();
}

static void OpenDexNav(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
}

// ---------------------------------------------------------------------------
// Building and drawing
// ---------------------------------------------------------------------------

static void AddItem(enum PauseMenuItem item)
{
    sPauseMenu->items[sPauseMenu->itemCount++] = item;
}

static void BuildItems(void)
{
    bool32 tutorial = sPauseMenu->forTutorial;

    if (GetSafariZoneFlag())
    {
        AddItem(PAUSE_ITEM_RETIRE);
        AddItem(PAUSE_ITEM_POKEDEX);
        AddItem(PAUSE_ITEM_POKEMON);
        AddItem(PAUSE_ITEM_BAG);
        AddItem(PAUSE_ITEM_TRAINER);
        AddItem(PAUSE_ITEM_OPTIONS);
    }
    else if (InBattlePike())
    {
        AddItem(PAUSE_ITEM_POKEDEX);
        AddItem(PAUSE_ITEM_POKEMON);
        AddItem(PAUSE_ITEM_TRAINER);
        AddItem(PAUSE_ITEM_OPTIONS);
    }
    else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        AddItem(PAUSE_ITEM_POKEMON);
        AddItem(PAUSE_ITEM_BAG);
        AddItem(PAUSE_ITEM_TRAINER);
        AddItem(PAUSE_ITEM_REST);
        AddItem(PAUSE_ITEM_RETIRE);
        AddItem(PAUSE_ITEM_OPTIONS);
    }
    else if (InMultiPartnerRoom())
    {
        AddItem(PAUSE_ITEM_POKEMON);
        AddItem(PAUSE_ITEM_TRAINER);
        AddItem(PAUSE_ITEM_OPTIONS);
    }
    else
    {
        if (DEBUG_OVERWORLD_MENU && DEBUG_OVERWORLD_IN_MENU && !tutorial)
            AddItem(PAUSE_ITEM_DEBUG);
        if (FlagGet(FLAG_SYS_POKEDEX_GET))
            AddItem(PAUSE_ITEM_POKEDEX);
        if (DN_FLAG_DEXNAV_GET != 0 && FlagGet(DN_FLAG_DEXNAV_GET) && !tutorial)
            AddItem(PAUSE_ITEM_DEXNAV);
        if (FlagGet(FLAG_SYS_POKEMON_GET))
            AddItem(PAUSE_ITEM_POKEMON);
        if (FlagGet(FLAG_SYS_POKENAV_GET) || tutorial) // the tutorial is where you learn to open it
            AddItem(PAUSE_ITEM_POKEGEAR);
        AddItem(PAUSE_ITEM_BAG);
        AddItem(PAUSE_ITEM_TRAINER);
        AddItem(PAUSE_ITEM_SAVE);
        AddItem(PAUSE_ITEM_OPTIONS);
    }
}

static bool32 HasExtraInfo(void)
{
    return GetSafariZoneFlag() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE;
}

static u32 GetSlotPitch(void)
{
    return min(SLOT_MAX_PITCH, DISPLAY_HEIGHT / sPauseMenu->itemCount);
}

static u32 GetSlotTop(u32 index)
{
    u32 pitch = GetSlotPitch();
    return (DISPLAY_HEIGHT - pitch * sPauseMenu->itemCount) / 2 + index * pitch;
}

// Accent outline around a panel-colored box
static void DrawBoxPanel(u32 windowId)
{
    u32 width = GetWindowAttribute(windowId, WINDOW_WIDTH) * 8;
    u32 height = GetWindowAttribute(windowId, WINDOW_HEIGHT) * 8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(COLOR_ACCENT));
    FillWindowPixelRect(windowId, PIXEL_FILL(COLOR_PANEL), 1, 1, width - 2, height - 2);
}

// Each slot owns a GetSlotPitch()-tall band of the panel. The hovered one grows into the gap with an accent border.
static void DrawSlot(u32 index)
{
    u32 windowId = sPauseMenu->windowIds[PAUSE_WIN_ICONS];
    u32 top = GetSlotTop(index);
    u32 pitch = GetSlotPitch();

    FillWindowPixelRect(windowId, PIXEL_FILL(COLOR_PANEL), ICON_PANEL_EDGE, top, ICON_PANEL_WIDTH * 8 - ICON_PANEL_EDGE, pitch);
    if (index == sPauseMenuCursor)
        FillWindowPixelRect(windowId, PIXEL_FILL(COLOR_ACCENT), SLOT_X - 2, top, SLOT_WIDTH + 4, pitch);
    FillWindowPixelRect(windowId, PIXEL_FILL(COLOR_SLOT), SLOT_X, top + 1, SLOT_WIDTH, pitch - 2);
}

static void DrawIconPanel(void)
{
    u32 windowId = sPauseMenu->windowIds[PAUSE_WIN_ICONS];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(COLOR_PANEL));
    FillWindowPixelRect(windowId, PIXEL_FILL(COLOR_ACCENT), 0, 0, ICON_PANEL_EDGE, DISPLAY_HEIGHT);
    for (u32 i = 0; i < sPauseMenu->itemCount; i++)
        DrawSlot(i);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void PrintInfoPanel(void)
{
    u32 windowId = sPauseMenu->windowIds[PAUSE_WIN_INFO];
    u8 *str;

    DrawBoxPanel(windowId);

    // GetDayOfWeek also updates gLocalTime
    str = StringCopy(gStringVar4, sWeekdayNames[GetDayOfWeek()]);
    *str++ = CHAR_SPACE;
    FormatDecimalTimeWithoutSeconds(str, gLocalTime.hours, gLocalTime.minutes, FALSE);
    AddTextPrinterParameterized3(windowId, FONT_SMALL, 4, 1, sTextColors, TEXT_SKIP_DRAW, gStringVar4);

    if (GetSafariZoneFlag())
    {
        u32 x;

        BlitBitmapToWindow(windowId, sStepIcon_Gfx, 4, 20, 8, 8);
        ConvertIntToDecimalStringN(gStringVar1, gSafariZoneStepCounter, STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized3(windowId, FONT_SMALL, 14, 17, sTextColors, TEXT_SKIP_DRAW, gStringVar1);

        x = 14 + GetStringWidth(FONT_SMALL, gStringVar1, 0) + 6;
        BlitBitmapToWindow(windowId, sBallIcon_Gfx, x, 20, 8, 8);
        ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_LEFT_ALIGN, 2);
        AddTextPrinterParameterized3(windowId, FONT_SMALL, x + 10, 17, sTextColors, TEXT_SKIP_DRAW, gStringVar1);
    }
    else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        BlitBitmapToWindow(windowId, sFloorIcon_Gfx, 4, 20, 8, 8);
        AddTextPrinterParameterized3(windowId, FONT_SMALL, 14, 17, sTextColors, TEXT_SKIP_DRAW,
                                     sPyramidFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    }
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void PrintLabel(void)
{
    u32 windowId = sPauseMenu->windowIds[PAUSE_WIN_LABEL];
    u32 fontId;

    DrawBoxPanel(windowId);
    StringExpandPlaceholders(gStringVar4, sPauseMenuItems[sPauseMenu->items[sPauseMenuCursor]].label);
    fontId = GetFontIdToFit(gStringVar4, FONT_NORMAL, 0, LABEL_WIDTH * 8 - 4);
    AddTextPrinterParameterized3(windowId, fontId, GetStringCenterAlignXOffset(fontId, gStringVar4, LABEL_WIDTH * 8), 1,
                                 sTextColors, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void UpdateIcons(void)
{
    for (u32 i = 0; i < sPauseMenu->itemCount; i++)
    {
        struct Sprite *sprite = &gSprites[sPauseMenu->spriteIds[i]];
        bool32 hovered = (i == sPauseMenuCursor);

        StartSpriteAnim(sprite, hovered);
        StartSpriteAffineAnim(sprite, hovered ? ICON_AFFINE_HOVER : ICON_AFFINE_IDLE);
        sprite->subpriority = hovered ? 0 : 1; // drawn over its neighbors while it's enlarged
    }
}

static void CreateIcons(void)
{
    struct SpriteTemplate template = sSpriteTemplate_PauseIcon;
    struct SpritePalette palette = {sPauseIcons_Pal, TAG_PAUSE_ICON_PAL};

    LoadSpritePalette(&palette);
    for (u32 i = 0; i < sPauseMenu->itemCount; i++)
    {
        u32 item = sPauseMenu->items[i];
        struct SpriteSheet sheet = {sPauseMenuItems[item].iconGfx, 0x400, TAG_PAUSE_ICONS + item};
        u32 spriteId;

        LoadSpriteSheet(&sheet);
        template.tileTag = TAG_PAUSE_ICONS + item;
        spriteId = CreateSprite(&template, ICON_X, GetSlotTop(i) + GetSlotPitch() / 2, 1);
        gSprites[spriteId].copyToObjWin = sPauseMenu->inDarkness;
        sPauseMenu->spriteIds[i] = spriteId;
    }
    UpdateIcons();
}

static void CreatePauseMenu(bool32 forTutorial)
{
    sPauseMenu = AllocZeroed(sizeof(*sPauseMenu));
    sPauseMenu->forTutorial = forTutorial;
    BuildItems();
    if (sPauseMenuCursor >= sPauseMenu->itemCount)
        sPauseMenuCursor = 0;

    HideMapNamePopUpWindow();
    LoadPalette(sPauseMenu_Pal, BG_PLTT_ID(PAUSE_MENU_PAL), PLTT_SIZE_4BPP);
    for (u32 i = 0; i < PAUSE_WIN_COUNT; i++)
    {
        struct WindowTemplate template = sPauseMenuWindowTemplates[i];

        if (i == PAUSE_WIN_INFO && !HasExtraInfo())
            template.height = 2;
        sPauseMenu->windowIds[i] = AddWindow(&template);
        PutWindowTilemap(sPauseMenu->windowIds[i]);
    }

    // Flash darkness hides sprites outside its circle. The icons draw into the OBJ window, which then shows them.
    sPauseMenu->inDarkness = (GetFlashLevel() > 0 || InBattlePyramid());
    if (sPauseMenu->inDarkness)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    DrawIconPanel();
    PrintInfoPanel();
    PrintLabel();
    CreateIcons();
    CreateTask(Task_PauseMenu, 80);
}

static void DestroyPauseMenu(void)
{
    for (u32 i = 0; i < sPauseMenu->itemCount; i++)
    {
        FreeSpriteOamMatrix(&gSprites[sPauseMenu->spriteIds[i]]);
        DestroySprite(&gSprites[sPauseMenu->spriteIds[i]]);
        FreeSpriteTilesByTag(TAG_PAUSE_ICONS + sPauseMenu->items[i]);
    }
    FreeSpritePaletteByTag(TAG_PAUSE_ICON_PAL);

    for (u32 i = 0; i < PAUSE_WIN_COUNT; i++)
    {
        ClearWindowTilemap(sPauseMenu->windowIds[i]);
        RemoveWindow(sPauseMenu->windowIds[i]);
    }
    ScheduleBgCopyTilemapToVram(0);

    if (sPauseMenu->inDarkness)
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        ClearGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }
    TRY_FREE_AND_SET_NULL(sPauseMenu);
}

// ---------------------------------------------------------------------------
// Input
// ---------------------------------------------------------------------------

static void MoveCursor(s32 delta)
{
    u32 oldPos = sPauseMenuCursor;

    PlaySE(SE_SELECT);
    sPauseMenuCursor = (sPauseMenuCursor + sPauseMenu->itemCount + delta) % sPauseMenu->itemCount;
    DrawSlot(oldPos);
    DrawSlot(sPauseMenuCursor);
    CopyWindowToVram(sPauseMenu->windowIds[PAUSE_WIN_ICONS], COPYWIN_GFX);
    UpdateIcons();
    PrintLabel();
}

static void Task_OpenItemAfterFade(u8 taskId)
{
    enum PauseMenuItem item;

    if (gPaletteFade.active)
        return;

    item = sPauseMenu->items[sPauseMenuCursor];
    PlayRainStoppingSoundEffect();
    DestroyPauseMenu();
    CleanupOverworldWindowsAndTilemaps();
    DestroyTask(taskId);
    sPauseMenuItems[item].open();
}

static void SelectItem(u8 taskId)
{
    enum PauseMenuItem item = sPauseMenu->items[sPauseMenuCursor];

    PlaySE(SE_SELECT);
    if (sPauseMenu->forTutorial)
    {
        DestroyPauseMenu();
        DestroyTask(taskId);
        gSpecialVar_Result = item;
        ScriptContext_Enable();
        return;
    }

    if (item == PAUSE_ITEM_POKEDEX && GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
        return;
    if (item == PAUSE_ITEM_DEXNAV && MapHasNoEncounterData())
        return;

    if (sPauseMenuItems[item].fadeFirst)
    {
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_OpenItemAfterFade;
        return;
    }

    // Controls stay locked; the item's screen or prompt unlocks them when it's done
    DestroyPauseMenu();
    DestroyTask(taskId);
    sPauseMenuItems[item].open();
}

static void ClosePauseMenu(u8 taskId)
{
    bool32 forTutorial = sPauseMenu->forTutorial;

    PlaySE(SE_SELECT);
    DestroyPauseMenu();
    DestroyTask(taskId);
    if (forTutorial)
    {
        gSpecialVar_Result = MULTI_B_PRESSED;
        ScriptContext_Enable();
    }
    else
    {
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
    }
}

#define tInputReady data[0]

static void Task_PauseMenu(u8 taskId)
{
    // Skip the frame the menu opens on, or the Start press that opened it would also close it
    if (!gTasks[taskId].tInputReady)
    {
        gTasks[taskId].tInputReady = TRUE;
        return;
    }
    // Wait out the fade in when returning from a submenu
    if (gPaletteFade.active || !IsWeatherNotFadingIn())
        return;

    if (JOY_NEW(DPAD_UP))
        MoveCursor(-1);
    else if (JOY_NEW(DPAD_DOWN))
        MoveCursor(1);
    else if (JOY_NEW(A_BUTTON))
        SelectItem(taskId);
    else if (JOY_NEW(B_BUTTON | START_BUTTON))
        ClosePauseMenu(taskId);
}

// ---------------------------------------------------------------------------
// Entry points
// ---------------------------------------------------------------------------

void PauseMenu_Show(void)
{
    FreezeObjectEvents();
    PlayerFreeze();
    StopPlayerAvatar();
    LockPlayerFieldControls();
    CreatePauseMenu(FALSE);
}

// Used by ScriptMenu_CreateStartMenuForPokenavTutorial: VAR_RESULT gets the chosen PAUSE_ITEM_* or MULTI_B_PRESSED
void PauseMenu_ShowForPokegearTutorial(void)
{
    sPauseMenuCursor = 0;
    CreatePauseMenu(TRUE);
}

// Coming back from a submenu (CB2_ReturnToFieldWithOpenMenu)
bool8 FieldCB_ReturnToFieldOpenPauseMenu(void)
{
    PauseMenu_Show();
    FadeInFromBlack();
    return TRUE;
}
