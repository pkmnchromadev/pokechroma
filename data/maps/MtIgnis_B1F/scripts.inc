MtIgnis_B1F_MapScripts::
	.byte 0


IgnisCaveB1F_Trainer_Hiker::
# 4 "data/maps/MtIgnis_B1F/scripts.pory"
	trainerbattle_single TRAINER_HIKER_JONATHAN, IgnisCaveB1F_Trainer_Hiker_Text_0, IgnisCaveB1F_Trainer_Hiker_Text_1
# 5 "data/maps/MtIgnis_B1F/scripts.pory"
	msgbox IgnisCaveB1F_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


IgnisCaveB1F_Trainer_BlackBelt::
# 9 "data/maps/MtIgnis_B1F/scripts.pory"
	trainerbattle_single TRAINER_BLACKBELT_JACKSON, IgnisCaveB1F_Trainer_BlackBelt_Text_0, IgnisCaveB1F_Trainer_BlackBelt_Text_1
# 10 "data/maps/MtIgnis_B1F/scripts.pory"
	msgbox IgnisCaveB1F_Trainer_BlackBelt_Text_2, MSGBOX_NPC
	end


IgnisCaveB1F_Trainer_Hiker_Text_0:
# 4 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}It's dark down here, isn't it?$"

IgnisCaveB1F_Trainer_Hiker_Text_1:
# 4 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "Bright enough to fight!$"

IgnisCaveB1F_Trainer_Hiker_Text_2:
# 5 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}The caverns below get even darker.$"

IgnisCaveB1F_Trainer_BlackBelt_Text_0:
# 9 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}Did I catch you off guard?$"

IgnisCaveB1F_Trainer_BlackBelt_Text_1:
# 9 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "Well played!$"

IgnisCaveB1F_Trainer_BlackBelt_Text_2:
# 10 "data/maps/MtIgnis_B1F/scripts.pory"
	.string "{COLOR BLUE}Always stay on guard, you never know\n"
	.string "when something is lurking.$"
