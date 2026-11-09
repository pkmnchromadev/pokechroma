# 1 "data/maps/OldaleTown/scripts.pory"

# 2 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_MART_EMPLOYEE, 2
# 3 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_RIVAL, 4
# 4 "data/maps/OldaleTown/scripts.pory"

# 5 "data/maps/OldaleTown/scripts.pory"
@OldaleTown_MapScripts::
# 6 "data/maps/OldaleTown/scripts.pory"
@	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 7 "data/maps/OldaleTown/scripts.pory"
@	.byte 0
# 8 "data/maps/OldaleTown/scripts.pory"

# 9 "data/maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition:
# 10 "data/maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_ROSSANO_TOWN
# 12 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 13 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 14 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 15 "data/maps/OldaleTown/scripts.pory"
	end
# 16 "data/maps/OldaleTown/scripts.pory"

# 17 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_ROSSANO_TOWN_STATE
# 18 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 19 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_ROSSANO_TOWN_STATE, 1
# 20 "data/maps/OldaleTown/scripts.pory"
	return
# 21 "data/maps/OldaleTown/scripts.pory"

# 22 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 23 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 24 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 25 "data/maps/OldaleTown/scripts.pory"
	return
# 26 "data/maps/OldaleTown/scripts.pory"

# 27 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 28 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
# 29 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 30 "data/maps/OldaleTown/scripts.pory"
	return
# 31 "data/maps/OldaleTown/scripts.pory"

# 32 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 33 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 34 "data/maps/OldaleTown/scripts.pory"
	end
# 35 "data/maps/OldaleTown/scripts.pory"

# 36 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl::
# 37 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 38 "data/maps/OldaleTown/scripts.pory"
	end
# 39 "data/maps/OldaleTown/scripts.pory"

# 40 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 41 "data/maps/OldaleTown/scripts.pory"
	lock
# 42 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 43 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 44 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 45 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 46 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 47 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 48 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 49 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 50 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 51 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 52 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 53 "data/maps/OldaleTown/scripts.pory"
	end
# 54 "data/maps/OldaleTown/scripts.pory"

# 55 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 56 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 57 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
# 58 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 59 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 60 "data/maps/OldaleTown/scripts.pory"
	end
# 61 "data/maps/OldaleTown/scripts.pory"

# 62 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 63 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 64 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
# 65 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 66 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 67 "data/maps/OldaleTown/scripts.pory"
	end
# 68 "data/maps/OldaleTown/scripts.pory"

# 69 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 70 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
# 71 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 72 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 74 "data/maps/OldaleTown/scripts.pory"
	end
# 75 "data/maps/OldaleTown/scripts.pory"

# 76 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 77 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 78 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 79 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 80 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 81 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 82 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 83 "data/maps/OldaleTown/scripts.pory"
	release
# 84 "data/maps/OldaleTown/scripts.pory"
	end
# 85 "data/maps/OldaleTown/scripts.pory"

# 86 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 87 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 88 "data/maps/OldaleTown/scripts.pory"
	release
# 89 "data/maps/OldaleTown/scripts.pory"
	end
# 90 "data/maps/OldaleTown/scripts.pory"

# 91 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 92 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 93 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 94 "data/maps/OldaleTown/scripts.pory"
	release
# 95 "data/maps/OldaleTown/scripts.pory"
	end
# 96 "data/maps/OldaleTown/scripts.pory"

# 97 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 98 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 99 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 100 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 101 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 102 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 103 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 104 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 105 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 106 "data/maps/OldaleTown/scripts.pory"
	step_end
# 107 "data/maps/OldaleTown/scripts.pory"

# 108 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 109 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 112 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 113 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 114 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 116 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 117 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 118 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 119 "data/maps/OldaleTown/scripts.pory"
	step_end
# 120 "data/maps/OldaleTown/scripts.pory"

# 121 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 122 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 123 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 124 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 125 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 126 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 127 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 129 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 130 "data/maps/OldaleTown/scripts.pory"
	step_end
# 131 "data/maps/OldaleTown/scripts.pory"

# 132 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1:
# 133 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 136 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 137 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 138 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 139 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 140 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 141 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 142 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 143 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 144 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 145 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 146 "data/maps/OldaleTown/scripts.pory"
	step_end
