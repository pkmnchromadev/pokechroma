# 1 "data/maps/Route101/scripts.pory"

# 2 "data/maps/Route101/scripts.pory"
.set LOCALID_BIRCH, 2
# 3 "data/maps/Route101/scripts.pory"
.set LOCALID_ZIGZAGOON, 4
# 4 "data/maps/Route101/scripts.pory"

# 5 "data/maps/Route101/scripts.pory"
@Route101_MapScripts::
# 6 "data/maps/Route101/scripts.pory"
@	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 7 "data/maps/Route101/scripts.pory"
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 8 "data/maps/Route101/scripts.pory"
@	.byte 0
# 9 "data/maps/Route101/scripts.pory"

# 10 "data/maps/Route101/scripts.pory"
Route101_OnTransition:
# 11 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data/maps/Route101/scripts.pory"
	end
# 13 "data/maps/Route101/scripts.pory"

# 14 "data/maps/Route101/scripts.pory"
Route101_OnFrame:
# 15 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 16 "data/maps/Route101/scripts.pory"
	.2byte 0
# 17 "data/maps/Route101/scripts.pory"

# 18 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 19 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 20 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 21 "data/maps/Route101/scripts.pory"
	end
# 22 "data/maps/Route101/scripts.pory"

# 23 "data/maps/Route101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 24 "data/maps/Route101/scripts.pory"
	lockall
# 25 "data/maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 26 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 27 "data/maps/Route101/scripts.pory"
	closemessage
# 28 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_BIRCH, 0, 15
# 29 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
# 30 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
# 31 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
# 32 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 33 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 35 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
# 36 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 38 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 39 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 40 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 41 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 42 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 43 "data/maps/Route101/scripts.pory"
	closemessage
# 44 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 45 "data/maps/Route101/scripts.pory"
	releaseall
# 46 "data/maps/Route101/scripts.pory"
	end
# 47 "data/maps/Route101/scripts.pory"

# 48 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 49 "data/maps/Route101/scripts.pory"
	lockall
# 50 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 51 "data/maps/Route101/scripts.pory"
	closemessage
# 52 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
# 53 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route101/scripts.pory"
	releaseall
# 55 "data/maps/Route101/scripts.pory"
	end
# 56 "data/maps/Route101/scripts.pory"

# 57 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 58 "data/maps/Route101/scripts.pory"
	lockall
# 59 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 60 "data/maps/Route101/scripts.pory"
	closemessage
# 61 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
# 62 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route101/scripts.pory"
	releaseall
# 64 "data/maps/Route101/scripts.pory"
	end
# 65 "data/maps/Route101/scripts.pory"

# 66 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 67 "data/maps/Route101/scripts.pory"
	lockall
# 68 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 69 "data/maps/Route101/scripts.pory"
	closemessage
# 70 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
# 71 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 72 "data/maps/Route101/scripts.pory"
	releaseall
# 73 "data/maps/Route101/scripts.pory"
	end
# 74 "data/maps/Route101/scripts.pory"

# 75 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 76 "data/maps/Route101/scripts.pory"
	walk_up
# 77 "data/maps/Route101/scripts.pory"
	step_end
# 78 "data/maps/Route101/scripts.pory"

# 79 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 80 "data/maps/Route101/scripts.pory"
	walk_right
# 81 "data/maps/Route101/scripts.pory"
	step_end
# 82 "data/maps/Route101/scripts.pory"

# 83 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 84 "data/maps/Route101/scripts.pory"
	walk_down
# 85 "data/maps/Route101/scripts.pory"
	step_end
# 86 "data/maps/Route101/scripts.pory"

# 87 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 88 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 89 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 90 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 91 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 92 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 93 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 94 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 95 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 96 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 97 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 98 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 99 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 100 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 101 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 102 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 103 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 104 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 105 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 106 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 107 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 108 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 109 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 110 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 111 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 112 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 113 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 116 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 117 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 118 "data/maps/Route101/scripts.pory"
	step_end
