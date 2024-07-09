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
    Conductor* cond;
    Image image;
    Texture2D textures;
        
    Rectangle frameRec;
    Rectangle pos;
        
    Note(PlayNote note,int stepTime,Conductor* condu,int x): note(note),stepTime(stepTime),cond(condu),x(x)
    {
        initialY = 0;

        image = LoadImage("assets/images/notes.png");
            textures = LoadTextureFromImage(image);
            UnloadImage(image);

            switch (note.corridor) {

            case 0 | 4:

                frameRec = { 0,246,154,157 };

                break;

            case 1 | 5:

                frameRec = { 0,0,157,154 };
                break;

            case 2 | 6:

                frameRec = { 249,0,157,154 };
                break;

            case 3 | 7:

                frameRec = { 246,246,154,157 };
                break;



            }

    }




    void DrawNote() {

        Vector2 origin = { 0,0 };
        pos.x = x;
        pos.y = y;
        pos.width = frameRec.width*0.5;
        pos.height = frameRec.height*0.5;
        DrawTexturePro(textures, frameRec, pos, origin, 0, WHITE);

    }


    void noteUpdate() {

        
        speed = 2;
        y = initialY + (speed * (cond->songPosition - note.timeToHit));
        if (cond->songPosition > note.timeToHit) played = true;
        DrawNote();
        std::cout << y << std::endl;

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
        int x;


    NoteSpawner()
    {

    }
	NoteSpawner(vector<PlayNote> spawnNote,Conductor* conductor,int corridor, int x):corridor(corridor),conductor(conductor),notes(spawnNote),x(x)
	{
        AssignChartNotes(notes, conductor);
        
        


	}

    void AssignChartNotes(vector<PlayNote> data,Conductor* conductor) {

        for (int i = 0; i < data.size();i++) {
            if (data[i].corridor == corridor) {

                int idY = data[i].timeToHit / conductor->stepLengthInSeconds;
                
                spawnNotes.push_back(Note(data[i],idY,conductor,x));

            }
        }
    }

    void SpawnerUpdate() {

        for (int i = 0; i < spawnNotes.size();i++) {


            //if(!spawnNotes[i].played)
            spawnNotes[i].noteUpdate();
           
        }


        



    }
};

