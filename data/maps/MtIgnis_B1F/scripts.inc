MtIgnis_B1F_MapScripts::
# 2 "data/maps/MtIgnis_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtIgnis_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MtIgnis_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/MtIgnis_B1F/scripts.pory"
	setflashlevel 3
	return


IgnisCaveB1F_Trainer_Hiker::
# 8 "data/maps/MtIgnis_B1F/scripts.pory"
	trainerbattle_single TRAINER_HIKER_JONATHAN, IgnisCaveB1F_Trainer_Hiker_Text_0, IgnisCaveB1F_Trainer_Hiker_Text_1
# 9 "data/maps/MtIgnis_B1F/scripts.pory"
	msgbox IgnisCaveB1F_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


IgnisCaveB1F_Trainer_BlackBelt::
# 13 "data/maps/MtIgnis_B1F/scripts.pory"
	trainerbattle_single TRAINER_BLACKBELT_JACKSON, IgnisCaveB1F_Trainer_BlackBelt_Text_0, IgnisCaveB1F_Trainer_BlackBelt_Text_1
# 14 "data/maps/MtIgnis_B1F/scripts.pory"
	msgbox IgnisCaveB1F_Trainer_BlackBelt_Text_2, MSGBOX_NPC
	end


IgnisCaveB1F_ItemBall_FireStone::
# 18 "data/maps/MtIgnis_B1F/scripts.pory"
	finditem ITEM_FIRE_STONE
	end


IgnisCaveB1F_Trainer_Hiker_Text_0:
# 8 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}It's dark down here, isn't it?$"

IgnisCaveB1F_Trainer_Hiker_Text_1:
# 8 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "Bright enough to fight!$"

IgnisCaveB1F_Trainer_Hiker_Text_2:
# 9 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "The caverns below get even darker.$"

IgnisCaveB1F_Trainer_BlackBelt_Text_0:
# 13 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}Did I catch you off guard?$"

IgnisCaveB1F_Trainer_BlackBelt_Text_1:
# 13 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "Well played!$"

IgnisCaveB1F_Trainer_BlackBelt_Text_2:
# 14 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "Always stay on guard, you never know\n"
	.string "when something is lurking.$"
