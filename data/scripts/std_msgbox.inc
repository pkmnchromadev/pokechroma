Std_MsgboxNPC:
	lock
	faceplayer
	setmessagebox 0x1 0x2
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign:
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	lockall
	setmessagebox 0x1 0x2
	message NULL
	waitmessage
	waitbuttonpress
	releaseall
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Std_MsgboxDefault:
	setmessagebox 0x1 0x2
	message NULL
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	setmessagebox 0x1 0x2
	message NULL
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints:
	setmessagebox 0x1 0x2
	message NULL
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

@ Never used, pokenavcall is always used directly instead
Std_MsgboxPokenav:
	pokenavcall NULL
	waitmessage
	return

EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	waitstate
	return
