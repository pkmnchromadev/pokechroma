# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 3 "data/maps/Route102/scripts.pory"
	.byte 0
# 4 "data/maps/Route102/scripts.pory"

# 5 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 6 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 7 "data/maps/Route102/scripts.pory"
	end
# 8 "data/maps/Route102/scripts.pory"

# 9 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 10 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 11 "data/maps/Route102/scripts.pory"
	end
# 12 "data/maps/Route102/scripts.pory"

# 13 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 14 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 15 "data/maps/Route102/scripts.pory"
	end
# 16 "data/maps/Route102/scripts.pory"

# 17 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 18 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 19 "data/maps/Route102/scripts.pory"
	end
# 20 "data/maps/Route102/scripts.pory"

# 21 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 22 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 23 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 24 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 25 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 26 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 27 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 28 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 29 "data/maps/Route102/scripts.pory"
	release
# 30 "data/maps/Route102/scripts.pory"
	end
# 31 "data/maps/Route102/scripts.pory"

# 32 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 33 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 34 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 35 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 36 "data/maps/Route102/scripts.pory"
	release
# 37 "data/maps/Route102/scripts.pory"
	end
# 38 "data/maps/Route102/scripts.pory"

# 39 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 40 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 41 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 42 "data/maps/Route102/scripts.pory"
	release
# 43 "data/maps/Route102/scripts.pory"
	end
# 44 "data/maps/Route102/scripts.pory"

# 45 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 46 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 47 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 48 "data/maps/Route102/scripts.pory"
	release
# 49 "data/maps/Route102/scripts.pory"
	end
# 50 "data/maps/Route102/scripts.pory"

# 51 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 52 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 53 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 54 "data/maps/Route102/scripts.pory"
	release
# 55 "data/maps/Route102/scripts.pory"
	end
# 56 "data/maps/Route102/scripts.pory"

# 57 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 58 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 59 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 60 "data/maps/Route102/scripts.pory"
	end
# 61 "data/maps/Route102/scripts.pory"

# 62 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 63 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 64 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 65 "data/maps/Route102/scripts.pory"
	end
# 66 "data/maps/Route102/scripts.pory"

# 67 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 68 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 69 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 70 "data/maps/Route102/scripts.pory"
	end
# 71 "data/maps/Route102/scripts.pory"

# 72 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 73 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 74 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 75 "data/maps/Route102/scripts.pory"
	end
# 76 "data/maps/Route102/scripts.pory"

# 77 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 78 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 79 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 80 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 81 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 82 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 83 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 84 "data/maps/Route102/scripts.pory"

# 85 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 86 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 87 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 88 "data/maps/Route102/scripts.pory"

# 89 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 90 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 91 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 92 "data/maps/Route102/scripts.pory"

# 93 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 94 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 95 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 96 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 97 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 98 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 99 "data/maps/Route102/scripts.pory"

# 100 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 101 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 102 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 103 "data/maps/Route102/scripts.pory"

# 104 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 105 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 106 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 107 "data/maps/Route102/scripts.pory"

# 108 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 109 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 110 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

RossanoFoothills_trg_RivalBattle::
# 119 "data/maps/Route102/scripts.pory"
	lockall
# 120 "data/maps/Route102/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceDown
# 121 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route102/scripts.pory"
	delay 30
# 123 "data/maps/Route102/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 124 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 125 "data/maps/Route102/scripts.pory"
	playse SE_PIN
# 126 "data/maps/Route102/scripts.pory"
	waitse
# 127 "data/maps/Route102/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
# 128 "data/maps/Route102/scripts.pory"
	setspeaker RossanoFoothills_trg_RivalBattle_Text_0
# 129 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_trg_RivalBattle_Text_1, MSGBOX_AUTOCLOSE
# 130 "data/maps/Route102/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 131 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 59
	goto_if_eq RossanoFoothills_trg_RivalBattle_2
# 136 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 60
	goto_if_eq RossanoFoothills_trg_RivalBattle_3
# 139 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 61
	goto_if_eq RossanoFoothills_trg_RivalBattle_4
# 144 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 62
	goto_if_eq RossanoFoothills_trg_RivalBattle_5
# 149 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 63
	goto_if_eq RossanoFoothills_trg_RivalBattle_6
RossanoFoothills_trg_RivalBattle_1:
# 155 "data/maps/Route102/scripts.pory"
	setspeaker RossanoFoothills_trg_RivalBattle_Text_0
# 156 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_trg_RivalBattle_Text_2, MSGBOX_AUTOCLOSE
# 157 "data/maps/Route102/scripts.pory"
	switch VAR_STARTER_MON
# 158 "data/maps/Route102/scripts.pory"
	case 0, RossanoFoothills_trg_RivalBattle_14
# 160 "data/maps/Route102/scripts.pory"
	case 1, RossanoFoothills_trg_RivalBattle_15
