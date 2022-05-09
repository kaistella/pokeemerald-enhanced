UnifiedCave_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, UnifiedCave_Entrance_OnResume
	.byte 0

UnifiedCave_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_UNIFIED_CAVE, 9, 6
	setescapewarp MAP_UNDERWATER_UNIFIED_CAVE, 9, 6
	end