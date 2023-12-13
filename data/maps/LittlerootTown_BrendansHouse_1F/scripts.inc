# 1 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
# 3 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
# 4 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
# 5 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayersHouse_1F_Mapscript2_Init
# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
# 7 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.byte 0
# 8 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
# 12 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
# 13 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 14 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
# 18 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 19 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 20 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
# 21 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	checkplayergender
# 22 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, MALE
# 23 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
# 24 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 25 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 26 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
# 27 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
# 28 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 29 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 30 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
# 33 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 5
# 34 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
# 35 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 36 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
# 37 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 39 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 8, 4
# 41 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 42 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 4, 5
# 46 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 47 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 48 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 49 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
# 50 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 9, 8
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 54 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 55 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
# 56 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
# 57 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
# 58 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
# 59 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
# 60 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
# 61 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 62 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.2byte 0
# 63 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 64 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
# 65 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 66 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 67 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 68 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 69 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 70 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 71 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
# 72 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 73 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 74 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 75 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 76 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
# 77 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 78 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 79 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 80 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
# 81 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 82 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 83 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 84 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 85 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 87 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
# 88 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 89 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, 0
# 90 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1  @ Object event ID for Mom
# 91 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
# 92 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 93 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 94 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
# 95 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 96 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 97 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 98 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 100 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 101 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 102 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
# 103 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 104 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 105 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 106 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 107 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
# 108 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 109 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 110 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 111 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
# 112 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 113 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 114 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 115 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 116 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 117 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 118 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 119 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 120 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
# 121 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 122 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 123 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 124 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 125 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 126 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 127 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 128 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 129 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
# 130 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 131 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 132 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 133 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 134 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 135 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
# 136 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 137 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 138 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 139 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 140 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 141 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
# 142 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 143 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 144 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 145 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 146 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 147 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
# 148 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 149 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 150 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	addobject 7
# 151 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 152 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 153 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 154 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 155 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, Common_Movement_Delay48
# 156 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 157 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 158 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
# 159 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, 1
# 160 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 161 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
# 162 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 163 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
# 164 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 165 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
# 166 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 167 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 168 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
# 170 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 171 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
# 172 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 173 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
# 174 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 175 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	removeobject 7
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
# 177 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 178 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 179 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 181 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 182 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 183 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadedefaultbgm
# 184 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 185 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 186 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
# 188 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 189 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 190 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 191 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 192 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
# 193 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
# 194 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 195 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 196 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 197 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
# 198 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
# 199 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 200 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 201 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 202 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
# 203 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
# 204 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 205 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 206 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 207 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
# 208 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 209 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 210 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 211 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 212 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 214 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 215 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 216 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 217 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
# 218 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 219 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 220 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 221 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 222 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 223 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
# 224 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 225 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 226 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 227 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 228 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 229 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 230 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 231 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 232 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 233 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
# 234 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
# 235 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
# 236 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 237 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 238 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 239 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
# 240 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
# 241 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
# 242 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 243 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 244 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 245 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
# 246 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
# 247 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
# 248 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 249 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 250 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 251 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
# 252 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 253 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 254 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 255 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 256 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 257 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
# 258 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 259 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 260 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 261 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 262 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 263 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 264 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 265 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 266 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
# 267 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 268 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 269 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 270 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 271 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 272 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
# 273 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 274 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 275 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 276 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 277 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 278 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 279 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 280 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
# 281 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 282 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 283 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 284 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 285 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 286 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 287 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 288 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 289 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 290 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 291 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 292 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
# 293 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 294 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 295 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 296 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 297 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 298 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 299 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 300 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
# 301 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See, {PLAYER}?\n"
# 302 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Isn't it nice in here, too?$"
# 303 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 304 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
# 305 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The mover's POKéMON do all the work\n"
# 306 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "of moving us in and cleaning up after.\l"
# 307 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This is so convenient!\p"
# 308 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "{PLAYER}, your room is upstairs.\n"
# 309 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go check it out, dear!\p"
# 310 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD bought you a new clock to mark\n"
# 311 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "our move here.\l"
# 312 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't forget to set it!$"
# 313 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 314 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
# 315 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, {PLAYER}?\p"
# 316 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Aren't you interested in seeing your\n"
# 317 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "very own room?$"
# 318 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 319 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
# 320 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}.\p"
# 321 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go set the clock in your room, honey.$"
# 322 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 323 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
# 324 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
# 325 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Quick! Come quickly!$"
# 326 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 327 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
# 328 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Look! It's PETALBURG GYM!\n"
# 329 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Maybe DAD will be on!$"
# 330 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 331 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
# 332 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh… It's over.\p"
# 333 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think DAD was on, but we missed him.\n"
# 334 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Too bad.$"
# 335 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 336 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
# 337 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes.\n"
# 338 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "One of DAD's friends lives in town.\p"
# 339 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH is his name.\p"
# 340 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He lives right next door, so you should\n"
# 341 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "go over and introduce yourself.$"
# 342 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 343 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
# 344 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See you, honey!$"
# 345 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 346 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
# 347 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Did you introduce yourself to\n"
# 348 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH?$"
# 349 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 350 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
# 351 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: How are you doing, {PLAYER}?\n"
# 352 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You look a little tired.\p"
# 353 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think you should rest a bit.$"
# 354 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 355 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
# 356 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Take care, honey!$"
# 357 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 358 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
# 359 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
# 360 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Then here's something from your MOM!$"
# 361 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 362 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
# 363 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't push yourself too hard, dear.\n"
# 364 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You can always come home.\p"
# 365 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go for it, honey!$"
# 366 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 367 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
# 368 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: What is that, honey? A POKéNAV?\n"
# 369 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Someone from DEVON gave it to you?\p"
# 370 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Well, honey, how about registering\n"
# 371 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "your mom?\p"
# 372 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "… … …$"
# 373 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 374 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
# 375 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered MOM\n"
# 376 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "in the POKéNAV.$"
# 377 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 378 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
# 379 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Fugiiiiih!$"
# 380 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 381 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
# 382 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Huggoh, uggo uggo…$"
# 383 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 384 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
# 385 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "INTERVIEWER: …We brought you this\n"
# 386 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "report from in front of PETALBURG GYM.$"
# 387 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 388 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
# 389 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There is a movie on TV.\p"
# 390 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Two men are dancing on a big piano\n"
# 391 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "keyboard.\p"
# 392 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Better get going!$"
# 393 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 394 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
# 395 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's the instruction booklet for the\n"
# 396 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "RUNNING SHOES.\p"
# 397 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Press the B Button to run while\n"
# 398 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "wearing your RUNNING SHOES.\p"
# 399 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Lace up your RUNNING SHOES and hit\n"
# 400 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "the road running!”$"
# 401 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 402 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
# 403 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm?\p"
# 404 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 405 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's been a while since I saw you,\n"
# 406 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "but you look…stronger, somehow.\p"
# 407 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "That's the impression I get.\n"
# 408 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "But your old man hasn't given up yet!\p"
# 409 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes, I have something for you.\n"
# 410 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This came to you from someone named\l"
# 411 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MR. BRINEY.$"
# 412 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 413 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
# 414 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm, a TICKET for a ferry?\p"
# 415 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "If I recall, there are ferry ports in\n"
# 416 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "SLATEPORT and LILYCOVE.$"
# 417 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 418 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
# 419 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I'd better get back to PETALBURG GYM.\p"
# 420 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM, thanks for looking after the house\n"
# 421 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while I'm away.$"
# 422 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 423 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
# 424 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: That DAD of yours…\p"
# 425 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He comes home for the first time in a\n"
# 426 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while, but all he talks about is POKéMON.\p"
# 427 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He should relax and stay a little longer.$"
# 428 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 429 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
# 430 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Is that a breaking news story?$"
# 431 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 432 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
# 433 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We bring you this emergency\n"
# 434 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "news flash!\p"
# 435 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "In various HOENN locales, there have\n"
# 436 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "been reports of a BZZT…colored\l"
# 437 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "POKéMON in flight.\p"
# 438 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The identity of this POKéMON is\n"
# 439 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "currently unknown.\p"
# 440 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We now return you to the regular\n"
# 441 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "movie program.$"
# 442 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 443 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
# 444 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}, did you catch that?\p"
# 445 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "What color did the announcer say\n"
# 446 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "that POKéMON was?$"
# 447 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 448 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
# 449 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, isn't that something!\n"
# 450 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There are still unknown POKéMON.$"

