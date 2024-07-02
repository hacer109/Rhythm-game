#pragma once
#include <iostream>
#include <raylib.h>
#include "Grid.h"

#include <vector>
#include "Conductor.h"

using namespace std;
class Charter_menu
{
public:



    Conductor conductor = Conductor("assets/sound/Philly_Nice.mp3", 175);
    std::vector<Grid> sections;
    


    std::vector<Grid> AssignSections(std::vector<Grid> sections) {
        
        
        int numOfSections = roundf(conductor.songLengthInSeconds / (conductor.stepLengthInSeconds * 16));


        for (int i = 0; i < numOfSections;i++) {

            sections.push_back(Grid(100, 360, 3));
         
        }

        return sections;
    }
    
    Charter_menu()
    {
        sections = AssignSections(sections);
    }

	bool startHasRun = false;
   
   
  

    void CharterUpdate() {
        
        if (IsKeyReleased(KEY_SPACE)) conductor.PlaySong();
        conductor.ConductorUpdate();
       
        sections[0].AssignGrid();
        
    }

};

