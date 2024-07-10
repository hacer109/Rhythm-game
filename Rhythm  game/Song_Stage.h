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
	
	std::string songName;
	std::vector<PlayNote> notes;
	vector<PlayNote> spawnNotes;
	NoteSpawner spawner;
	NoteSpawner spawner2;
	NoteSpawner spawner3;
	NoteSpawner spawner4;
	Conductor conductor;
	Camera2D camera = {0};
	Vector2 target = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
	Vector2 offset = {GetScreenWidth()/2.0f,GetScreenHeight()/2.0f};
	float zoom = 1.0f;

	Song_Stage()
	{

	}
	Song_Stage(string songName): songName(songName)
	{
		LoadSong(songName);
		
		camera.target = target;
		camera.rotation = 0.0f;
		camera.zoom = zoom;
		camera.offset = offset;

	}

	void LoadSong(std::string name){
	
		string a = "assets/Chart_Data/"+name+".json";
		ifstream inputFile(a);
		if (!inputFile) {

			cout << "failed to open file,please put  the properly structured json file" << endl;
		}
		else {



		}

		nlohmann::json Jasondata;
		inputFile >> Jasondata;
		inputFile.close();

		vector<PlayNote> data;
		float BPM;
		string path;
		for (const auto& entry : Jasondata) {
			PlayNote note;
	

			note.sectionId = entry["sectionID"];
			note.corridor = entry["corridor"];
			note.length = entry["length"];
			note.timeToHit = entry["timeToHit"];
			note.offset = entry["offset"];
			conductor.SetBPM(entry["BPM"]);
			BPM = entry["BPM"];
			path = entry["songPath"];
			data.push_back(note);

		}

		
		notes = data;
		spawnNotes = notes;
	//	conductor.songBpm = BPM;
		spawner = NoteSpawner(spawnNotes, &conductor, 0, 0,zoom,500);
		spawner2 = NoteSpawner(spawnNotes, &conductor, 1, 0, zoom, 700);
		spawner3 = NoteSpawner(spawnNotes, &conductor, 2, 0, zoom, 900);
		spawner4 = NoteSpawner(spawnNotes, &conductor, 3, 0, zoom, 1100);
		conductor = Conductor("assets/sound/Philly_Nice.mp3", BPM);
	}


	 

	void SongStageUpdate() {

		
		BeginMode2D(camera);
		camera.rotation = 0.0f;
		camera.zoom = zoom;
		camera.offset = offset;
		if (IsKeyReleased(KEY_A))zoom += 1.0f;
		if (IsKeyReleased(KEY_D))zoom -= 1.0f;
		DrawRectangle(500, 500, 200, 200, RED);
		if (IsKeyReleased(KEY_UP))target.y += 10;
		if (IsKeyReleased(KEY_DOWN))target.y -= 10;
		if (IsKeyReleased(KEY_LEFT))target.x += 10;
		if (IsKeyReleased(KEY_RIGHT))target.x -= 10;
		camera.target = target;
		EndMode2D();
		conductor.ConductorUpdate();
		
		if (IsKeyReleased(KEY_SPACE))conductor.isPaused = !conductor.isPaused;
		spawner.SpawnerUpdate();
		spawner2.SpawnerUpdate();
		spawner3.SpawnerUpdate();
		spawner4.SpawnerUpdate();

		
		


		spawner.size = 1;
		
		
		
		spawner.x = 500;
		spawner2.x = 700;
		spawner3.x = 900;
		spawner4.x = 1100;



		spawner.y = 360;
		spawner2.y = 360;
		spawner3.y = 360;
		spawner4.y = 360;
		
		
		//std::cout << zoom << std::endl;
		
		
	}

	
};

