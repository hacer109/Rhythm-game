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
#include <raymath.h>
#include "H_Tools0.h"
using namespace std;






class sustainLength {
public:

    int offset;

    Texture texture; 
    Rectangle susRectangle; 
    
    Rectangle pos;


    sustainLength(Texture texture,Rectangle susRectangle,Rectangle pos,int offset):
        texture(texture),
        susRectangle(susRectangle),
        pos(pos)
    {

    }

    void susUpdate(Rectangle pos) {

        Rectangle acPos = pos;
        acPos.y = pos.y + offset;
        
        DrawTexturePro(texture,susRectangle , pos, {0,0},0,WHITE);
       // DrawRectangle(pos.x, pos.y, 150, 100, BLUE);
    }

};




class Note {
public:



    PlayNote note;
    int stepTime;
    bool played =false;
    float timeInstanciate;
    int x;
    float speed = 2.5;
        
    float initialY;
    int y;
    int size;
    Conductor* cond;
    Image image;

    Image sustains;

    Texture2D textures;
    Texture2D susTextures;

    int targetY = 2*768;
    Rectangle susRectangle;//among us...
    Rectangle susRectangleEnd; // damn he got ejected 
    Rectangle frameRec;
    Rectangle pos;
    Rectangle susPos;
    float tempY;
    int key;
    Tween begining_tween;
    
    bool isSustainNote = false;
    bool isPlayer;
    vector<sustainLength> sustainNotes;

    Note(PlayNote note,int stepTime,Conductor* condu,int x,int y,float speed,bool isPlayer):
       isPlayer(isPlayer), speed(speed), tempY(y), note(note), stepTime(stepTime), cond(condu), x(x)
    {
        


        begining_tween = Tween(targetY, 50, speed-1);
        image = LoadImage("assets/images/notes.png");
        sustains = LoadImage("assets/images/note_holds.png");
            textures = LoadTextureFromImage(image);
            susTextures = LoadTextureFromImage(sustains);


            susPos.x = x + 25;
            susPos.y = y + 25;
            susPos.width = susRectangle.width;
            susPos.height = susRectangle.height;

            if (note.length != 0) {

             
                
                
                

                for (int i = 0; i < note.length;i++) {

                    if (i != note.length) {
                        sustainNotes.push_back(sustainLength(susTextures, susRectangle, susPos, 50*i));
                    }
                    else {
                        sustainNotes.push_back(sustainLength(susTextures, susRectangleEnd, susPos, 50*i));
                    }
                    

                }









                
                isSustainNote = true;
            }
            else isSustainNote = false;

            UnloadImage(image);
            UnloadImage(sustains);

            switch (note.corridor) {

            case 0 :

                frameRec = { 0,246,154,157 };
                susRectangle = {210,84,50,44};
                susRectangleEnd = {210,0,50,64};
                
                break;

            case 1 :
                
                frameRec = { 0,0,157,154 };

                susRectangle = { 140,84,50,44 };
                susRectangleEnd = { 140,0,50,64 };

                break;

            case 2 :
                
                frameRec = { 249,0,157,154 };

                susRectangle = { 70,84,50,44 };
                susRectangleEnd = { 70,0,50,64 };

                break;

            case 3 :
                
                frameRec = { 246,246,154,157 };

                susRectangle = { 0,84,50,44 };
                susRectangleEnd = { 0,0,50,64 };

                break;

            case  4:
                key = KEY_D;
                frameRec = { 0,246,154,157 };
                susRectangle = { 210,84,50,44 };
                susRectangleEnd = { 210,0,50,64 };

                break;

            case  5:
                susRectangle = { 140,84,50,44 };
                susRectangleEnd = { 140,0,50,64 };
                frameRec = { 0,0,157,154 };
                key = KEY_F;
                break;

            case 6:
                susRectangle = { 70,84,50,44 };
                susRectangleEnd = { 70,0,50,64 };
                frameRec = { 249,0,157,154 };
                key = KEY_J;
                break;

            case  7:
                susRectangle = { 0,84,50,44 };
                susRectangleEnd = { 0,0,50,64 };
                frameRec = { 246,246,154,157 };
                key = KEY_K;
                break;



            }


    }

    int ReturnIndex(PlayNote note) {

        if (cond->songPosition >= note.timeToHit - 0.08 && cond ->songPosition <= note.timeToHit + 0.08) {
            return 2;
        }
        else {

            return 1;
        }


    }
    
    bool drawTop = true;

    void DrawNote() {

        
        float inverseZoom = float(size);
        Vector2 origin = { 0,0 };
        pos.x = x;
        pos.y = y;
        pos.width = float(frameRec.width - inverseZoom);
        pos.height = float(frameRec.height - inverseZoom);

        if(isSustainNote && susPos.height >=0 && drawTop)
        DrawTexturePro(textures, frameRec, pos, origin, 0, WHITE);

        else if(!isSustainNote)DrawTexturePro(textures, frameRec, pos, origin, 0, WHITE);

        susPos.x = x+25;
        if (y <= 50 && IsKeyDown(key))
            susPos.y = 150;
        else if (y <= 50 && isPlayer == false) {
            susPos.y = 150;
            susPos.height -= 10;
        }
        else susPos.y = y+ 100;


        susPos.width = susRectangle.width;

        if(y >50)
        susPos.height = susRectangle.height * note.length;
        else {
            if (IsKeyDown(key)) susPos.height -= 10;
        
        

           

        }

        if (susPos.height <= 0 && isSustainNote) played = true;
        

        DrawTexturePro(susTextures, susRectangleEnd, susPos, { 0,0 }, 0, WHITE);
       
        for (int i = 0;i < sustainNotes.size();i++) {

            //sustainNotes[i].susUpdate(susPos);
        }

        //DrawTexturePro(susTextures, susRectangle, susPos, { 0,0 }, 0,WHITE);



    }


