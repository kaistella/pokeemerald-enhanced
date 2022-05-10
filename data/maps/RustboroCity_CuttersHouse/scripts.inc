RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_MACHETE
	setflag FLAG_RECEIVED_HM01
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "MACHETE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_Gym_Text_ExplainMachete:
	.string "This MACHETE is capable\n"
	.string "of cutting down small trees.\p"
	.string "It can let you get to places\n"
	.string "that you couldn't reach before!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That MACHETE is capable of\n"
	.string "chopping down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"