PlayersHouse_trg_DadBeforeExit::
# 458 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 459 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceRight
# 460 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 461 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 462 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 463 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_trg_DadBeforeExit_Text_0, MSGBOX_AUTOCLOSE
# 464 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 465 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_TEMP_1, 7
	goto_if_eq PlayersHouse_trg_DadBeforeExit_2
# 468 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_TEMP_1, 8
	goto_if_eq PlayersHouse_trg_DadBeforeExit_3
# 471 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_TEMP_1, 9
	goto_if_eq PlayersHouse_trg_DadBeforeExit_4
PlayersHouse_trg_DadBeforeExit_1:
# 475 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceDown
# 476 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 477 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_es_DadBeforeExit
	return

PlayersHouse_trg_DadBeforeExit_2:
# 466 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_Movement_0
# 467 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
	goto PlayersHouse_trg_DadBeforeExit_1

PlayersHouse_trg_DadBeforeExit_3:
# 469 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_Movement_1
# 470 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
	goto PlayersHouse_trg_DadBeforeExit_1

PlayersHouse_trg_DadBeforeExit_4:
# 472 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_Movement_2
# 473 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
	goto PlayersHouse_trg_DadBeforeExit_1


PlayersHouse_es_DadBeforeExit::
# 480 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 481 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	faceplayer
# 482 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_PLAYERSHOUSE_STATE, 1
	goto_if_eq PlayersHouse_es_DadBeforeExit_1
