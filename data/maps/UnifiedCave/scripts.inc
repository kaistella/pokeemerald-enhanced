.set LOCALID_ZYGARDE, 1

UnifiedCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, UnifiedCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, UnifiedCave_OnTransition
	.byte 0

UnifiedCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, UnifiedCave_EventScript_TryRemoveZygarde
	end

UnifiedCave_EventScript_TryRemoveZygarde::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Common_EventScript_NopReturn
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

UnifiedCave_OnTransition:
	call_if_unset FLAG_DEFEATED_ZYGARDE, UnifiedCave_EventScript_ShowZygarde
	end

UnifiedCave_EventScript_ShowZygarde::
	clearflag FLAG_HIDE_ZYGARDE
	return

UnifiedCave_EventScript_Zygarde::
	lockall
	waitse
	playmoncry SPECIES_ZYGARDE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZYGARDE, 30
	setvar VAR_LAST_TALKED, LOCALID_ZYGARDE
	setvar VAR_0x8009, SPECIES_ZYGARDE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, UnifiedCave_EventScript_CaughtZygarde
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, UnifiedCave_EventScript_DefeatedZygarde
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnifiedCave_EventScript_RanFromZygarde
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, UnifiedCave_EventScript_RanFromZygarde
	end

UnifiedCave_EventScript_CaughtZygarde::
	setflag FLAG_DEFEATED_ZYGARDE
	goto UnifiedCave_EventScript_CaughtZygardeText
	end

UnifiedCave_EventScript_CaughtZygardeText::
	msgbox UnifiedCave_Text_CaughtZygarde, MSGBOX_AUTOCLOSE
	end

UnifiedCave_Text_CaughtZygarde::
	.string "The Zygarde was caught.$"
	end

UnifiedCave_EventScript_DefeatedZygarde::
	setflag FLAG_DEFEATED_ZYGARDE
	goto UnifiedCave_EventScript_DefeatedZygardeText
	end

UnifiedCave_EventScript_DefeatedZygardeText::
	msgbox UnifiedCave_Text_DefeatedZygarde, MSGBOX_AUTOCLOSE
	end

UnifiedCave_Text_DefeatedZygarde::
	.string "The Zygarde was defeated.$"
	end

UnifiedCave_EventScript_RanFromZygarde::
	msgbox UnifiedCave_Text_RanFromZygarde, MSGBOX_AUTOCLOSE
	end

UnifiedCave_EventScript_RanFromZygardeText::
	msgbox UnifiedCave_Text_RanFromZygarde, MSGBOX_AUTOCLOSE
	end

UnifiedCave_Text_RanFromZygarde::
	.string "You decided to battle the Zygarde later.$"
	end