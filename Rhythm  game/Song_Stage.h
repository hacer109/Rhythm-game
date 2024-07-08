#pragma once
#include <iostream>
#include <raylib.h>
#include "Character_song.h"
#include "PlayerButton.h"
#include <vector>
#include "Custom_Containers.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include "Conductor.h"
#include "NoteSpawner.h"

using namespace std;
class Song_Stage
{
public:


	//Character_song bf = Character_song(500,0,1,"assets/images/BOYFRIEND","BF NOTE UP0","BF NOTE DOWN0", "BF NOTE LEFT0", "BF NOTE RIGHT0", "BF idle dance0", 24);
	
/*	PlayerButton button = PlayerButton(100, 100, 1, "assets/images/NOTE_assets", "left confirm instance", "left press instance 1", "arrow static instance 1", 24);
	PlayerButton button1 = PlayerButton(300, 100, 1, "assets/images/NOTE_assets", "down confirm instance", "down press instance 1", "arrow static instance 2", 24);
	PlayerButton button2 = PlayerButton(500, 100, 1, "assets/images/NOTE_assets", "up confirm instance", "up press instance 1", "arrow static instance 4", 24);
	PlayerButton button3 = PlayerButton(700, 100, 1, "assets/images/NOTE_assets", "right confirm instance", "right press instance 1", "arrow static instance 3", 24);*/
	Conductor conductor;
	std::string songName;
	std::vector<PlayNote> notes;
	vector<PlayNote> spawnNotes;
	NoteSpawner spawner = NoteSpawner(spawnNotes, &conductor,1);
	Song_Stage()
	{

	}
	Song_Stage(string songName): songName(songName)
	{
		LoadSong(songName);
	}

	void LoadSong(std::string name){
	
		string a = "assets/Chart_Data/" + name;
		ifstream inputFile(a);
		if (!inputFile) {

			cerr << "failed to open file,please put  the properly structured json file" << endl;
		}
		else {



		}

		nlohmann::json Jasondata;
		inputFile >> Jasondata;
		inputFile.close();

		vector<PlayNote> data;
		float BPM;
		
		for (const auto& entry : Jasondata) {
			PlayNote note;
	

			note.sectionId = entry["sectionID"];
			note.corridor = entry["corridor"];
			note.length = entry["length"];
			note.timeToHit = entry["timeToHit"];
			note.offset = entry["offset"];
			conductor.SetBPM(entry["BPM"]);
			BPM = entry["BPM"];
			data.push_back(note);

		}

		
		notes = data;
		spawnNotes = notes;
		conductor = Conductor(a, BPM);
	
	}




	void SongStageUpdate() {



		conductor.ConductorUpdate();





		/*

		if (IsKeyDown(KEY_F))button1.animState = 1;
		else button1.animState = 0;
		if (IsKeyDown(KEY_J))button2.animState = 1;
		else button2.animState = 0;
		if (IsKeyDown(KEY_K))button3.animState = 1;
		else button3.animState = 0;
		button.UpdatePlayerButton();
		button1.UpdatePlayerButton();
		button2.UpdatePlayerButton();
		button3.UpdatePlayerButton();*/
		

	}

	
};