# 119 "data/maps/Route101/scripts.pory"

# 120 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 121 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 122 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 123 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 124 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 127 "data/maps/Route101/scripts.pory"
	step_end
# 128 "data/maps/Route101/scripts.pory"

# 129 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 130 "data/maps/Route101/scripts.pory"
	step_end
# 131 "data/maps/Route101/scripts.pory"

# 132 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 133 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 134 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 135 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 136 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 137 "data/maps/Route101/scripts.pory"
	step_end
# 138 "data/maps/Route101/scripts.pory"

# 139 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 140 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 141 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 142 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 145 "data/maps/Route101/scripts.pory"
	step_end
# 146 "data/maps/Route101/scripts.pory"

# 147 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 148 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 149 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 150 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 151 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 153 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 154 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 155 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 156 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 159 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 160 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 161 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 162 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 163 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 164 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 165 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 166 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 167 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 168 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 170 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 171 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 172 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 173 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 174 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 175 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 177 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 178 "data/maps/Route101/scripts.pory"
	step_end
# 179 "data/maps/Route101/scripts.pory"

# 180 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 181 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 182 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 183 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 184 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 185 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 186 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 187 "data/maps/Route101/scripts.pory"
	step_end
# 188 "data/maps/Route101/scripts.pory"

# 189 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 190 "data/maps/Route101/scripts.pory"
	step_end
# 191 "data/maps/Route101/scripts.pory"

# 192 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 193 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 194 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 195 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 196 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 197 "data/maps/Route101/scripts.pory"
	step_end
# 198 "data/maps/Route101/scripts.pory"

# 199 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 200 "data/maps/Route101/scripts.pory"
	walk_up
# 201 "data/maps/Route101/scripts.pory"
	walk_up
# 202 "data/maps/Route101/scripts.pory"
	step_end
# 203 "data/maps/Route101/scripts.pory"

# 204 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 205 "data/maps/Route101/scripts.pory"
	walk_up
# 206 "data/maps/Route101/scripts.pory"
	walk_left
# 207 "data/maps/Route101/scripts.pory"
	walk_up
# 208 "data/maps/Route101/scripts.pory"
	step_end
# 209 "data/maps/Route101/scripts.pory"

# 210 "data/maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 211 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 212 "data/maps/Route101/scripts.pory"
	end
# 213 "data/maps/Route101/scripts.pory"

# 214 "data/maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 215 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 216 "data/maps/Route101/scripts.pory"
	end
# 217 "data/maps/Route101/scripts.pory"

# 218 "data/maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 219 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 220 "data/maps/Route101/scripts.pory"
	end
# 221 "data/maps/Route101/scripts.pory"

# 222 "data/maps/Route101/scripts.pory"
Route101_EventScript_BirchsBag::
# 223 "data/maps/Route101/scripts.pory"
	lock
# 224 "data/maps/Route101/scripts.pory"
	faceplayer
# 225 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 226 "data/maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 227 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 228 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ZIGZAGOON
# 229 "data/maps/Route101/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
# 230 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 231 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 232 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 233 "data/maps/Route101/scripts.pory"
	waitstate
# 234 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
# 235 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 236 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 237 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 238 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 239 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 240 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 241 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 242 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 243 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 244 "data/maps/Route101/scripts.pory"
	checkplayergender
# 245 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 246 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 247 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 248 "data/maps/Route101/scripts.pory"
	waitstate
# 249 "data/maps/Route101/scripts.pory"
	release
# 250 "data/maps/Route101/scripts.pory"
	end
# 251 "data/maps/Route101/scripts.pory"

# 252 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 253 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 254 "data/maps/Route101/scripts.pory"
	return
# 255 "data/maps/Route101/scripts.pory"

# 256 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 257 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 258 "data/maps/Route101/scripts.pory"
	return
# 259 "data/maps/Route101/scripts.pory"

