# 1 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_MapScripts:: @ 81F9296
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnTransition: @ 81F92A1
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@    call_if_set FLAG_CANVASTOWN_RIVALBATTLE, SkipsHouse_Mapscript_Locations
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_lt LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_ge LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 4
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos:: @ 81F92CD
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos:: @ 81F92E6
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_Ret
# 29 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret
# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm 1, 8, 2
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Ret:: @ 81F9309
# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay:: @ 81F930A
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay:: @ 81F9317
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnWarp: @ 81F931D
# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.2byte 0
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor:: @ 81F9327
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq SecretBase_EventScript_InitDecorations
# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall:: @ 81F9334
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMay
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMay:: @ 81F934A
# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	addobject 1
# 69 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayEnters
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PIN
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, 1
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 81 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 87 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadedefaultbgm
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth:: @ 81F93BA
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth:: @ 81F93E9
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 114 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest:: @ 81F9418
# 120 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 123 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast:: @ 81F9440
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
# 132 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 134 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 135 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
# 139 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 142 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayEnters: @ 81F946F
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 145 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 148 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth: @ 81F9473
# 149 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth: @ 81F9479
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 161 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 164 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 165 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 167 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth: @ 81F9483
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 170 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 173 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 176 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 177 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 178 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth: @ 81F948B
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 180 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth: @ 81F948F
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 189 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 191 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 192 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 193 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 194 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth: @ 81F9497
# 195 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 197 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 198 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest: @ 81F949D
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 204 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 207 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 210 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest: @ 81F94A4
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 216 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 217 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 218 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest: @ 81F94A9
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 221 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 224 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast: @ 81F94AD
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 227 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 231 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 232 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast: @ 81F94B2
# 233 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 234 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 235 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 236 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 239 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 242 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast: @ 81F94BB
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 245 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 248 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_faster_right
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 250 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 251 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Rival:: @ 81F94C1
# 252 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 253 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
# 254 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 256 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq RivalsHouse_2F_EventScript_May
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq RivalsHouse_2F_EventScript_Brendan
# 259 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_May:: @ 81F94E3
# 262 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 265 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Brendan:: @ 81F94ED
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
# 268 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_RivalPostLilycove:: @ 81F94F7
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq RivalsHouse_2F_EventScript_MayPostLilycove
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq RivalsHouse_2F_EventScript_BrendanPostLilycove
# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayPostLilycove:: @ 81F951D
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanPostLilycove:: @ 81F952F
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayWhereShouldIGoNext:: @ 81F9541
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext:: @ 81F954A
# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_PC:: @ 81F9553
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 310 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC:: @ 81F956C
# 311 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 312 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 313 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 314 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 315 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC:: @ 81F9576
# 316 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, 2
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 318 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 321 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 324 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F958F
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, 2
# 327 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 328 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 329 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 330 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 331 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 332 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhoAreYou: @ 81F959C
# 333 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh?\n"
# 334 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who… Who are you?\p"
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\n"
# 336 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\p"
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So your move was today.\p"
# 339 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Um… I'm MAY.\n"
# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Glad to meet you!\p"
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I…\n"
# 342 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "with POKéMON all over the world.\p"
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 345 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "my dad, PROF. BIRCH.\p"
# 346 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 347 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 348 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 349 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eheheh…\p"
# 351 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 352 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON!\p"
# 354 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 355 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 356 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayGettingReady: @ 81F978A
# 357 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored!\n"
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items ready, and…$"
# 359 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhoAreYou: @ 81F97B4
# 361 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey!\n"
# 362 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You…\p"
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who are you?\p"
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Moved in next door, right?\p"
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Dad, PROF. BIRCH, said that our new\n"
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "next-door neighbor is a GYM LEADER's\l"
# 369 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "My name's BRENDAN.\n"
# 371 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 372 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 373 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "a POKéMON?\p"
# 374 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 375 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 376 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild POKéMON.\p"
# 378 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Some other time, okay?$"
# 379 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 380 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanGettingReady: @ 81F9962
# 381 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "POKéMON fully restored…\n"
# 382 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items all packed, and…$"
# 383 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 384 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_ItsRivalsPokeBall: @ 81F9991
# 385 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's {RIVAL}'s POKé BALL!\p"
# 386 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Better leave it right where it is.$"
# 387 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 388 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayJustCheckingMyPokedex: @ 81F99C9
# 389 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 390 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking my POKéDEX.\p"
# 391 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's still a lot of POKéMON that\n"
# 392 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I've seen but haven't caught.\p"
# 393 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "And there are many others that\n"
# 394 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I think will evolve.\p"
# 395 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I wonder where I should go catch\n"
# 396 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?$"
# 397 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 398 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhereShouldIGoNext: @ 81F9A9E
# 399 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
# 400 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some POKéMON next?\p"
# 401 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wouldn't it be funny if we ran into each\n"
# 402 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "other, {PLAYER}{KUN}?$"
# 403 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 404 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex: @ 81F9B0D
# 405 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
# 406 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking out my POKéDEX.\p"
# 407 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There are still many POKéMON that\n"
# 408 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I need to catch, I know, but this\l"
# 409 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "is looking pretty good.\p"
# 410 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Checking this POKéDEX out gives me\n"
# 411 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "the urge to hit the road again.$"
# 412 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 413 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhereShouldIGoNext: @ 81F9BE7
# 414 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
# 415 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "where I should catch POKéMON next.\p"
# 416 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
# 417 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "catching POKéMON, I can pitch you a\l"
# 418 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "battle if you'd like.$"
