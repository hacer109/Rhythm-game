



#include <iostream>
#include <raylib.h>

#include <unordered_map>
#include "BaseStates.h"
#include "H_Tools0.h"
#include <vector>
#include "AnimatedObject.h"
#include "curState_.cpp"
#include "Conductor.h"




//  TO DO:
//      
//      Fix mempry management, a lot of stuff on the heap needs to be deleted and remade.
//      memory:     966 mb
//      Need to make it optimized, like less than 1000 mb per scene at the very least.
//      Also...fuck forgot what to write...oh ye uhhhhhh unload stuff that isnt needed 
//      its 1:39 am my brain is a mush...
//      also replace some stuff with smart pointers
// 
//      pointers - heap
//      no pointers - stack 
// 
//      prioritize stack whenever possible
//      Notes from the 2 Cherno videos i watched ^^^
//      probably best to make everything work then optimize dunno...
//


void GameState(curState *gameState, int& gameStateNum) {

    switch (*gameState)
    {
         case MainMenu:
             gameStateNum = 0;
           break;
         case SelectMenu:
             gameStateNum = 1;
           break;

          case FreePlay:
              gameStateNum = 5;
            break;

         case WeekSelect:
             gameStateNum = 3;
           break;

          case DebugMenu:
              gameStateNum = 4;
           break;

          case Song:
              gameStateNum = 2;
              break;
    }



    

    
}
int gameStateNum = 0;
 curState gameState = curState(MainMenu);



int main()  
{
    InitAudioDevice();
   // InitWindow(1920, 1080, "Rhythm mania");//  InitWindow(1366, 768, "Rhythm mania");
    InitWindow(1366, 768, "Rhythm mania");
    SetTargetFPS(168);
   
    
    
    
    int* numPtr = &gameStateNum;
    
    
  

    BaseStates* scenes[]{ new Main_Menu(),new Select_Menu(),new SongPlay(), new Debug_menu()
};

    GameState(&gameState, gameStateNum);
    

    while (!WindowShouldClose()) {

        
        
        
        ClearBackground(ORANGE);

        BeginDrawing();
        
        scenes[gameStateNum]->Update(numPtr);
        
       
        EndDrawing();
    }

   
    CloseAudioDevice();
    CloseWindow();
}