# 260 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 261 "data/maps/Route101/scripts.pory"
	walk_right
# 262 "data/maps/Route101/scripts.pory"
	step_end
# 263 "data/maps/Route101/scripts.pory"

# 264 "data/maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 265 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"
# 266 "data/maps/Route101/scripts.pory"

# 267 "data/maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 268 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 269 "data/maps/Route101/scripts.pory"
	.string "Please! Help!\p"
# 270 "data/maps/Route101/scripts.pory"
	.string "In my BAG!\n"
# 271 "data/maps/Route101/scripts.pory"
	.string "There's a POKé BALL!$"
# 272 "data/maps/Route101/scripts.pory"

# 273 "data/maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 274 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 275 "data/maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 276 "data/maps/Route101/scripts.pory"

# 277 "data/maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 278 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 279 "data/maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 280 "data/maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 281 "data/maps/Route101/scripts.pory"
	.string "You saved me.\n"
# 282 "data/maps/Route101/scripts.pory"
	.string "Thanks a lot!\p"
# 283 "data/maps/Route101/scripts.pory"
	.string "Oh?\p"
# 284 "data/maps/Route101/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 285 "data/maps/Route101/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 286 "data/maps/Route101/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 287 "data/maps/Route101/scripts.pory"

# 288 "data/maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 289 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 290 "data/maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 291 "data/maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 292 "data/maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 293 "data/maps/Route101/scripts.pory"

# 294 "data/maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 295 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 296 "data/maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 297 "data/maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 298 "data/maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 299 "data/maps/Route101/scripts.pory"

# 300 "data/maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 301 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 302 "data/maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_MapScripts::
# 311 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 312 "data/maps/Route101/scripts.pory"
	switch VAR_CANVAS_TOWN_STATE
# 313 "data/maps/Route101/scripts.pory"
	case 1, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 318 "data/maps/Route101/scripts.pory"
	case 3, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 314 "data/maps/Route101/scripts.pory"
	setobjectxyperm 7, 7, 64
# 315 "data/maps/Route101/scripts.pory"
	setobjectmovementtype 7, MOVEMENT_TYPE_LOOK_AROUND
# 316 "data/maps/Route101/scripts.pory"
	setobjectxyperm 8, 17, 61
# 317 "data/maps/Route101/scripts.pory"
	removeobject 8, MAP_ROUTE101
	return

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 319 "data/maps/Route101/scripts.pory"
	setobjectxyperm 2, 7, 61
	return


CanvasPath_Trigger_SkipCypressEncounter::
# 325 "data/maps/Route101/scripts.pory"
	lockall
# 326 "data/maps/Route101/scripts.pory"
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_RIGHT
# 327 "data/maps/Route101/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 328 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 6
	goto_if_eq CanvasPath_Trigger_SkipCypressEncounter_2
# 332 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 8
	goto_if_eq CanvasPath_Trigger_SkipCypressEncounter_3
CanvasPath_Trigger_SkipCypressEncounter_1:
# 337 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 338 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 339 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 340 "data/maps/Route101/scripts.pory"
	waitse
# 342 "data/maps/Route101/scripts.pory"
	delay 8
# 343 "data/maps/Route101/scripts.pory"
	goto CanvasPath_EventScript_SkipCypressEncounter
	return

CanvasPath_Trigger_SkipCypressEncounter_2:
# 329 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceLeft
# 330 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
# 331 "data/maps/Route101/scripts.pory"
	waitmovement 0
	goto CanvasPath_Trigger_SkipCypressEncounter_1

CanvasPath_Trigger_SkipCypressEncounter_3:
# 333 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceRight
# 334 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 335 "data/maps/Route101/scripts.pory"
	waitmovement 0
	goto CanvasPath_Trigger_SkipCypressEncounter_1


