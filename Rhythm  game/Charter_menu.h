#pragma once
#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include "Conductor.h"
#include <vector>


using namespace std;
class Charter_menu
{
public:




    
    
    std::vector<Grid> AssignSections(std::vector<Grid> sections,Conductor conductor) {


        int numOfSections = 70; //conductor.songLengthInSeconds / (conductor.stepLengthInSeconds * 16);


        for (int i = 0; i < numOfSections;i++) {

            sections.push_back(Grid(100, 360, 3));
         
        }

        return sections;
    }
    
    Charter_menu()
    {
    }

	bool startHasRun = false;
   
   
   

    
  

	void CharterStart() {



        
	}

    void CharterUpdate() {
        
     
       

        
    }

};