# 494 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_PLAYERSHOUSE_STATE, 2
	goto_if_eq PlayersHouse_es_DadBeforeExit_2
# 499 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_4, MSGBOX_DEFAULT
# 500 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 5
# 501 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 502 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 503 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playfanfare MUS_HEAL
# 504 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitfanfare
# 505 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special HealPlayerParty
# 506 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_5, MSGBOX_AUTOCLOSE
# 507 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	end

PlayersHouse_es_DadBeforeExit_1:
# 483 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_0
# 484 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmessage
# 485 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 486 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_1
# 487 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_SYS_POKENAV_GET
# 488 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_RECEIVED_POKENAV
# 489 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 490 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitfanfare
# 491 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_2, MSGBOX_AUTOCLOSE
# 492 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial
	end

PlayersHouse_es_DadBeforeExit_2:
# 495 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_Text_3, MSGBOX_AUTOCLOSE
# 496 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	end


PlayersHouse_es_DadBeforeExit_PokegearTutorial::
# 512 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 513 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 514 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_RESULT
# 515 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 0, PlayersHouse_es_DadBeforeExit_PokegearTutorial_3
# 517 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 1, PlayersHouse_es_DadBeforeExit_PokegearTutorial_4
# 519 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 2, PlayersHouse_es_DadBeforeExit_PokegearTutorial_5
# 521 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 4, PlayersHouse_es_DadBeforeExit_PokegearTutorial_6
# 523 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 5, PlayersHouse_es_DadBeforeExit_PokegearTutorial_7
# 525 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 6, PlayersHouse_es_DadBeforeExit_PokegearTutorial_8
# 527 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 7, PlayersHouse_es_DadBeforeExit_PokegearTutorial_9
# 529 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case MULTI_B_PRESSED, PlayersHouse_es_DadBeforeExit_PokegearTutorial_10
PlayersHouse_es_DadBeforeExit_PokegearTutorial_1:
# 532 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special OpenPokenavForTutorial
# 533 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 534 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceDown
# 535 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_0, MSGBOX_AUTOCLOSE
# 537 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 20
# 538 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 539 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_1, MSGBOX_DEFAULT
# 540 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitfanfare
# 541 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 542 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_2, MSGBOX_AUTOCLOSE
# 543 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceLeft
# 544 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 545 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_PLAYERSHOUSE_STATE, 2
# 546 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	end