CanvasPath_EventScript_SkipCypressEncounter::
# 346 "data/maps/Route101/scripts.pory"
	lockall
# 347 "data/maps/Route101/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 348 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 7
	goto_if_eq CanvasPath_EventScript_SkipCypressEncounter_2
CanvasPath_EventScript_SkipCypressEncounter_1:
# 351 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_0, MSGBOX_AUTOCLOSE
# 352 "data/maps/Route101/scripts.pory"
	applymovement 7, CanvasPath_Movement_SkipCypressEncounter_0
# 353 "data/maps/Route101/scripts.pory"
	delay 10
# 354 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 6
	goto_if_eq CanvasPath_EventScript_SkipCypressEncounter_5
# 357 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 8
	goto_if_eq CanvasPath_EventScript_SkipCypressEncounter_6
# 361 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_0, 7
	goto_if_eq CanvasPath_EventScript_SkipCypressEncounter_7
CanvasPath_EventScript_SkipCypressEncounter_4:
# 365 "data/maps/Route101/scripts.pory"
	clearflag FLAG_CANVAS_TOWN_SKIP
# 366 "data/maps/Route101/scripts.pory"
	addobject 8, MAP_ROUTE101
# 367 "data/maps/Route101/scripts.pory"
	setobjectxyperm 8, 17, 61
# 368 "data/maps/Route101/scripts.pory"
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_RIGHT
# 369 "data/maps/Route101/scripts.pory"
	delay 8
# 370 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_WalkInPlaceRight
# 371 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 372 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_1
# 373 "data/maps/Route101/scripts.pory"
	delay 12
# 374 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_2, MSGBOX_AUTOCLOSE
# 375 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 376 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 377 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 378 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 379 "data/maps/Route101/scripts.pory"
	waitse
# 380 "data/maps/Route101/scripts.pory"
	playbgm MUS_RG_OAK, FALSE
# 382 "data/maps/Route101/scripts.pory"
	applymovement 8, CanvasPath_Movement_SkipCypressEncounter_1
# 383 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 384 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_3
# 385 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_4
# 386 "data/maps/Route101/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceDown
# 387 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 388 "data/maps/Route101/scripts.pory"
	delay 12
# 389 "data/maps/Route101/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceLeft
# 390 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 391 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_5, MSGBOX_DEFAULT
# 392 "data/maps/Route101/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 393 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 394 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 395 "data/maps/Route101/scripts.pory"
	waitse
# 396 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_6, MSGBOX_DEFAULT
# 397 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_7, MSGBOX_DEFAULT
# 398 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 399 "data/maps/Route101/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceRight
# 400 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 401 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_8, MSGBOX_DEFAULT
# 402 "data/maps/Route101/scripts.pory"
	delay 10
# 403 "data/maps/Route101/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceLeft
# 404 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 405 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_9, MSGBOX_YESNO
CanvasPath_EventScript_SkipCypressEncounter_12:
# 406 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_ne CanvasPath_EventScript_SkipCypressEncounter_13
# 409 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_11, MSGBOX_DEFAULT
# 410 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_12
# 411 "data/maps/Route101/scripts.pory"
	closemessage
# 412 "data/maps/Route101/scripts.pory"
	applymovement 8, CanvasPath_Movement_SkipCypressEncounter_2
# 413 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 414 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_13, MSGBOX_AUTOCLOSE
# 416 "data/maps/Route101/scripts.pory"
	setflag FLAG_CANVAS_TOWN_SKIP
# 417 "data/maps/Route101/scripts.pory"
	addvar VAR_CANVAS_TOWN_STATE, 1
# 418 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 5, 6
# 419 "data/maps/Route101/scripts.pory"
	releaseall
	end

CanvasPath_EventScript_SkipCypressEncounter_2:
# 349 "data/maps/Route101/scripts.pory"
	faceplayer
	goto CanvasPath_EventScript_SkipCypressEncounter_1

