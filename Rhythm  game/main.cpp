

#include <iostream>
#include <raylib.h>
#include "Conductor.h"
#include <unordered_map>
#include "BaseStates.h"
#include "H_Tools0.h"
#include <vector>
#include "AnimatedObject.h"
#include "curState_.cpp"




void GameState(curState &gameState, int& gameStateNum) {

    switch (gameState)
    {
         case MainMenu:
             gameStateNum = 0;
           break;
         case SelectMenu:
             gameStateNum = 1;
           break;

          case FreePlay:
              gameStateNum = 2;
            break;

         case WeekSelect:
             gameStateNum = 3;
           break;

          case DebugMenu:
              gameStateNum = 4;
           break;

          case Song:
              gameStateNum = 5;
              break;
    }

    
}

 curState gameState = curState(MainMenu);
int main()  
{
    
    
    
    
    int gameStateNum = 0;
    InitWindow(1366, 768, "Rhythm mania");
   // std::unordered_map<int, BaseStates> scenes;

    BaseStates* scenes[]{ new Main_Menu(),new Select_Menu(),new SongPlay(),new Debug_menu()};

    GameState(gameState, gameStateNum);
    


    SetTargetFPS(168);

    InitAudioDevice();

    
    
    
    
    AnimatedObject obj = AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5,"assets/images/gfDanceTitle", 24,false);
   
    


    while (!WindowShouldClose()) {

        GameState(gameState, gameStateNum);
       
       
        
        ClearBackground(ORANGE);

        BeginDrawing();
       
        scenes[gameStateNum]->Update(gameState);
      //  obj.UpdateAnimation();
        
       
        EndDrawing();
    }

    CloseWindow();
}