PlayersHouse_es_DadBeforeExit_PokegearTutorial_3:
# 516 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_4:
# 518 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_5:
# 520 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_6:
# 522 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_7:
# 524 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_8:
# 526 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_9:
# 528 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1

PlayersHouse_es_DadBeforeExit_PokegearTutorial_10:
# 530 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial_1


PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear::
# 550 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceDown
# 551 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 552 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear_Text_0, MSGBOX_DEFAULT
# 553 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 554 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 15
# 555 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_es_DadBeforeExit_PokegearTutorial
	return


# 558 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_Movement_0:
# 559 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 560 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 560 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 561 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_up
	step_end

# 564 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_Movement_1:
# 565 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 565 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 566 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_up
	step_end

# 568 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_Movement_2:
# 569 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 570 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 570 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 571 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_up
	step_end

PlayersHouse_trg_DadBeforeExit_Text_0:
# 463 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Wait {PLAYER}!\n"
	.string "I have a gift for you!$"

PlayersHouse_es_DadBeforeExit_Text_0:
# 483 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Wow... you've grown up so fast!\p"
	.string "Now that you're leaving home, I'd like\n"
	.string "you to take this.$"

PlayersHouse_es_DadBeforeExit_Text_1:
# 486 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "{PLAYER} receieved the {COLOR GREEN}PokéGear$"

PlayersHouse_es_DadBeforeExit_Text_2:
# 491 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Feels like yesterday went I was\n"
	.string "teaching you type advantages...\p"
	.string "Time flies{PAUSE 5}.{PAUSE 5}.{PAUSE 5}.{PAUSE 5}\p"
	.string "{COLOR DARK_GREY}Dad: {COLOR BLUE}Now, try out that fancy new tech\n"
	.string "of yours!\p"
	.string "Try calling your friend {COLOR GREEN}Skip{COLOR BLUE}.$"

PlayersHouse_es_DadBeforeExit_Text_3:
# 495 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Don't be late to see {COLOR GREEN}Professor\n"
	.string "Cypress{COLOR BLUE}!$"

PlayersHouse_es_DadBeforeExit_Text_4:
# 499 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Come by to see your old man?\p"
	.string "You should rest up while you're here.$"

PlayersHouse_es_DadBeforeExit_Text_5:
# 506 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Thanks for stopping by {PLAYER}.\p"
	.string "Stay safe out there, don't forget to\n"
	.string "come home once in a while!$"

PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_0:
# 536 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Good!\p"
	.string "Now that you're all setup with the\n"
	.string "{COLOR GREEN}PokéGear{COLOR BLUE}, you can call home too!$"

PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_1:
# 539 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered {COLOR GREEN}Dad{COLOR DARK_GREY} as a contact in the\n"
	.string "{COLOR GREEN}PokéGear{COLOR BLUE}$"

PlayersHouse_es_DadBeforeExit_PokegearTutorial_Text_2:
# 542 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Quickly now, the professor will be\n"
	.string "showing up any minute!$"

PlayersHouse_DadBeforeExit_txt_PleaseSelectPokegear_Text_0:
# 552 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: {COLOR BLUE}Try using the {COLOR GREEN}PokéGear$"
