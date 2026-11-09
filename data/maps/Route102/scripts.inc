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

RossanoFoothills_Sign_IgnisCave::
# 115 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Sign_IgnisCave_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


RossanoFoothills_Sign_RouteSign::
# 119 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Sign_RouteSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


RossanoFoothills_Object_Boy::
# 124 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Object_Boy_Text_0, MSGBOX_NPC
	end


RossanoFoothills_ItemBall_HyperPotion::
# 128 "data/maps/Route102/scripts.pory"
	finditem ITEM_HYPER_POTION
	end


RossanoFoothills_Trainer_BirdKeeper::
# 133 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BIRDKEEPER_CICERO, RossanoFoothills_Trainer_BirdKeeper_Text_0, RossanoFoothills_Trainer_BirdKeeper_Text_1
# 134 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_BirdKeeper_Text_2, MSGBOX_NPC
	end


RossanoFoothills_Trainer_BugCatcher::
# 138 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BUGCATCHER_GABRIEL, RossanoFoothills_Trainer_BugCatcher_Text_0, RossanoFoothills_Trainer_BugCatcher_Text_1
# 139 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_BugCatcher_Text_2, MSGBOX_NPC
	end


RossanoFoothills_Trainer_Lass::
# 143 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_LASS_ELENA, RossanoFoothills_Trainer_Lass_Text_0, RossanoFoothills_Trainer_Lass_Text_1
# 144 "data/maps/Route102/scripts.pory"
	msgbox RossanoFoothills_Trainer_Lass_Text_2, MSGBOX_NPC
	end


RossanoFoothills_Sign_IgnisCave_Text_0:
# 115 "data/maps/Route102/scripts.pory"
	.string "{COLOR LIGHT_GREEN}Ignis Cave$"

RossanoFoothills_Sign_RouteSign_Text_0:
# 119 "data/maps/Route102/scripts.pory"
	.string "{COLOR LIGHT_GREEN}Rossano Foothills\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} Treviso City\n"
	.string "{DOWN_ARROW} Ignis Cave$"

RossanoFoothills_Object_Boy_Text_0:
# 124 "data/maps/Route102/scripts.pory"
	.string "{COLOR BLUE}You can find all sorts of Pokémon\n"
	.string "between cities and towns.\p"
	.string "{COLOR GREEN}Ryoko{COLOR BLUE} has a vast diversity between\n"
	.string "Pokémon in {COLOR GREEN}West Ryoko{COLOR BLUE} and {COLOR GREEN}East Ryoko{COLOR BLUE}.$"

RossanoFoothills_Trainer_BirdKeeper_Text_0:
# 133 "data/maps/Route102/scripts.pory"
	.string "{COLOR BLUE}Me and my birds have the highground!$"

RossanoFoothills_Trainer_BirdKeeper_Text_1:
# 133 "data/maps/Route102/scripts.pory"
	.string "It's over!\n"
	.string "The highground wasn't enough!$"

RossanoFoothills_Trainer_BirdKeeper_Text_2:
# 134 "data/maps/Route102/scripts.pory"
	.string "{COLOR BLUE}If a Pokémon has wings, it's my\n"
	.string "favorite!$"

RossanoFoothills_Trainer_BugCatcher_Text_0:
# 138 "data/maps/Route102/scripts.pory"
	.string "{COLOR BLUE}I love looking for little critters in the\n"
	.string "wild.$"

RossanoFoothills_Trainer_BugCatcher_Text_1:
# 138 "data/maps/Route102/scripts.pory"
	.string "Always more critters to find!$"

RossanoFoothills_Trainer_BugCatcher_Text_2:
# 139 "data/maps/Route102/scripts.pory"
	.string "{COLOR BLUE}You can find critters all around Ryoko,\n"
	.string "in all sorts and sizes!$"

RossanoFoothills_Trainer_Lass_Text_0:
# 143 "data/maps/Route102/scripts.pory"
	.string "{COLOR RED}Hey!\n"
	.string "You looked at me!$"

RossanoFoothills_Trainer_Lass_Text_1:
# 143 "data/maps/Route102/scripts.pory"
	.string "Okay...\n"
	.string "I saw you first...$"

RossanoFoothills_Trainer_Lass_Text_2:
# 144 "data/maps/Route102/scripts.pory"
	.string "{COLOR RED}When a trainer sees you, be ready to\n"
	.string "battle!$"
