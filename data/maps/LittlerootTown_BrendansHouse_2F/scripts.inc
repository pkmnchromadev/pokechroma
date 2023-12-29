# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayersHouse_Mapscript2_Init
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition: @ 81F83EE
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_lt LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_ge LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 4
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos:: @ 81F841A
# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos:: @ 81F8433
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret  @ Odd that the MaysHouse equivalent was used here instead
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm 1, 0, 2
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret:: @ 81F8456
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan:: @ 81F8457
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan:: @ 81F8464
# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp: @ 81F846A
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor:: @ 81F8474
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq SecretBase_EventScript_InitDecorations
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall:: @ 81F8481
# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan:: @ 81F8497
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	addobject 1
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, 1
# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth:: @ 81F8507
# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 102 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 103 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 104 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 105 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth:: @ 81F8536
# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest:: @ 81F8565
# 120 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 121 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 125 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 126 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 127 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 128 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 129 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 130 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 131 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast:: @ 81F8594
# 132 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 133 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 134 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 135 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 136 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 137 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 138 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 139 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 141 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 142 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters: @ 81F85BC
# 143 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 144 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 145 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 146 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 147 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 148 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth: @ 81F85C0
# 149 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 150 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 151 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 152 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 153 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 154 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 155 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 156 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth: @ 81F85C6
# 157 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 158 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 159 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 160 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 161 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 162 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 163 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 164 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 165 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 166 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 167 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth: @ 81F85CF
# 168 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 169 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 170 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 171 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 172 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 173 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 174 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 175 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 176 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 177 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth: @ 81F85D7
# 178 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 179 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 180 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 181 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 182 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 183 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth: @ 81F85DB
# 184 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 186 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 187 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 188 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 189 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 190 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 191 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 192 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth: @ 81F85E2
# 193 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 194 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 195 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 196 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 197 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 198 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 199 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 200 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest: @ 81F85E8
# 201 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 202 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 203 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 204 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 205 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 206 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 207 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest: @ 81F85ED
# 208 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 209 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 210 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 211 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 212 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 213 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 214 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 215 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 216 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 217 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 218 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest: @ 81F85F6
# 219 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 220 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 221 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 222 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 223 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 224 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 225 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 226 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 227 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast: @ 81F85FD
# 228 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 229 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 230 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 231 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 232 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 233 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 234 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 235 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 236 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast: @ 81F8604
# 237 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 238 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 239 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 240 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 241 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 242 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 243 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 244 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast: @ 81F8609
# 245 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 246 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 247 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 248 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 249 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 250 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC:: @ 81F860D
# 251 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 252 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 253 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 254 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 255 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 256 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 257 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 258 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 259 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC:: @ 81F8626
# 260 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 261 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 262 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 263 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 264 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 265 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 266 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 267 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 268 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 269 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
# 270 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 271 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 272 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 273 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 274 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 275 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 276 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC:: @ 81F864C
# 277 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 278 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 279 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 280 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 281 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook:: @ 81F8656
# 282 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 283 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 284 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 285 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube:: @ 81F865F
# 286 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 287 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 288 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 289 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped: @ 81F8668
# 290 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 291 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 292 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 293 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom: @ 81F869A
# 294 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 295 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 296 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 297 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 298 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 299 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 300 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 301 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 302 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 303 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook: @ 81F877F
# 304 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 305 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 306 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 307 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 308 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 311 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap: @ 81F8820
# 312 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 313 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "HOENN region map.$"
# 314 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 315 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube: @ 81F884F
# 316 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 317 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 318 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

# 320 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 321 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_Mapscript2_Init::
# 322 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_PLAYERSHOUSE_STATE, 0, PlayersHouse_Mapscript_DadEnterRoom
# 323 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0

PlayersHouse_Mapscript_DadEnterRoom::
# 329 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_PLAYERSHOUSE_STATE, 0
	goto_if_eq PlayersHouse_Mapscript_DadEnterRoom_1
	return

PlayersHouse_Mapscript_DadEnterRoom_1:
# 330 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 331 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 40
# 332 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxy 1, 7, 3
# 333 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_EXIT
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, PlayersHouse_Movement_DadEnterRoom_0
# 335 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 336 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 337 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 338 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_Mapscript_DadEnterRoom_Text_0, MSGBOX_AUTOCLOSE
# 339 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 340 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 341 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement 1, PlayersHouse_Movement_DadEnterRoom_1
# 342 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 343 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_EXIT
# 344 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 1
# 345 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_PLAYERSHOUSE_STATE, 1
# 346 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_PLAYERSHOUSE_DAD_STATE
# 347 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 348 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 349 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end


# 354 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_Movement_DadEnterRoom_0:
# 355 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_slow_right
# 356 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_left
# 358 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 359 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	emote_exclamation_mark
	step_end

# 361 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_Movement_DadEnterRoom_1:
# 362 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_slow_left
	step_end

PlayersHouse_Mapscript_DadEnterRoom_Text_0:
# 338 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Dad: {COLOR GREEN}{PLAYER}{COLOR BLUE}!\n"
	.string "You're gonna be late!\p"
	.string "{COLOR DARK_GRAY}Dad: {COLOR GREEN}Professor Cypress{COLOR BLUE} is visiting town\n"
	.string "and is looking for a new Trainer to be\l"
	.string "her assistant!\p"
	.string "{COLOR DARK_GRAY}Dad: {COLOR BLUE}Now, get ready and let your friend\n"
	.string "{COLOR GREEN}Skip{COLOR BLUE} know about it too.\p"
	.string "Don't be late!$"