# 162 "data/maps/Route102/scripts.pory"
	case 2, RossanoFoothills_trg_RivalBattle_16
RossanoFoothills_trg_RivalBattle_12:
# 165 "data/maps/Route102/scripts.pory"
	goto RossanoFoothills_es_RivalDefeat
	end

RossanoFoothills_trg_RivalBattle_2:
# 132 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_0
# 133 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 134 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
# 135 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_trg_RivalBattle_1

RossanoFoothills_trg_RivalBattle_3:
# 137 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_1
# 138 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_trg_RivalBattle_1

RossanoFoothills_trg_RivalBattle_4:
# 140 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_2
# 141 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 142 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 143 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_trg_RivalBattle_1

RossanoFoothills_trg_RivalBattle_5:
# 145 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_3
# 146 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 147 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 148 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_trg_RivalBattle_1

RossanoFoothills_trg_RivalBattle_6:
# 150 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_4
# 151 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 152 "data/maps/Route102/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 153 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_trg_RivalBattle_1

RossanoFoothills_trg_RivalBattle_14:
# 159 "data/maps/Route102/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SKIP_ROSSANO_2, RossanoFoothills_text_RivalDefeat
	goto RossanoFoothills_trg_RivalBattle_12

RossanoFoothills_trg_RivalBattle_15:
# 161 "data/maps/Route102/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SKIP_ROSSANO_3, RossanoFoothills_text_RivalDefeat
	goto RossanoFoothills_trg_RivalBattle_12

RossanoFoothills_trg_RivalBattle_16:
# 163 "data/maps/Route102/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SKIP_ROSSANO_1, RossanoFoothills_text_RivalDefeat
	goto RossanoFoothills_trg_RivalBattle_12


RossanoFoothills_es_RivalDefeat::
# 170 "data/maps/Route102/scripts.pory"
	lockall
# 171 "data/maps/Route102/scripts.pory"
	playbgm MUS_RG_RIVAL_EXIT, FALSE
# 172 "data/maps/Route102/scripts.pory"
	setspeaker RossanoFoothills_trg_RivalBattle_Text_0
# 173 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_es_RivalDefeat_Text_0, MSGBOX_AUTOCLOSE
# 174 "data/maps/Route102/scripts.pory"
	delay 30
# 175 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_es_RivalDefeat_Text_1, MSGBOX_AUTOCLOSE
# 176 "data/maps/Route102/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 177 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 59
	goto_if_eq RossanoFoothills_es_RivalDefeat_2
# 180 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 60
	goto_if_eq RossanoFoothills_es_RivalDefeat_3
# 184 "data/maps/Route102/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceRight
# 185 "data/maps/Route102/scripts.pory"
	waitmovement 0
RossanoFoothills_es_RivalDefeat_1:
# 187 "data/maps/Route102/scripts.pory"
	removeitem ITEM_PARCEL
# 188 "data/maps/Route102/scripts.pory"
	delay 30
# 189 "data/maps/Route102/scripts.pory"
	setspeaker RossanoFoothills_trg_RivalBattle_Text_0
# 190 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_es_RivalDefeat_Text_2, MSGBOX_AUTOCLOSE
# 191 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 60
	goto_if_eq RossanoFoothills_es_RivalDefeat_8
# 194 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_0, 59
	goto_if_eq RossanoFoothills_es_RivalDefeat_9
# 198 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_7
# 199 "data/maps/Route102/scripts.pory"
	waitmovement 0
RossanoFoothills_es_RivalDefeat_7:
# 201 "data/maps/Route102/scripts.pory"
	fadenewbgm MUS_RG_ROUTE11
# 202 "data/maps/Route102/scripts.pory"
	setvar VAR_ROSSANO_FOOTHILLS_RIVAL_BATTLE, 1
# 203 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROSSANO_FOOTHILLS_RIVAL_BATTLE
# 204 "data/maps/Route102/scripts.pory"
	removeobject 8
# 205 "data/maps/Route102/scripts.pory"
	releaseall
	end

RossanoFoothills_es_RivalDefeat_2:
# 178 "data/maps/Route102/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceLeft
# 179 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_es_RivalDefeat_1

RossanoFoothills_es_RivalDefeat_3:
# 181 "data/maps/Route102/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceDown
# 182 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_es_RivalDefeat_1

RossanoFoothills_es_RivalDefeat_8:
# 192 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_5
# 193 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_es_RivalDefeat_7

RossanoFoothills_es_RivalDefeat_9:
# 195 "data/maps/Route102/scripts.pory"
	applymovement 8, RossanoFoothills_Movement_6
# 196 "data/maps/Route102/scripts.pory"
	waitmovement 0
	goto RossanoFoothills_es_RivalDefeat_7