# 147 "data/maps/OldaleTown/scripts.pory"

# 148 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
# 149 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 150 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 151 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 152 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 153 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 154 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 155 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 156 "data/maps/OldaleTown/scripts.pory"
	step_end
# 157 "data/maps/OldaleTown/scripts.pory"

# 158 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 159 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 160 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 161 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 162 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 163 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 164 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 165 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 166 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 167 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 168 "data/maps/OldaleTown/scripts.pory"
	step_end
# 169 "data/maps/OldaleTown/scripts.pory"

# 170 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 171 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 172 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 173 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 175 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 176 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	step_end
# 179 "data/maps/OldaleTown/scripts.pory"

# 180 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 181 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 182 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 184 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 185 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 186 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 187 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 188 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 189 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 190 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 191 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 192 "data/maps/OldaleTown/scripts.pory"
	step_end
# 193 "data/maps/OldaleTown/scripts.pory"

# 194 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 195 "data/maps/OldaleTown/scripts.pory"
	lock
# 196 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 197 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 198 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 199 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 200 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 201 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 202 "data/maps/OldaleTown/scripts.pory"
	release
# 203 "data/maps/OldaleTown/scripts.pory"
	end
# 204 "data/maps/OldaleTown/scripts.pory"

# 205 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 206 "data/maps/OldaleTown/scripts.pory"
	lockall
# 207 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 208 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 209 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 210 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 211 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 212 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 213 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 214 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 215 "data/maps/OldaleTown/scripts.pory"
	end
# 216 "data/maps/OldaleTown/scripts.pory"

# 217 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 218 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 219 "data/maps/OldaleTown/scripts.pory"
	release
# 220 "data/maps/OldaleTown/scripts.pory"
	end
# 221 "data/maps/OldaleTown/scripts.pory"

# 222 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 223 "data/maps/OldaleTown/scripts.pory"
	lockall
# 224 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 225 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 226 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 227 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 228 "data/maps/OldaleTown/scripts.pory"
	end
# 229 "data/maps/OldaleTown/scripts.pory"

# 230 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 231 "data/maps/OldaleTown/scripts.pory"
	lockall
# 232 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 233 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 234 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 235 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 237 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 238 "data/maps/OldaleTown/scripts.pory"
	end
# 239 "data/maps/OldaleTown/scripts.pory"

# 240 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 241 "data/maps/OldaleTown/scripts.pory"
	lockall
# 242 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 243 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 244 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 245 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 246 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 247 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 248 "data/maps/OldaleTown/scripts.pory"
	end
# 249 "data/maps/OldaleTown/scripts.pory"

# 250 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 251 "data/maps/OldaleTown/scripts.pory"
	lockall
# 252 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 253 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 254 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 255 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 256 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 257 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 258 "data/maps/OldaleTown/scripts.pory"
	end
# 259 "data/maps/OldaleTown/scripts.pory"

# 260 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 261 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 262 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 263 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 264 "data/maps/OldaleTown/scripts.pory"
	end
# 265 "data/maps/OldaleTown/scripts.pory"

# 266 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 267 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 268 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 269 "data/maps/OldaleTown/scripts.pory"
	end
# 270 "data/maps/OldaleTown/scripts.pory"

# 271 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 272 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 273 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 274 "data/maps/OldaleTown/scripts.pory"
	end
# 275 "data/maps/OldaleTown/scripts.pory"

# 276 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 277 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 278 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 279 "data/maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 280 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 281 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 282 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 283 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 284 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 285 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 286 "data/maps/OldaleTown/scripts.pory"
	end
# 287 "data/maps/OldaleTown/scripts.pory"

# 288 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 289 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 290 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 291 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 292 "data/maps/OldaleTown/scripts.pory"
	return
# 293 "data/maps/OldaleTown/scripts.pory"

# 294 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 295 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 296 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 297 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 298 "data/maps/OldaleTown/scripts.pory"
	return
# 299 "data/maps/OldaleTown/scripts.pory"

# 300 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 301 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 302 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 303 "data/maps/OldaleTown/scripts.pory"
	step_end
# 304 "data/maps/OldaleTown/scripts.pory"