CanvasPath_EventScript_SkipCypressEncounter_5:
# 355 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CanvasPath_Movement_SkipCypressEncounter_p1
# 356 "data/maps/Route101/scripts.pory"
	waitmovement 0
	goto CanvasPath_EventScript_SkipCypressEncounter_4

CanvasPath_EventScript_SkipCypressEncounter_6:
# 358 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CanvasPath_Movement_SkipCypressEncounter_p0
# 359 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 360 "data/maps/Route101/scripts.pory"
	delay 8
	goto CanvasPath_EventScript_SkipCypressEncounter_4

CanvasPath_EventScript_SkipCypressEncounter_7:
# 362 "data/maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CanvasPath_Movement_SkipCypressEncounter_p2
# 363 "data/maps/Route101/scripts.pory"
	waitmovement 0
	goto CanvasPath_EventScript_SkipCypressEncounter_4

CanvasPath_EventScript_SkipCypressEncounter_13:
# 407 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_EventScript_SkipCypressEncounter_Text_10, MSGBOX_YESNO
	goto CanvasPath_EventScript_SkipCypressEncounter_12


# 423 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_0:
# 424 "data/maps/Route101/scripts.pory"
	walk_up
# 424 "data/maps/Route101/scripts.pory"
	walk_up
# 424 "data/maps/Route101/scripts.pory"
	walk_up
# 425 "data/maps/Route101/scripts.pory"
	walk_right
# 425 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

# 427 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_p0:
# 428 "data/maps/Route101/scripts.pory"
	walk_up
# 428 "data/maps/Route101/scripts.pory"
	walk_up
# 429 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

# 431 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_p2:
# 432 "data/maps/Route101/scripts.pory"
	walk_up
# 432 "data/maps/Route101/scripts.pory"
	walk_up
# 432 "data/maps/Route101/scripts.pory"
	walk_up
# 433 "data/maps/Route101/scripts.pory"
	walk_right
# 433 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

# 435 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_p1:
# 436 "data/maps/Route101/scripts.pory"
	walk_up
# 436 "data/maps/Route101/scripts.pory"
	walk_up
# 437 "data/maps/Route101/scripts.pory"
	walk_right
# 437 "data/maps/Route101/scripts.pory"
	walk_right
# 437 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

# 439 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_1:
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
# 440 "data/maps/Route101/scripts.pory"
	walk_left
	step_end

# 442 "data/maps/Route101/scripts.pory"
CanvasPath_Movement_SkipCypressEncounter_2:
# 443 "data/maps/Route101/scripts.pory"
	walk_in_place_up
# 444 "data/maps/Route101/scripts.pory"
	delay_8
# 445 "data/maps/Route101/scripts.pory"
	walk_in_place_right
# 446 "data/maps/Route101/scripts.pory"
	delay_8
# 447 "data/maps/Route101/scripts.pory"
	walk_in_place_left
# 448 "data/maps/Route101/scripts.pory"
	delay_8
	step_end

CanvasPath_Sign_RouteSign_1::
# 453 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Sign_RouteSign_1_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


CanvasPath_Sign_RouteSign_2::
# 457 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Sign_RouteSign_2_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


CanvasPath_Object_MartEmployee::
# 461 "data/maps/Route101/scripts.pory"
	lock
# 462 "data/maps/Route101/scripts.pory"
	faceplayer
# 463 "data/maps/Route101/scripts.pory"
	goto_if_unset FLAG_CANVAS_PATH_MART_EMPLOYEE, CanvasPath_Object_MartEmployee_2
# 468 "data/maps/Route101/scripts.pory"
	faceplayer
# 469 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Object_MartEmployee_Text_1, MSGBOX_AUTOCLOSE
CanvasPath_Object_MartEmployee_1:
# 471 "data/maps/Route101/scripts.pory"
	releaseall
	end

CanvasPath_Object_MartEmployee_2:
# 464 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Object_MartEmployee_Text_0
# 465 "data/maps/Route101/scripts.pory"
	giveitem ITEM_POTION, 1
