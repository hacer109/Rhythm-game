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
    bool played;
    int x, y;


    Note(PlayNote note,int stepTime)
    {

    }




    void DrawNote() {




    }


    void noteUpdate() {

        if (y < 0) {

            played = true;
       }



        


    }

    ~Note()
    {

    }


};


class NoteSpawner
{
public:


        vector<PlayNote> notes;
        Conductor* conductor;
        int corridor;
        vector<Note> spawnNotes;



    NoteSpawner()
    {

    }
	NoteSpawner(vector<PlayNote> spawnNote,Conductor* conductor,int corridor):corridor(corridor),conductor(conductor),notes(spawnNote)
	{
        AssignChartNotes(notes, conductor);
        
        


	}

    void AssignChartNotes(vector<PlayNote> data,Conductor* conductor) {

        for (int i = 0; i < data.size();i++) {
            if (data[i].corridor == corridor) {

                int idY = data[i].timeToHit / conductor->stepLengthInSeconds;
                
                spawnNotes.push_back(Note(data[i],idY));

            }
        }
    }

    void SpawnerUpdate() {




    }
};

