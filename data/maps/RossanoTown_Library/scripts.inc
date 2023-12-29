RossanoTown_Library_MapScripts::
# 7 "data/maps/RossanoTown_Library/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RossanoTown_Library_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

RossanoTown_Library_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/RossanoTown_Library/scripts.pory"
	switch VAR_ROSSANO_TOWN_STATE
# 9 "data/maps/RossanoTown_Library/scripts.pory"
	case 1, RossanoTown_Library_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

RossanoTown_Library_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 10 "data/maps/RossanoTown_Library/scripts.pory"
	removeobject 8
	return


RossanoLibrary_Object_Librarian::
# 15 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Librarian_Text_0, MSGBOX_NPC
	end


RossanoLibrary_Object_Artist::
# 19 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 20 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 21 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Artist_Text_0, MSGBOX_AUTOCLOSE
# 22 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
# 23 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_Maniac::
# 27 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 28 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 29 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Maniac_Text_0, MSGBOX_AUTOCLOSE
# 30 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
# 31 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_SchoolKid::
# 35 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 36 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 37 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_SchoolKid_Text_0, MSGBOX_AUTOCLOSE
# 38 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 39 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_LittleBoy::
# 43 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 44 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 45 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_LittleBoy_Text_0, MSGBOX_AUTOCLOSE
# 46 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
# 47 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_Girl::
# 51 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 52 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 53 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Girl_Text_0, MSGBOX_AUTOCLOSE
# 54 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
# 55 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_Woman::
# 59 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 60 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 61 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Woman_Text_0, MSGBOX_AUTOCLOSE
# 62 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 63 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_Chad::
# 67 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 68 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 69 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_Chad_Text_0, MSGBOX_AUTOCLOSE
# 70 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 71 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	end


RossanoLibrary_Object_GruntTakesBook::
# 76 "data/maps/RossanoTown_Library/scripts.pory"
	lock
# 77 "data/maps/RossanoTown_Library/scripts.pory"
	delay 4
# 78 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceUp
# 79 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
# 80 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_GruntTakesBook_Text_0, MSGBOX_AUTOCLOSE
# 81 "data/maps/RossanoTown_Library/scripts.pory"
	delay 8
# 82 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceUp
# 83 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
# 84 "data/maps/RossanoTown_Library/scripts.pory"
	delay 12
# 85 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceUp
# 86 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
# 87 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_GruntTakesBook_Text_1, MSGBOX_AUTOCLOSE
# 88 "data/maps/RossanoTown_Library/scripts.pory"
	delay 8
# 89 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceUp
# 90 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
# 91 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_GruntTakesBook_Text_2, MSGBOX_AUTOCLOSE
# 92 "data/maps/RossanoTown_Library/scripts.pory"
	delay 8
# 93 "data/maps/RossanoTown_Library/scripts.pory"
	faceplayer
# 94 "data/maps/RossanoTown_Library/scripts.pory"
	delay 8
# 95 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 96 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
# 97 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_GruntTakesBook_Text_3, MSGBOX_AUTOCLOSE
# 98 "data/maps/RossanoTown_Library/scripts.pory"
	trainerbattle_no_intro TRAINER_PROTO_GRUNT_1, RossanoLibrary_Object_GruntTakesBook_Text_4
# 99 "data/maps/RossanoTown_Library/scripts.pory"
	msgbox RossanoLibrary_Object_GruntTakesBook_Text_5, MSGBOX_AUTOCLOSE
# 100 "data/maps/RossanoTown_Library/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 101 "data/maps/RossanoTown_Library/scripts.pory"
	compare VAR_TEMP_1, 4
	goto_if_eq RossanoLibrary_Object_GruntTakesBook_2
# 105 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, RossanoLibrary_Movement_GruntTakesBook_1
# 106 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
RossanoLibrary_Object_GruntTakesBook_1:
# 108 "data/maps/RossanoTown_Library/scripts.pory"
	playse SE_EXIT
# 109 "data/maps/RossanoTown_Library/scripts.pory"
	removeobject 8
# 110 "data/maps/RossanoTown_Library/scripts.pory"
	setflag FLAG_ROSSANO_LIBRARY_GRUNT
# 111 "data/maps/RossanoTown_Library/scripts.pory"
	waitse
# 112 "data/maps/RossanoTown_Library/scripts.pory"
	setvar VAR_ROSSANO_TOWN_STATE, 1
# 113 "data/maps/RossanoTown_Library/scripts.pory"
	releaseall
	end

RossanoLibrary_Object_GruntTakesBook_2:
# 102 "data/maps/RossanoTown_Library/scripts.pory"
	applymovement 8, RossanoLibrary_Movement_GruntTakesBook_0
