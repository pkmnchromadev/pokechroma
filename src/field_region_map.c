#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "region_map.h"
#include "sound.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

/*
 *  This is the type of map shown when interacting with the metatiles for
 *  a wall-mounted Region Map (on the wall of the Pokemon Centers near the PC)
 *  It does not zoom, and pressing A or B closes the map
 *
 *  For the region map in the pokenav, see pokenav_region_map.c
 *  For the region map in the pokedex, see pokdex_area_screen.c/pokedex_area_region_map.c
 *  For the fly map, and utility functions all of the maps use, see region_map.c
 */

enum {
    WIN_MAPSEC_NAME,
    WIN_BOTTOM_BAR,
};

// pokechroma: location box sits above the bottom bar; its BG1 area is darkened via WIN0 + BLDY
#define MAPSEC_WIN_LEFT  16
#define MAPSEC_WIN_TOP   16
#define MAPSEC_WIN_WIDTH 14
#define BAR_TOP          18

// 0 = transparent, 1-3 = keypad_icons.png palette (white, gray, light gray), 4 = bar fill
// keypad icons ({B_BUTTON} etc.) are drawn raw with index 1 = button body, 2 = letter, so keep the bar off those
static const u16 sRegionMapTextPal[16] = {RGB_BLACK, RGB2GBA(255, 255, 255), RGB2GBA(98, 98, 98), RGB2GBA(213, 213, 205), RGB2GBA(232, 150, 24)};
static const u8 sMapSecTextColors[] = {0, 1, 2};
static const u8 sBarTextColors[] = {4, 1, 2};

enum {
    TAG_PLAYER_ICON,
    TAG_CURSOR,
};

static EWRAM_DATA struct {
    MainCallback callback;
    u32 unused;
    struct RegionMap regionMap;
    u16 state;
} *sFieldRegionMapHandler = NULL;

static void MCB2_InitRegionMapRegisters(void);
static void VBCB_FieldUpdateRegionMap(void);
static void MCB2_FieldUpdateRegionMap(void);
static void FieldUpdateRegionMap(void);
static void PrintRegionMapSecName();
static void PrintBottomBarText();

static const struct BgTemplate sFieldRegionMapBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct WindowTemplate sFieldRegionMapWindowTemplates[] =
{
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = MAPSEC_WIN_LEFT,
        .tilemapTop = MAPSEC_WIN_TOP,
        .width = MAPSEC_WIN_WIDTH,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_BOTTOM_BAR] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = BAR_TOP,
        .width = DISPLAY_TILE_WIDTH,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1 + MAPSEC_WIN_WIDTH * 2
    },
    DUMMY_WIN_TEMPLATE
};

void FieldInitRegionMap(MainCallback callback)
{
    SetVBlankCallback(NULL);
    sFieldRegionMapHandler = Alloc(sizeof(*sFieldRegionMapHandler));
    sFieldRegionMapHandler->state = 0;
    sFieldRegionMapHandler->callback = callback;
    SetMainCallback2(MCB2_InitRegionMapRegisters);
}

static void MCB2_InitRegionMapRegisters(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sFieldRegionMapBgTemplates, ARRAY_COUNT(sFieldRegionMapBgTemplates));
    InitWindows(sFieldRegionMapWindowTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(sRegionMapTextPal, BG_PLTT_ID(15), sizeof(sRegionMapTextPal));
    ClearScheduledBgCopiesToVram();
    SetMainCallback2(MCB2_FieldUpdateRegionMap);
    SetVBlankCallback(VBCB_FieldUpdateRegionMap);
}

static void VBCB_FieldUpdateRegionMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MCB2_FieldUpdateRegionMap(void)
{
    FieldUpdateRegionMap();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    DoScheduledBgTilemapCopiesToVram();
}