# 466 "data/maps/Route101/scripts.pory"
	setflag FLAG_CANVAS_PATH_MART_EMPLOYEE
	goto CanvasPath_Object_MartEmployee_1


CanvasPath_Object_OldWoman::
# 475 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Object_OldWoman_Text_0, MSGBOX_NPC
	end


CanvasPath_Object_Fisherman::
# 479 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Object_Fisherman_Text_0, MSGBOX_NPC
	end


CanvasPath_ItemBall_FullHeal::
# 483 "data/maps/Route101/scripts.pory"
	finditem ITEM_FULL_HEAL
	end


CanvasPath_Trainer_Youngster::
# 489 "data/maps/Route101/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_CODY, CanvasPath_Trainer_Youngster_Text_0, CanvasPath_Trainer_Youngster_Text_1
# 490 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Trainer_Youngster_Text_2, MSGBOX_NPC
	end


CanvasPath_Trainer_BugCatcher::
# 494 "data/maps/Route101/scripts.pory"
	trainerbattle_single TRAINER_BUGCATCHER_ISAIAH, CanvasPath_Trainer_BugCatcher_Text_0, CanvasPath_Trainer_BugCatcher_Text_1
# 495 "data/maps/Route101/scripts.pory"
	msgbox CanvasPath_Trainer_BugCatcher_Text_2, MSGBOX_NPC
	end


CanvasPath_EventScript_SkipCypressEncounter_Text_0:
# 351 "data/maps/Route101/scripts.pory"
	.string "Skip: {COLOR BLUE}Took ya long enough!\p"
	.string "Okay{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.\n"
	.string "It's time.\p"
	.string "Come on {PLAYER}, watch me catch my\n"
	.string "first Pokémon!$"

CanvasPath_EventScript_SkipCypressEncounter_Text_1:
# 372 "data/maps/Route101/scripts.pory"
	.string "Skip: {COLOR BLUE}Alright, all I have to do is walk\n"
	.string "into the grass...$"

CanvasPath_EventScript_SkipCypressEncounter_Text_2:
# 374 "data/maps/Route101/scripts.pory"
	.string "???: {COLOR RED}Stop right there!$"

CanvasPath_EventScript_SkipCypressEncounter_Text_3:
# 384 "data/maps/Route101/scripts.pory"
	.string "???: {COLOR RED}What do you two think you're\n"
	.string "doing?$"

CanvasPath_EventScript_SkipCypressEncounter_Text_4:
# 385 "data/maps/Route101/scripts.pory"
	.string "Skip: {COLOR BLUE}P{PAUSE 5}-{PAUSE 10}Professor Cypress!$"

CanvasPath_EventScript_SkipCypressEncounter_Text_5:
# 391 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}You two don't seem to have a\n"
	.string "Pokèmon between you.\p"
	.string "What's the meaning of going into the\n"
	.string "tall grass!\p"
	.string "It worries me what people like that\n"
	.string "would do to Pokèmon...$"

CanvasPath_EventScript_SkipCypressEncounter_Text_6:
# 396 "data/maps/Route101/scripts.pory"
	.string "Skip: {COLOR BLUE}No!{PAUSE 16}\n"
	.string "{PLAYER} had nothing to do with\l"
	.string "running into the tall grass.\p"
	.string "It was my idea{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.{PAUSE 10}$"

CanvasPath_EventScript_SkipCypressEncounter_Text_7:
# 397 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}Hm.{PAUSE 12}\n"
	.string "I can't knock your honesty.$"

CanvasPath_EventScript_SkipCypressEncounter_Text_8:
# 401 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}{FONT_SMALL}... They tried to go in the tall\n"
	.string "grass because they wanted Pokèmon...\p"
	.string "Hmm... What to do...?\p"
	.string "Is it wise to set them on this path?$"

