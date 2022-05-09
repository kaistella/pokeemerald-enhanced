Underwater_UnifiedCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_UnifiedCave_OnResume
	.byte 0

Underwater_UnifiedCave_OnResume:
	setdivewarp MAP_UNIFIED_CAVE_ENTRANCE, 10, 17
	end