# 103 "data/maps/RossanoTown_Library/scripts.pory"
	waitmovement 0
	goto RossanoLibrary_Object_GruntTakesBook_1


# 116 "data/maps/RossanoTown_Library/scripts.pory"
RossanoLibrary_Movement_GruntTakesBook_0:
# 117 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 118 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_down
# 118 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_down
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 119 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 120 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_up
# 120 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_up
# 121 "data/maps/RossanoTown_Library/scripts.pory"
	walk_in_place_left
	step_end

# 123 "data/maps/RossanoTown_Library/scripts.pory"
RossanoLibrary_Movement_GruntTakesBook_1:
# 124 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_down
# 124 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_down
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 125 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_right
# 126 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_up
# 126 "data/maps/RossanoTown_Library/scripts.pory"
	walk_fast_up
# 127 "data/maps/RossanoTown_Library/scripts.pory"
	walk_in_place_left
	step_end

RossanoLibrary_Object_Librarian_Text_0:
# 15 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR RED}Welcome to the {COLOR GREEN}Rossano Library{COLOR RED}.\p"
	.string "Please feel free to indulge yourself in\n"
	.string "our fine selection of books!\p"
	.string "And please stay quiet.$"

RossanoLibrary_Object_Artist_Text_0:
# 21 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR RED}I'm trying to find a book about modern\n"
	.string "art...\p"
	.string "Maybe I should go to a museum.$"

RossanoLibrary_Object_Maniac_Text_0:
# 29 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR BLUE}Have you ever heard of\n"
	.string "psuedo-science?\p"
	.string "It's fascinating!\p"
	.string "I wonder why other scientists don't\n"
	.string "talk about these breakthroughs in\l"
	.string "modern medicine.$"

RossanoLibrary_Object_SchoolKid_Text_0:
# 37 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR BLUE}I come here to study for school.\p"
	.string "It's a lot quieter than my home.$"

RossanoLibrary_Object_LittleBoy_Text_0:
# 45 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR BLUE}I can't reach the top shelf!$"

RossanoLibrary_Object_Girl_Text_0:
# 53 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR RED}Horticulture books are abundant here!\p"
	.string "I love learning ways to mantain my\n"
	.string "garden.$"

RossanoLibrary_Object_Woman_Text_0:
# 61 "data/maps/RossanoTown_Library/scripts.pory"
	.string "{COLOR RED}I can't focus with this guy across the\n"
	.string "table...\p"
	.string "But the kid downstairs is super\n"
	.string "annoying.\p"
	.string "Ugh.$"

RossanoLibrary_Object_Chad_Text_0:
# 69 "data/maps/RossanoTown_Library/scripts.pory"
	.string "Chad: {COLOR BLUE}I once read that the Unova\n"
	.string "region's Subway system truly tests\l"
	.string "your battle skills.\p"
	.string "Perhaps I will visit one day..$"

RossanoLibrary_Object_GruntTakesBook_Text_0:
# 80 "data/maps/RossanoTown_Library/scripts.pory"
	.string "???: {COLOR BLUE}{FONT_SMALL}Which book is it...$"

RossanoLibrary_Object_GruntTakesBook_Text_1:
# 87 "data/maps/RossanoTown_Library/scripts.pory"
	.string "???: {COLOR BLUE}{FONT_SMALL}All of these books are dusty!$"

RossanoLibrary_Object_GruntTakesBook_Text_2:
# 91 "data/maps/RossanoTown_Library/scripts.pory"
	.string "???: {COLOR BLUE}Ah-ha!\n"
	.string "Found it!$"

RossanoLibrary_Object_GruntTakesBook_Text_3:
# 97 "data/maps/RossanoTown_Library/scripts.pory"
	.string "???: {COLOR BLUE}H{PAUSE 5}-{PAUSE 10}Hey kid!\n"
	.string "Nothin' to see here!\p"
	.string "I'm not stealin' anything!\p"
	.string "{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.\n"
	.string "{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.{PAUSE 10}.\p"
	.string "Okay!\n"
	.string "Fine!\p"
	.string "You caught me stealin'!\p"
	.string "But you're not tellin' anyone!$"

RossanoLibrary_Object_GruntTakesBook_Text_4:
# 98 "data/maps/RossanoTown_Library/scripts.pory"
	.string "Drats!\p"
	.string "Boss ain't gonna be happy about this\n"
	.string "ruckus...$"

RossanoLibrary_Object_GruntTakesBook_Text_5:
# 99 "data/maps/RossanoTown_Library/scripts.pory"
	.string "???: {COLOR BLUE}Oh great,\n"
	.string "Boss ain't gonna be happy...\p"
	.string "You didn't see nothin' kid!$"