        bool CheckHit(int key) {


            if (isPlayer == false) {
                

                if (isSustainNote) {

                    float hitTime = cond->songPosition;
                    float timeDiff = fabs(hitTime - note.timeToHit);
                    if (timeDiff <= 0.1f) { // Adjust the hit window as needed
                        drawTop = false;
                        return true;
                    }
                }
                else {
                    float hitTime = cond->songPosition-0.08;
                    float timeDiff = fabs(hitTime - note.timeToHit);
                    if (timeDiff <= 0.1f) { // Adjust the hit window as needed
                        played = true;
                        return true;
                    }
                }
            }

            if (isSustainNote) {



                if (IsKeyPressed(key) && !played) {
                    float hitTime = cond->songPosition;
                    float timeDiff = fabs(hitTime - note.timeToHit);
                    if (timeDiff <= 0.1f) { // Adjust the hit window as needed
                        drawTop = false;
                        return true;
                    }
                }




            }
            else {
                if (IsKeyPressed(key) && !played) {
                    float hitTime = cond->songPosition;
                    float timeDiff = fabs(hitTime - note.timeToHit);
                    if (timeDiff <= 0.1f) { // Adjust the hit window as needed
                        played = true;
                        return true;
                    }
                }

            }


            return false;
        }
    
    






   /* bool CheckHit(int key) {
        if (IsKeyPressed(key) && !played) {
            float hitTime = cond->songPosition;
            float timeDiff = fabs(hitTime - note.timeToHit);
            if (timeDiff <= 0.1f) { // Adjust the hit window as needed
                played = true;
                return true;
            }
        }
        return false;
    }*/ //saving this just in case i break it :/





    

    int assets = 0;
    void noteUpdate() {

      //  begining_tween.totalTime = speed;
        if (targetY != 50) {
           
           // targetY = Lerp(targetY, GetScreenHeight() - 150, 2);
            
            targetY = begining_tween.update();

            std::cout << targetY << std::endl;
        }
        else {


            cond->PlaySong();

        }

        
       

      float a = ((8 * 16)) / (cond->stepLengthInSeconds * 16) + 768 + 150; 

        y = ((targetY)-((cond->songPosition - note.timeToHit) * (0.45 * speed))*a);
    


       // DrawRectangle(x, targetY, 5000, 10, BLUE);

      //  if (y < 500) played = true;
        DrawNote();
        

        assets = ReturnIndex(note);
        
    }

    ~Note()
    {
        std::cout << "DESTROED NOTE" << std::endl;
      //  assets = 1;
    }


};


class NoteSpawner
{
public:


    vector<PlayNote> notes;
    Conductor* conductor;
    int corridor;
    vector<Note> spawnNotes;
    int x, size, y;
    float speed;
    bool isPlayer;
    NoteSpawner()
    {

    }
    NoteSpawner(vector<PlayNote> spawnNote, Conductor* conductor, int corridor, int x, int size, int y,float speed,bool isPlayer) : 
        speed(speed),y(y),
        size(size),
        corridor(corridor), 
        conductor(conductor), 
        notes(spawnNote), 
        x(x),
        isPlayer(isPlayer)
    {
        AssignChartNotes(notes, conductor);




    }

    void AssignChartNotes(vector<PlayNote> data, Conductor* conductor) {

        for (int i = 0; i < data.size();i++) {
            if (data[i].corridor == corridor) {

                int idY = data[i].timeToHit / conductor->stepLengthInSeconds;

                spawnNotes.push_back(Note(data[i], idY, conductor, x, y,speed,isPlayer));

            }
        }
    }





    int teeeeee;
    float songTrack;
    
    void SpawnerUpdate() {

        for (int i = 0; i < spawnNotes.size();i++) {


            if(spawnNotes[i].played == false)
            spawnNotes[i].noteUpdate();
            spawnNotes[i].size = size;
            spawnNotes[i].x = x;
            spawnNotes[i].initialY = y;
           

            
            if (spawnNotes[0].played == false) {

                songTrack = conductor->songPosition;
                teeeeee = spawnNotes[0].assets;
            }
            else {

                if(conductor->songPosition == songTrack + 0.2)
                teeeeee = 1;
            }



            if (spawnNotes[0].played == true) spawnNotes.erase(spawnNotes.begin());

        }
        //if(spawnNotes.size() != 0)
     //   spawnNotes[0].assets = spawnNotes[0].ReturnIndex(spawnNotes[0].note);

        for (auto& note : spawnNotes) {
            if (note.CheckHit(note.key)) {
                std::cout << "Note hit!" << std::endl;
            }
        }
    }
    
};

