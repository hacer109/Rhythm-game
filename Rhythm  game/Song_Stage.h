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
	
	
	
	std::string songName;
	std::vector<PlayNote> notes;
	vector<PlayNote> spawnNotes;
	NoteSpawner spawner;
	NoteSpawner spawner2;
	NoteSpawner spawner3;
	NoteSpawner spawner4;

	NoteSpawner spawner5;
	NoteSpawner spawner6;
	NoteSpawner spawner7;
	NoteSpawner spawner8;

	Conductor conductor;
	Camera2D camera = {0};
	Vector2 target = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
	Vector2 offset = {GetScreenWidth()/2.0f,GetScreenHeight()/2.0f};
	float zoom = 1.0f;

	Image city, street, sky, behindTrain, win;
	Texture2D city1, street1, sky1, behindTrain1, win1;


	//120 x
	 //int offset = 120;
	 int bx=50;
	 int b2x = 850;
	 int bsY = 50;

	PlayerButton button  = PlayerButton(b2x    , bsY, -44, "assets/images/NOTE_assets", "left confirm instance 1", "left press instance 1", "arrow static instance 4", 24);
	PlayerButton button1 = PlayerButton(b2x+120, bsY, -44, "assets/images/NOTE_assets", "down confirm instance 1", "down press instance 1", "arrow static instance 3", 24);
	PlayerButton button2 = PlayerButton(b2x+240, bsY, -44, "assets/images/NOTE_assets", "up confirm instance 1", "up press instance 1", "arrow static instance 2", 24);
	PlayerButton button3 = PlayerButton(b2x+360, bsY, -44, "assets/images/NOTE_assets", "right confirm instance 1", "right press instance 1", "arrow static instance 1", 24);


	PlayerButton button4 = PlayerButton(bx,       bsY, -44, "assets/images/NOTE_assets", "left confirm instance 1", "left press instance 1", "arrow static instance 4", 24);
	PlayerButton button5 = PlayerButton(bx + 120, bsY, -44, "assets/images/NOTE_assets", "down confirm instance 1", "down press instance 1", "arrow static instance 3", 24);
	PlayerButton button6 = PlayerButton(bx + 240, bsY, -44, "assets/images/NOTE_assets", "up confirm instance 1", "up press instance 1", "arrow static instance 2", 24);
	PlayerButton button7 = PlayerButton(bx + 360, bsY, -44, "assets/images/NOTE_assets", "right confirm instance 1", "right press instance 1", "arrow static instance 1", 24);



	Song_Stage()
	{

	}
	Song_Stage(string songName): songName(songName)
	{
		
		 city =     LoadImage("assets/images/city.png");
		   street = LoadImage("assets/images/street.png");
		sky =       LoadImage("assets/images/sky.png");
	  behindTrain = LoadImage("assets/images/behindTrain.png");
		      win = LoadImage("assets/images/win4.png");

		city1 = LoadTextureFromImage(city);
		street1 = LoadTextureFromImage(street);
		sky1 = LoadTextureFromImage(sky);
		behindTrain1 = LoadTextureFromImage(behindTrain);
		win1 = LoadTextureFromImage(win);


		LoadSong(songName);
		
		camera.target = target;
		camera.rotation = 0.0f;
		camera.zoom = zoom;
		camera.offset = offset;


	/*	UnloadImage(city);
		UnloadImage(behindTrain);
		UnloadImage(sky);
		UnloadImage(street);
		UnloadImage(win);*/


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
		spawner = NoteSpawner(spawnNotes, &conductor, 0, 0,zoom,bsY,2.5,false);
		spawner2 = NoteSpawner(spawnNotes, &conductor, 1, 0, zoom, bsY, 2.5,false);
		spawner3 = NoteSpawner(spawnNotes, &conductor, 2, 0, zoom, bsY, 2.5,false);
		spawner4 = NoteSpawner(spawnNotes, &conductor, 3, 0, zoom, bsY, 2.5,false);

		spawner5 = NoteSpawner(spawnNotes, &conductor, 4, 0, zoom, bsY, 2.5,true);
		spawner6 = NoteSpawner(spawnNotes, &conductor, 5, 0, zoom, bsY, 2.5,true);
		spawner7 = NoteSpawner(spawnNotes, &conductor, 6, 0, zoom, bsY, 2.5,true);
		spawner8 = NoteSpawner(spawnNotes, &conductor, 7, 0, zoom, bsY, 2.5,true);

		conductor = Conductor("assets/sound/Philly_Nice.mp3", BPM);
		
	}


	 
	float siz = 44;
	void SongStageUpdate() {

		
		BeginMode2D(camera);
		camera.rotation = 0.0f;
		camera.zoom = zoom;
		camera.offset = offset;
		if (IsKeyReleased(KEY_N))zoom += 0.1f;
		if (IsKeyReleased(KEY_M))zoom -= 0.1f;
		DrawRectangle(500, 500, 200, 200, RED);
		if (IsKeyDown(KEY_UP))target.y += 10;
		if (IsKeyDown(KEY_DOWN))target.y -= 10;
		if (IsKeyDown(KEY_LEFT))target.x += 10;
		if (IsKeyDown(KEY_RIGHT))target.x -= 10;
		Rectangle fa = { 0, 0,1729,955 };
		DrawTexturePro(sky1, fa,fa,{0,0},0,WHITE);
		DrawTexturePro(city1, fa, fa, { 0,0 }, 0, WHITE);
		DrawTexturePro(win1, fa, fa, { 0,0 }, 0, WHITE);
		DrawTexturePro(behindTrain1, fa, fa, { 0,0 }, 0, WHITE);
		DrawTexturePro(street1, fa, fa, { 0,0 }, 0, WHITE);
		DrawTexture(sky1, 50, 50, WHITE);
		
		ImageDraw(&sky, sky, fa, fa, WHITE);
		camera.target = target;
		EndMode2D();
		conductor.ConductorUpdate();
		
		if (IsKeyReleased(KEY_SPACE))conductor.isPaused = !conductor.isPaused;
		

		
		button.UpdatePlayerButton();
		button2.UpdatePlayerButton();
		button3.UpdatePlayerButton();
		button1.UpdatePlayerButton();

		button4.UpdatePlayerButton();
		button5.UpdatePlayerButton();
		button6.UpdatePlayerButton();
		button7.UpdatePlayerButton();

		spawner.SpawnerUpdate();
		spawner2.SpawnerUpdate();
		spawner3.SpawnerUpdate();
		spawner4.SpawnerUpdate();

		spawner5.SpawnerUpdate();
		spawner6.SpawnerUpdate();
		spawner7.SpawnerUpdate();
		spawner8.SpawnerUpdate();

		//if (IsKeyReleased(KEY_J))siz -= 10;
	//	if (IsKeyReleased(KEY_K))siz += 10;
		spawner.size = siz;
		spawner2.size = siz;
		spawner3.size = siz;
		spawner4.size = siz;

		spawner5.size = siz;
		spawner6.size = siz;
		spawner7.size = siz;
		spawner8.size = siz;
		
		
		
		spawner.x = bx;
		spawner2.x = bx+120;
		spawner3.x = bx+240;
		spawner4.x = bx+360;

		spawner5.x = b2x;
		spawner6.x = b2x + 120;
		spawner7.x = b2x + 240;
		spawner8.x = b2x + 360;

		int y = bsY;
		//DrawRectangle(540, bsY, 500, 10, RED);
		spawner.y = y;
		spawner2.y = y;
		spawner3.y = y;
		spawner4.y = y;
		
		spawner5.y = y;
		spawner6.y = y;
		spawner7.y = y;
		spawner8.y = y;
	

		//this code here is pure cancer but im testing so stfu
		if (IsKeyDown(KEY_D)) {

		
			button.animState = spawner.teeeeee;

		}
		else {
			button.animState = 0;
		}

		if (IsKeyDown(KEY_F)) {


			button1.animState = spawner2.teeeeee;

		}
		else {
			button1.animState = 0;
		}

		if (IsKeyDown(KEY_J)) {


			button2.animState = spawner3.teeeeee;

		}
		else {
			button2.animState = 0;
		}

		if (IsKeyDown(KEY_K)) {


			button3.animState = spawner4.teeeeee;

		}
		else {
			button3.animState = 0;
		}
		//std::cout << spawner.spawnNotes.size() << std::endl;
		
		
	}

	
};