# 305 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 306 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 307 "data/maps/OldaleTown/scripts.pory"
	step_end
# 308 "data/maps/OldaleTown/scripts.pory"

# 309 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 310 "data/maps/OldaleTown/scripts.pory"
	face_left
# 311 "data/maps/OldaleTown/scripts.pory"
	step_end
# 312 "data/maps/OldaleTown/scripts.pory"

# 313 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 314 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 315 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 316 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 317 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 318 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 319 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 320 "data/maps/OldaleTown/scripts.pory"
	step_end
# 321 "data/maps/OldaleTown/scripts.pory"

# 322 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 323 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 324 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 325 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 326 "data/maps/OldaleTown/scripts.pory"
	step_end
# 327 "data/maps/OldaleTown/scripts.pory"

# 328 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 329 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 330 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 331 "data/maps/OldaleTown/scripts.pory"
	step_end
# 332 "data/maps/OldaleTown/scripts.pory"

# 333 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 334 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 335 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 336 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 337 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 338 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 339 "data/maps/OldaleTown/scripts.pory"
	step_end
# 340 "data/maps/OldaleTown/scripts.pory"

# 341 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 342 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 343 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 344 "data/maps/OldaleTown/scripts.pory"
	step_end
# 345 "data/maps/OldaleTown/scripts.pory"

# 346 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress:
# 347 "data/maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 348 "data/maps/OldaleTown/scripts.pory"
	.string "progress.$"
# 349 "data/maps/OldaleTown/scripts.pory"

# 350 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 351 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 352 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 353 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 354 "data/maps/OldaleTown/scripts.pory"

# 355 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 356 "data/maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 357 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 358 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 359 "data/maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 360 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 361 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 362 "data/maps/OldaleTown/scripts.pory"

# 363 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 364 "data/maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 365 "data/maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 366 "data/maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 367 "data/maps/OldaleTown/scripts.pory"

# 368 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 369 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 370 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 371 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 372 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 373 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 374 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 375 "data/maps/OldaleTown/scripts.pory"

# 376 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 377 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 378 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 379 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 381 "data/maps/OldaleTown/scripts.pory"

# 382 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 383 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 384 "data/maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 385 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 386 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 387 "data/maps/OldaleTown/scripts.pory"

# 388 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 389 "data/maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 390 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 391 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 392 "data/maps/OldaleTown/scripts.pory"

# 393 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 394 "data/maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 395 "data/maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 396 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 397 "data/maps/OldaleTown/scripts.pory"

# 398 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 399 "data/maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 400 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"

OldaleTown_MapScripts::
# 408 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 409 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_ROSSANO_TOWN
# 410 "data/maps/OldaleTown/scripts.pory"
	switch VAR_ROSSANO_TOWN_STATE
# 411 "data/maps/OldaleTown/scripts.pory"
	case 0, OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 412 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm 2, 3, 10
# 413 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	return


RossanoTown_Object_Boy::
# 419 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Object_Boy_Text_0, MSGBOX_NPC
	end


RossanoTown_Object_Girl::
# 423 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Object_Girl_Text_0, MSGBOX_NPC
	end


RossanoTown_Object_Officer::
# 427 "data/maps/OldaleTown/scripts.pory"
	lock
# 428 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 429 "data/maps/OldaleTown/scripts.pory"
	compare VAR_ROSSANO_TOWN_STATE, 0
	goto_if_eq RossanoTown_Object_Officer_2
# 432 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Object_Officer_Text_1, MSGBOX_AUTOCLOSE
RossanoTown_Object_Officer_1:
# 434 "data/maps/OldaleTown/scripts.pory"
	release
	end

RossanoTown_Object_Officer_2:
# 430 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Object_Officer_Text_0, MSGBOX_AUTOCLOSE
	goto RossanoTown_Object_Officer_1


RossanoTown_Sign_TownSign::
# 438 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Sign_TownSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_DEFAULT
	end


RossanoTown_Sign_LibrarySign::
# 442 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Sign_LibrarySign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


RossanoTown_Sign_RouteSign::
# 446 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Sign_RouteSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


RossanoTown_ItemBall_WaterStone::
# 450 "data/maps/OldaleTown/scripts.pory"
	finditem ITEM_WATER_STONE, 1
	end