CanvasPath_EventScript_SkipCypressEncounter_Text_9:
# 405 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}You two.\n"
	.string "Do you truly love Pokèmon?$"

CanvasPath_EventScript_SkipCypressEncounter_Text_10:
# 407 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}...{PAUSE 12}\n"
	.string "Sorry, I don't think I quiet heard that.\p"
	.string "You two.\n"
	.string "Do you truly love Pokèmon?$"

CanvasPath_EventScript_SkipCypressEncounter_Text_11:
# 409 "data/maps/Route101/scripts.pory"
	.string "Skip: {COLOR BLUE}Yes!\n"
	.string "A thousand times yes!\p"
	.string "Our answer will never change.$"

CanvasPath_EventScript_SkipCypressEncounter_Text_12:
# 410 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}Very well then!\p"
	.string "I will entrust you two with your very\n"
	.string "own Pokèmon.$"

CanvasPath_EventScript_SkipCypressEncounter_Text_13:
# 414 "data/maps/Route101/scripts.pory"
	.string "Cypress: {COLOR RED}How about we bring this\n"
	.string "somewhere safer?$"

CanvasPath_Sign_RouteSign_1_Text_0:
# 453 "data/maps/Route101/scripts.pory"
	.string "{COLOR LIGHT_GREEN}Canvas Path\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} Rossano Town\n"
	.string "{DOWN_ARROW} Canvas Town$"

CanvasPath_Sign_RouteSign_2_Text_0:
# 457 "data/maps/Route101/scripts.pory"
	.string "{COLOR LIGHT_GREEN}Canvas Path\p"
	.string "{COLOR DARK_GREY}{LEFT_ARROW} Rossano Town\n"
	.string "{DOWN_ARROW} Canvas Town$"

CanvasPath_Object_MartEmployee_Text_0:
# 464 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}Hey there trainer!\p"
	.string "Every good trainer needs to heal up\n"
	.string "once in a while.\p"
	.string "Please visit the PokéCenter in {COLOR GREEN}Rossano\n"
	.string "Town{COLOR BLUE} for all your medicine needs!\p"
	.string "Here, try a sample!$"

CanvasPath_Object_MartEmployee_Text_1:
# 469 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}Every good trainer needs to heal up\n"
	.string "once in a while.\p"
	.string "Potions and other medicines are readily\n"
	.string "available for purchase at your local\l"
	.string "PokéCenter$"

CanvasPath_Object_OldWoman_Text_0:
# 475 "data/maps/Route101/scripts.pory"
	.string "{COLOR RED}I use to be a Pokémon Trainer back in my\n"
	.string "day.\p"
	.string "Now I enjoy sitting here watching young\n"
	.string "trainers battle.$"

CanvasPath_Object_Fisherman_Text_0:
# 479 "data/maps/Route101/scripts.pory"
	.string "{COLOR RED}I've seen many other oceans and seas\n"
	.string "all around the world, but byfar this is\l"
	.string "the bluest!$"

CanvasPath_Trainer_Youngster_Text_0:
# 489 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}Is this your first Pokémon battle?$"

CanvasPath_Trainer_Youngster_Text_1:
# 489 "data/maps/Route101/scripts.pory"
	.string "Wow!$"

CanvasPath_Trainer_Youngster_Text_2:
# 490 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}When you make eye contact with a\n"
	.string "Pokémon Trainer, you're in for a battle!$"

CanvasPath_Trainer_BugCatcher_Text_0:
# 494 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}Bugs!\n"
	.string "I love bugs!$"

CanvasPath_Trainer_BugCatcher_Text_1:
# 494 "data/maps/Route101/scripts.pory"
	.string "No!\n"
	.string "My bugs!$"

CanvasPath_Trainer_BugCatcher_Text_2:
# 495 "data/maps/Route101/scripts.pory"
	.string "{COLOR BLUE}Ryoko has plenty of bugs, especially\n"
	.string "butterfly-like Pokémon!$"
