#pragma once
#include <iostream>
#include <raylib.h>
#include "Grid.h"

#include <vector>
#include "Conductor.h"
#include "Gui.h"

using namespace std;
class Charter_menu
{
public:



    Conductor conductor = Conductor("assets/sound/Philly_Nice.mp3", 175);
    Gui gui;
    std::vector<Grid> sections;
    float sectionDur;


    std::vector<Grid> AssignSections(std::vector<Grid> sections) {
        
        
        int numOfSections = lroundf(conductor.songLengthInSeconds / (conductor.stepLengthInSeconds * 16))+2;
        
        sectionDur = conductor.stepLengthInSeconds * 16;
        for (int i = 0; i < numOfSections;i++) {

            sections.push_back(Grid(100, 360 + (768 * i), 3));
            sections[i].offsetY = 360 + (768 * i);
            sections[i].sectionStartTime = sectionDur * i;
            sections[i].sectionEndTime = sectionDur * (i + 1);
            sections[i].sectionBeatStart = roundf(sections[i].sectionStartTime / conductor.secPerBeat);
            sections[i].sectionBeatEnd = roundf(sections[i].sectionEndTime / conductor.secPerBeat);
         
        }

        return sections;
    }
    
    Charter_menu()
    {
        sections = AssignSections(sections);
        gui.maxSections = sections.size();
    }

	bool startHasRun = false;
   
    Vector2 currentID;
        

    void CharterUpdate() {
        currentID = { (float)sections[gui.section].hoveredId,(float)sections[gui.section].hoveredId2 };
        conductor.ConductorUpdate();
        SetMusicVolume(conductor.song, gui.SongVolume);
        gui.curTime = conductor.songPosition;
        gui.songDuration = conductor.songLengthInSeconds;
        gui.x = sections[gui.section].hoveredX;
        gui.y = sections[gui.section].hoveredY;
        gui.ID = currentID.x;
        gui.ID2 = currentID.y;
       // conductor.songBpm = gui.BPM;
        sections[gui.section].posY = -gui.curTime * ((16 * 16 * sections[0].size) / (conductor.stepLengthInSeconds * 16)) + sections[gui.section].offsetY;
      
        sections[gui.section].AssignGrid();
        
        
        //if (gui.curTime >= sections[gui.section].sectionEndTime) gui.section++;
        
        if (conductor.songPositionInBeats == sections[gui.section].sectionBeatEnd) gui.section++;
        gui.Update();
    }

};