RossanoTown_ItemBall_BurnHeal::
# 454 "data/maps/OldaleTown/scripts.pory"
	finditem ITEM_BURN_HEAL, 1
	end


RossanoTown_Trigger_NoExitNeedLibrary::
# 459 "data/maps/OldaleTown/scripts.pory"
	lockall
# 460 "data/maps/OldaleTown/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 461 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 462 "data/maps/OldaleTown/scripts.pory"
	playse SE_PIN
# 463 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Trigger_NoExitNeedLibrary_Text_0, MSGBOX_AUTOCLOSE
# 464 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 465 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq RossanoTown_Trigger_NoExitNeedLibrary_2
RossanoTown_Trigger_NoExitNeedLibrary_1:
# 469 "data/maps/OldaleTown/scripts.pory"
	msgbox RossanoTown_Object_Officer_Text_0
# 470 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RossanoTown_Movement_NoExitNeedLibrary_p0
# 471 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 472 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq RossanoTown_Trigger_NoExitNeedLibrary_5
RossanoTown_Trigger_NoExitNeedLibrary_4:
# 476 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 477 "data/maps/OldaleTown/scripts.pory"
	releaseall
	end

RossanoTown_Trigger_NoExitNeedLibrary_2:
# 466 "data/maps/OldaleTown/scripts.pory"
	applymovement 2, RossanoTown_Movement_NoExitNeedLibrary_0
# 467 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
	goto RossanoTown_Trigger_NoExitNeedLibrary_1

RossanoTown_Trigger_NoExitNeedLibrary_5:
# 473 "data/maps/OldaleTown/scripts.pory"
	applymovement 2, RossanoTown_Movement_NoExitNeedLibrary_1
# 474 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
	goto RossanoTown_Trigger_NoExitNeedLibrary_4


# 480 "data/maps/OldaleTown/scripts.pory"
RossanoTown_Movement_NoExitNeedLibrary_0:
# 481 "data/maps/OldaleTown/scripts.pory"
	walk_right
	step_end

# 483 "data/maps/OldaleTown/scripts.pory"
RossanoTown_Movement_NoExitNeedLibrary_p0:
# 484 "data/maps/OldaleTown/scripts.pory"
	walk_down
	step_end

# 486 "data/maps/OldaleTown/scripts.pory"
RossanoTown_Movement_NoExitNeedLibrary_1:
# 487 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 488 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

RossanoTown_Object_Boy_Text_0:
# 419 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR GREEN}Rossano Town{COLOR BLUE} is an older settlement in\n"
	.string "{COLOR GREEN}Ryoko{COLOR BLUE}.\p"
	.string "The Library is full of old books, dating\n"
	.string "back to when {COLOR GREEN}Ryoko{COLOR BLUE} was discovered.$"

RossanoTown_Object_Girl_Text_0:
# 423 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR RED}I was raised here in {COLOR GREEN}Rossano{COLOR RED}.\p"
	.string "I've always wanted to be a Pokémon\n"
	.string "Trainer, but I don't ever feel like\l"
	.string "leaving town!$"

RossanoTown_Object_Officer_Text_0:
# 430 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR BLUE}Sorry kid, no one is leaving town.\p"
	.string "There have been reports of a\n"
	.string "suspicious character in town.$"

RossanoTown_Object_Officer_Text_1:
# 432 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR BLUE}I'm stationed here outside the library\n"
	.string "to make sure no one ends up stealing\l"
	.string "books again.$"

RossanoTown_Sign_TownSign_Text_0:
# 438 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR LIGHT_BLUE}Rossano Town{COLOR DARK_GREY}\n"
	.string "{FONT_SMALL}“History in Text”$"

RossanoTown_Sign_LibrarySign_Text_0:
# 442 "data/maps/OldaleTown/scripts.pory"
	.string "Library$"

RossanoTown_Sign_RouteSign_Text_0:
# 446 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR DARK_GREY}{LEFT_ARROW} Rossano Foothills$"

RossanoTown_Trigger_NoExitNeedLibrary_Text_0:
# 463 "data/maps/OldaleTown/scripts.pory"
	.string "{COLOR BLUE}Hold it!$"