# 213 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_0:
# 214 "data/maps/Route102/scripts.pory"
	walk_down
# 214 "data/maps/Route102/scripts.pory"
	walk_down
# 214 "data/maps/Route102/scripts.pory"
	walk_down
# 215 "data/maps/Route102/scripts.pory"
	walk_in_place_left
	step_end

# 218 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_1:
# 219 "data/maps/Route102/scripts.pory"
	walk_down
# 219 "data/maps/Route102/scripts.pory"
	walk_down
	step_end

# 222 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_2:
# 223 "data/maps/Route102/scripts.pory"
	walk_down
# 223 "data/maps/Route102/scripts.pory"
	walk_down
# 223 "data/maps/Route102/scripts.pory"
	walk_down
# 224 "data/maps/Route102/scripts.pory"
	walk_in_place_right
	step_end

# 227 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_3:
# 228 "data/maps/Route102/scripts.pory"
	walk_down
# 228 "data/maps/Route102/scripts.pory"
	walk_down
# 228 "data/maps/Route102/scripts.pory"
	walk_down
# 229 "data/maps/Route102/scripts.pory"
	walk_right
	step_end

# 232 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_4:
# 233 "data/maps/Route102/scripts.pory"
	walk_down
# 233 "data/maps/Route102/scripts.pory"
	walk_down
# 233 "data/maps/Route102/scripts.pory"
	walk_down
# 234 "data/maps/Route102/scripts.pory"
	walk_right
# 234 "data/maps/Route102/scripts.pory"
	walk_right
	step_end

# 237 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_5:
# 238 "data/maps/Route102/scripts.pory"
	walk_up
# 238 "data/maps/Route102/scripts.pory"
	walk_up
# 238 "data/maps/Route102/scripts.pory"
	walk_up
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
# 239 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

# 242 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_6:
# 243 "data/maps/Route102/scripts.pory"
	walk_up
# 243 "data/maps/Route102/scripts.pory"
	walk_up
# 243 "data/maps/Route102/scripts.pory"
	walk_up
# 243 "data/maps/Route102/scripts.pory"
	walk_up
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 244 "data/maps/Route102/scripts.pory"
	walk_left
# 245 "data/maps/Route102/scripts.pory"
	walk_down
# 245 "data/maps/Route102/scripts.pory"
	walk_down
# 246 "data/maps/Route102/scripts.pory"
	walk_left
# 246 "data/maps/Route102/scripts.pory"
	walk_left
# 246 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

# 249 "data/maps/Route102/scripts.pory"
RossanoFoothills_Movement_7:
# 250 "data/maps/Route102/scripts.pory"
	walk_up
# 250 "data/maps/Route102/scripts.pory"
	walk_up
# 250 "data/maps/Route102/scripts.pory"
	walk_up
# 250 "data/maps/Route102/scripts.pory"
	walk_up
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
# 251 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

RossanoFoothills_Sign_IgnisCave::
# 256 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Sign_IgnisCave_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


RossanoFoothills_Sign_RouteSign::
# 260 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Sign_RouteSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


RossanoFoothills_Object_Boy::
# 265 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Object_Boy_Text_0, MSGBOX_NPC
	end


RossanoFoothills_ItemBall_HyperPotion::
# 269 "data/maps/Route102/scripts.pory"
	finditem ITEM_HYPER_POTION
	end


RossanoFoothills_Trainer_BirdKeeper::
# 274 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BIRDKEEPER_CICERO, RossanoFoothills_Trainer_BirdKeeper_Text_0, RossanoFoothills_Trainer_BirdKeeper_Text_1
# 275 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_BirdKeeper_Text_2, MSGBOX_NPC
	end


RossanoFoothills_Trainer_BugCatcher::
# 279 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BUGCATCHER_GABRIEL, RossanoFoothills_Trainer_BugCatcher_Text_0, RossanoFoothills_Trainer_BugCatcher_Text_1
# 280 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_BugCatcher_Text_2, MSGBOX_NPC
	end


RossanoFoothills_Trainer_Lass::
# 284 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_AROMALADY_JESSI, RossanoFoothills_Trainer_Lass_Text_0, RossanoFoothills_Trainer_Lass_Text_1
# 285 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_Lass_Text_2, MSGBOX_NPC
	end


RossanoFoothills_trg_RivalBattle_Text_0:
# 128 "data/maps/Route102/scripts.pory"
	.string "Skip$"

RossanoFoothills_trg_RivalBattle_Text_1:
# 129 "data/maps/Route102/scripts.pory"
	.string "Hey there's the slowpoke!$"

