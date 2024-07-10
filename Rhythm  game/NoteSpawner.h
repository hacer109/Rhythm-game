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

using namespace std;



class Note {
public:



    PlayNote note;
    int stepTime;
    bool played =false;
    float timeInstanciate;
    int x,speed;
    float initialY;
    int y;
    int size;
    Conductor* cond;
    Image image;
    Texture2D textures;
    int targetY = GetScreenHeight()-150;
    Rectangle frameRec;
    Rectangle pos;
        
    Note(PlayNote note,int stepTime,Conductor* condu,int x,int y): y(y),note(note),stepTime(stepTime),cond(condu),x(x)
    {
        

        image = LoadImage("assets/images/notes.png");
            textures = LoadTextureFromImage(image);
            UnloadImage(image);

            switch (note.corridor) {

            case 0 :

                frameRec = { 0,246,154,157 };

                break;

            case 1 :

                frameRec = { 0,0,157,154 };
                break;

            case 2 :

                frameRec = { 249,0,157,154 };
                break;

            case 3 :

                frameRec = { 246,246,154,157 };
                break;

            case  4:

                frameRec = { 0,246,154,157 };

                break;

            case  5:

                frameRec = { 0,0,157,154 };
                break;

            case 6:

                frameRec = { 249,0,157,154 };
                break;

            case  7:

                frameRec = { 246,246,154,157 };
                break;



            }

    }




    void DrawNote() {

        float inverseZoom = float(size);
        Vector2 origin = { 0,0 };
        pos.x = x;
        pos.y = y;
        pos.width = float(frameRec.width * inverseZoom);
        pos.height = float(frameRec.height * inverseZoom);
        DrawTexturePro(textures, frameRec, pos, origin, 0, WHITE);

    }


    void noteUpdate() {

        
        speed = 2;
       // y = initialY + (speed * (cond->songPosition - note.timeToHit));

      //  float traveltime = 4 * cond->secPerBeat;
        float noteSize = (size * 10);
      //  y = targetY - (0.1f/traveltime) *targetY
        float a = (16*16*12) / (cond->stepLengthInSeconds*16) ;//12

        y = (targetY - ((cond->songPosition - note.timeToHit) * (0.45 * speed))*a);//find a num to multiply,calculate the screen to world ratio



        if (cond->songPosition > note.timeToHit) played = true;
        DrawNote();
        
        
    }

    ~Note()
    {
        std::cout << "DESTROED NOTE" << std::endl;
    }


};


class NoteSpawner
{
public:


        vector<PlayNote> notes;
        Conductor* conductor;
        int corridor;
        vector<Note> spawnNotes;
        int x,size,y;


    NoteSpawner()
    {

    }
	NoteSpawner(vector<PlayNote> spawnNote,Conductor* conductor,int corridor, int x,int size,int y):y(y),size(size), corridor(corridor), conductor(conductor), notes(spawnNote), x(x)
	{
        AssignChartNotes(notes, conductor);
        
        


	}

    void AssignChartNotes(vector<PlayNote> data,Conductor* conductor) {

        for (int i = 0; i < data.size();i++) {
            if (data[i].corridor == corridor) {

                int idY = data[i].timeToHit / conductor->stepLengthInSeconds;
                
                spawnNotes.push_back(Note(data[i],idY,conductor,x,y));

            }
        }
    }

    void SpawnerUpdate() {

        for (int i = 0; i < spawnNotes.size();i++) {


            //if(!spawnNotes[i].played)
            spawnNotes[i].noteUpdate();
            spawnNotes[i].size = size;
            spawnNotes[i].x = x;
            spawnNotes[i].initialY = y;
            spawnNotes[i].speed = 2.5;
            spawnNotes[i].targetY = y+ (GetScreenHeight()/2.0f);

        }


        std::cout << spawnNotes.size() << std::endl;



    }
};

