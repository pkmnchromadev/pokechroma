# 1 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
# 3 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
# 4 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
# 5 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
# 6 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 8 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnLoad: @ 81F88B5
# 9 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 10 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_lt LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
# 11 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
# 12 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 13 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 14 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes:: @ 81F88CA
# 15 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 16 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 17 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual:: @ 81F88DD
# 18 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkplayergender
# 19 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 20 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
# 21 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 22 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 23 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F88EA
# 24 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 25 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 26 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnTransition: @ 81F88F4
# 27 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
# 28 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
# 29 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 5
# 30 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
# 31 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 32 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
# 33 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 34 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs:: @ 81F8916
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 2, 4
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 38 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 39 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 40 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV:: @ 81F8922
# 41 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 6, 5
# 42 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 43 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 44 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 45 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor:: @ 81F892E
# 46 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 1, 8
# 47 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 48 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 49 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 50 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 51 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnFrame: @ 81F893A
# 52 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
# 53 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
# 54 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
# 55 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
# 56 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 57 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.2byte 0
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F8964
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 65 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 1, 1
# 67 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 68 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 69 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 70 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 71 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs: @ 81F898A
# 72 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 73 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 74 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 75 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F898C
# 76 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 77 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 78 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 79 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 80 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 81 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 82 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport:: @ 81F899D
# 83 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 84 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 85 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 89 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor:: @ 81F89AE
# 90 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 91 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 92 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 93 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 94 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 95 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 96 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
# 98 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 100 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 101 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 105 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 106 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach: @ 81F89EC
# 107 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 108 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 113 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 114 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 115 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalMom:: @ 81F89F3
# 116 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 117 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 118 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 119 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq RivalsHouse_1F_EventScript_RivalTooBusy
# 122 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 123 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 124 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalTooBusy:: @ 81F8A1F
# 128 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 129 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 130 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 131 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalIsOnRoute103:: @ 81F8A29
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 134 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 135 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 137 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_GoHomeEverySoOften:: @ 81F8A33
# 138 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 139 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 140 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 141 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 142 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalSibling:: @ 81F8A3D
# 143 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 144 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 145 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 146 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
# 147 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 148 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 149 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 150 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom:: @ 81F8A4C
# 151 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 152 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 153 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 154 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 155 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 156 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 157 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 158 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 159 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival0:: @ 81F8A67
# 160 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 161 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 163 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 164 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 165 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival1:: @ 81F8A73
# 166 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 167 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 168 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 169 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 170 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 171 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival2:: @ 81F8A7F
# 172 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 173 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 174 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 175 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 176 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 177 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival:: @ 81F8A8B
# 178 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 179 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 10
# 180 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	addobject 7
# 181 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 182 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 183 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 184 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 185 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, Common_Movement_Delay48
# 186 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 187 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 188 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_ne LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
# 189 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, 1
# 190 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 191 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
# 192 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 193 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
# 194 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
# 196 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 197 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 198 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 199 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
# 200 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 201 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 203 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
# 204 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 205 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	removeobject 7
# 206 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 207 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 208 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 209 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 210 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 211 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 212 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadedefaultbgm
# 214 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 215 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 216 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 217 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay:: @ 81F8B2A
# 218 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 219 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 220 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 221 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 222 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0:: @ 81F8B35
# 223 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
# 224 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 225 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 226 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 227 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1:: @ 81F8B40
# 228 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
# 229 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 230 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 231 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 232 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2:: @ 81F8B4B
# 233 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
# 234 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 235 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 236 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 237 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0: @ 81F8B56
# 238 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 239 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 240 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 241 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 242 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 243 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 244 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 245 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 246 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 247 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1: @ 81F8B5E
# 248 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 249 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 250 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 251 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 252 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 253 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2: @ 81F8B62
# 254 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 255 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 256 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 257 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 258 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 259 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 260 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 261 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 262 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 263 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0:: @ 81F8B6A
# 264 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
# 265 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
# 266 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 267 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 268 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 269 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1:: @ 81F8B7C
# 270 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
# 271 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
# 272 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 273 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 274 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 275 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2:: @ 81F8B8E
# 276 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
# 277 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
# 278 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 279 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 280 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 281 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0: @ 81F8BA0
# 282 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 283 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 284 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 285 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 286 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 287 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1: @ 81F8BA4
# 288 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 289 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 290 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 291 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 292 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 293 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 294 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 295 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 296 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2: @ 81F8BAB
# 297 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 298 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 299 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 300 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 301 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 302 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0: @ 81F8BAF
# 303 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 304 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 305 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 306 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 307 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 308 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 309 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 310 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1: @ 81F8BB5
# 311 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 312 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 313 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 314 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 315 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 316 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 317 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 318 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 319 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 320 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 321 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 322 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2: @ 81F8BBF
# 323 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 324 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 325 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 326 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 327 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 328 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 329 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 330 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_OhYoureTheNewNeighbor: @ 81F8BC5
# 331 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello. And you are?\p"
# 332 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … … …\n"
# 333 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … … …\p"
# 334 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}, our new next-door\n"
# 335 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "neighbor! Hi!\p"
# 336 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "We have a {STR_VAR_1} about the same\n"
# 337 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "age as you.\p"
# 338 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Our {STR_VAR_1} was excited about making\n"
# 339 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "a new friend.\p"
# 340 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Our {STR_VAR_1} is upstairs, I think.$"
# 341 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 342 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_LikeChildLikeFather: @ 81F8CA5
# 343 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like child, like father.\p"
# 344 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "My husband is as wild about POKéMON\n"
# 345 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "as our child.\p"
# 346 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "If he's not at his LAB, he's likely\n"
# 347 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "scrabbling about in grassy places.$"
# 348 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 349 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_TooBusyToNoticeVisit: @ 81F8D37
# 350 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
# 351 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I guess our child is too busy with\n"
# 352 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "POKéMON to notice that you came\l"
# 353 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to visit, {PLAYER}{KUN}.$"
# 354 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 355 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_WentOutToRoute103: @ 81F8D93
# 356 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
# 357 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "just a little while ago.\p"
# 358 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like father, like child.\n"
# 359 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{RIVAL} can't stay quietly at home.$"
# 360 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 361 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_ShouldGoHomeEverySoOften: @ 81F8E01
# 362 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
# 363 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "travel with POKéMON.\p"
# 364 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "But you should go home every so often\n"
# 365 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to let your mother know you're okay.\p"
# 366 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "She might not say it, but I'm sure she\n"
# 367 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "worries about you, {PLAYER}{KUN}.$"
# 368 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 369 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_MayWhoAreYou: @ 81F8EC6
# 370 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Huh?\n"
# 371 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Who… Who are you?\p"
# 372 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\n"
# 373 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\p"
# 374 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 375 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "So your move was today.\p"
# 376 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Um… I'm MAY.\n"
# 377 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Glad to meet you!\p"
# 378 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I…\n"
# 379 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 380 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "with POKéMON all over the world.\p"
# 381 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 382 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "my dad, PROF. BIRCH.\p"
# 383 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 384 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 385 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 386 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 387 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Eheheh…\p"
# 388 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 389 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 390 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "some wild POKéMON!\p"
# 391 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 392 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 393 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_BrendanWhoAreYou: @ 81F90B4
# 394 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hey!\n"
# 395 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "You…\p"
# 396 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Who are you?\p"
# 397 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 398 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Moved in next door, right?\p"
# 399 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 400 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Dad, PROF. BIRCH, said that our new\n"
# 401 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "next-door neighbor is a GYM LEADER's\l"
# 402 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 403 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "My name's BRENDAN.\n"
# 404 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 405 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 406 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "a POKéMON?\p"
# 407 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 408 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 409 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 410 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "some wild POKéMON.\p"
# 411 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Some other time, okay?$"
# 412 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 413 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_DoYouHavePokemon: @ 81F9262
# 414 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hi, neighbor!\p"
# 415 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Do you already have your\n"
# 416 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "own POKéMON?$"