RossanoFoothills_trg_RivalBattle_Text_2:
# 156 "data/maps/Route102/scripts.pory"
	.string "Took ya long enough!\n"
	.string "Did the Professor give you an earful?\p"
	.string "Keepin' it real, I couldn't sit around\n"
	.string "for some lousy speech.\p"
	.string "“Take care of your Pokémon...”\n"
	.string "Blah blah blah\p"
	.string "{PLAYER}!\n"
	.string "My dream has finally come true!\p"
	.string "Today marks the start of my journey to\n"
	.string "become the best Pokémon Trainer\l"
	.string "in all of Ryoko.\p"
	.string "And you'll be my training buddy!\p"
	.string "With your help, I can get stronger!\p"
	.string "So let me wipe the floor with your face!$"

RossanoFoothills_es_RivalDefeat_Text_0:
# 173 "data/maps/Route102/scripts.pory"
	.string "Tsk!{PAUSE 20}\n"
	.string "I need to train more.\p"
	.string "It was a fine battle...\n"
	.string "but we're both just getting started.\p"
	.string "What?\n"
	.string "You got somethin' for me?$"

RossanoFoothills_es_RivalDefeat_Text_1:
# 175 "data/maps/Route102/scripts.pory"
	.string "You handed over the {COLOR GREEN}Parcel$"

RossanoFoothills_es_RivalDefeat_Text_2:
# 190 "data/maps/Route102/scripts.pory"
	.string "So, Prof. Cypress wants us to complete\n"
	.string "the Pokédex too?\p"
	.string "I guess I can beat you in that too.\n"
	.string "Ha!\p"
	.string "Alright, that'll be so easy.\p"
	.string "I stocked up on a bunch of Potions at\n"
	.string "the Pokécenter, I heard that there's a\l"
	.string "cave up ahead.\p"
	.string "Apparently it's some sort of inactive\n"
	.string "lava chamber.\p"
	.string "Whatever, I'm not worried.\p"
	.string "That'll just give my Pokémon some much\n"
	.string "needed training.\p"
	.string "See ya later, slowpoke!$"

RossanoFoothills_Sign_IgnisCave_Text_0:
# 256 "data/maps/Route102/scripts.pory"
	.string "{COLOR LIGHT_GREEN}- Ignis Cave -\n"
	.string "{FONT_SMALL}Inactive Lava Chambers Ahead$"

RossanoFoothills_Sign_RouteSign_Text_0:
# 260 "data/maps/Route102/scripts.pory"
	.string "{COLOR LIGHT_GREEN}- Rossano Foothills -\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} Treviso City\n"
	.string "{DOWN_ARROW} Ignis Cave$"

RossanoFoothills_Object_Boy_Text_0:
# 265 "data/maps/Route102/scripts.pory"
	.string "You can find all sorts of Pokémon\n"
	.string "between cities and towns.\p"
	.string "{COLOR GREEN}Ryoko{COLOR DARK_GREY} has a vast diversity between\n"
	.string "Pokémon in {COLOR GREEN}West Ryoko{COLOR DARK_GREY} and {COLOR GREEN}East Ryoko{COLOR DARK_GREY}.$"

RossanoFoothills_Trainer_BirdKeeper_Text_0:
# 274 "data/maps/Route102/scripts.pory"
	.string "Caw!{PAUSE 16}\n"
	.string "Caw!\p"
	.string "Feathered friends, we have some prey!$"

RossanoFoothills_Trainer_BirdKeeper_Text_1:
# 274 "data/maps/Route102/scripts.pory"
	.string "Caaaw!$"

RossanoFoothills_Trainer_BirdKeeper_Text_2:
# 275 "data/maps/Route102/scripts.pory"
	.string "Caw!{PAUSE 16}\n"
	.string "Caw!\p"
	.string "What do you think of my bird call?$"

RossanoFoothills_Trainer_BugCatcher_Text_0:
# 279 "data/maps/Route102/scripts.pory"
	.string "Have you found any rare bugs?$"

RossanoFoothills_Trainer_BugCatcher_Text_1:
# 279 "data/maps/Route102/scripts.pory"
	.string "Always more critters to find!$"

RossanoFoothills_Trainer_BugCatcher_Text_2:
# 280 "data/maps/Route102/scripts.pory"
	.string "You can find critters all around Ryoko,\n"
	.string "in all sorts and sizes!$"

RossanoFoothills_Trainer_Lass_Text_0:
# 284 "data/maps/Route102/scripts.pory"
	.string "Hey!\n"
	.string "You looked at me funny!$"

RossanoFoothills_Trainer_Lass_Text_1:
# 284 "data/maps/Route102/scripts.pory"
	.string "Okay...\n"
	.string "I saw you first...$"

RossanoFoothills_Trainer_Lass_Text_2:
# 285 "data/maps/Route102/scripts.pory"
	.string "When a trainer sees you, be ready to\n"
	.string "battle!$"

RossanoFoothills_text_RivalDefeat::
# 209 "data/maps/Route102/scripts.pory"
	.string "What?\n"
	.string "I thought I picked the better Pokémon!$"