static void FieldUpdateRegionMap(void)
{
    switch (sFieldRegionMapHandler->state)
    {
    case 0:
        InitRegionMap(&sFieldRegionMapHandler->regionMap, FALSE);
        CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
        CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
        sFieldRegionMapHandler->state++;
        break;
    case 1:
        PutWindowTilemap(WIN_BOTTOM_BAR);
        PutWindowTilemap(WIN_MAPSEC_NAME);
        PrintBottomBarText();
        PrintRegionMapSecName();
        ScheduleBgCopyTilemapToVram(0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sFieldRegionMapHandler->state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDY, 8);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
        ShowBg(0);
        ShowBg(1); // pokechroma: region map drawn on BG1
        sFieldRegionMapHandler->state++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            sFieldRegionMapHandler->state++;
        }
        break;
    case 4:
        switch (DoRegionMapInputCallback())
        {
        case MAP_INPUT_MOVE_END:
                PrintRegionMapSecName();
                PrintBottomBarText();
                break;
        case MAP_INPUT_A_BUTTON:
        case MAP_INPUT_B_BUTTON:
                sFieldRegionMapHandler->state++;
                break;
        case MAP_INPUT_R_BUTTON:
                if (sFieldRegionMapHandler->regionMap.mapSecType == MAPSECTYPE_CITY_CANFLY
                    && FlagGet(OW_FLAG_POKE_RIDER) && Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
                {
                    PlaySE(SE_SELECT);
                    SetGpuReg(REG_OFFSET_BLDCNT, 0);
                    SetFlyDestination(&sFieldRegionMapHandler->regionMap);
                    gSkipShowMonAnim = TRUE;
                    ReturnToFieldFromFlyMapSelect();
                }
        }
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sFieldRegionMapHandler->state++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            FreeRegionMapIconResources();
            SetMainCallback2(sFieldRegionMapHandler->callback);
            TRY_FREE_AND_SET_NULL(sFieldRegionMapHandler);
            FreeAllWindowBuffers();
        }
        break;
    }
}

static void PrintRegionMapSecName(void)
{
    u8 name[MAP_NAME_LENGTH + 1];

    GetMapName(name, sFieldRegionMapHandler->regionMap.mapSecId, 0); // regionMap.mapSecName is space-padded, which breaks centering

    FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(0));
    if (sFieldRegionMapHandler->regionMap.mapSecType != MAPSECTYPE_NONE)
    {
        u32 x = GetStringCenterAlignXOffset(FONT_NORMAL, name, MAPSEC_WIN_WIDTH * 8);
        AddTextPrinterParameterized3(WIN_MAPSEC_NAME, FONT_NORMAL, x, 1, sMapSecTextColors, 0, name);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(MAPSEC_WIN_LEFT * 8, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(MAPSEC_WIN_TOP * 8, BAR_TOP * 8));
    }
    else
    {
        // hide the darkened box when the cursor isn't over a location
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
    }
    CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_GFX);
}

static void PrintBottomBarText(void)
{
    static const u8 sCancelText[] = _("{B_BUTTON} Cancel");
    static const u8 sCancelFlyText[] = _("{B_BUTTON} Cancel  {R_BUTTON} FLY");
    const u8 *region = IS_FRLG ? gText_Kanto : gText_Hoenn;
    const u8 *left = sCancelText;

    if (sFieldRegionMapHandler->regionMap.mapSecType == MAPSECTYPE_CITY_CANFLY
        && FlagGet(OW_FLAG_POKE_RIDER) && Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
        left = sCancelFlyText;

    FillWindowPixelBuffer(WIN_BOTTOM_BAR, PIXEL_FILL(4));
    AddTextPrinterParameterized3(WIN_BOTTOM_BAR, FONT_NORMAL, 4, 1, sBarTextColors, 0, left);
    AddTextPrinterParameterized3(WIN_BOTTOM_BAR, FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, region, DISPLAY_WIDTH - 4),
                                 1, sBarTextColors, 0, region);
    CopyWindowToVram(WIN_BOTTOM_BAR, COPYWIN_GFX);
}
