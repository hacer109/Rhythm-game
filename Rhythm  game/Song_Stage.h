#pragma once
#include <iostream>
#include <raylib.h>
#include "Character_song.h"
#include "PlayerButton.h"
class Song_Stage
{
public:


	//Character_song bf = Character_song(500,0,1,"assets/images/BOYFRIEND","BF NOTE UP0","BF NOTE DOWN0", "BF NOTE LEFT0", "BF NOTE RIGHT0", "BF idle dance0", 24);
	
	PlayerButton button = PlayerButton(100,100, 1, "assets/images/NOTE_assets", "left confirm instance", "left press instance 1", "arrow static instance 1", 24);
	PlayerButton button1 = PlayerButton(300, 100, 1, "assets/images/NOTE_assets", "down confirm instance", "down press instance 1", "arrow static instance 2", 24);
	PlayerButton button2 = PlayerButton(500, 100, 1, "assets/images/NOTE_assets", "up confirm instance", "up press instance 1", "arrow static instance 4", 24);
	PlayerButton button3 = PlayerButton(700, 100, 1, "assets/images/NOTE_assets", "right confirm instance", "right press instance 1", "arrow static instance 3", 24);
	void SongStageUpdate() {

		if (IsKeyDown(KEY_D))button.animState = 1;
		else button.animState = 0;
		/*else if (IsKeyDown(KEY_F)) bf.animState = 1;
		else if (IsKeyDown(KEY_J))bf.animState = 2;
		else if (IsKeyDown(KEY_K))bf.animState = 3;
		else bf.animState = 4;
		bf.characterUpdate();
		*/

		if (IsKeyDown(KEY_F))button1.animState = 1;
		else button1.animState = 0;
		if (IsKeyDown(KEY_J))button2.animState = 1;
		else button2.animState = 0;
		if (IsKeyDown(KEY_K))button3.animState = 1;
		else button3.animState = 0;
		button.UpdatePlayerButton();
		button1.UpdatePlayerButton();
		button2.UpdatePlayerButton();
		button3.UpdatePlayerButton();
		

	}

	
};

