

#include <iostream>
#include <raylib.h>
#include "Conductor.h"
#include <unordered_map>
#include "BaseStates.h"
#include "H_Tools0.h"
#include <vector>
#include "AnimatedObject.h"
enum curState {

    MainMenu,
    SelectMenu,
    FreePlay,
    WeekSelect,
    DebugMenu,
    Song

};




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

 curState gameState;
int main()  
{
    
    
    
    gameState = MainMenu;
    int gameStateNum = 0;
    InitWindow(1366, 768, "Rhythm mania");
   // std::unordered_map<int, BaseStates> scenes;

    BaseStates* scenes[]{ new Main_Menu(),new Select_Menu(),new SongPlay(),new Debug_menu()};

    GameState(gameState, gameStateNum);
    


    SetTargetFPS(120);

    InitAudioDevice();

    
    
    
    
    AnimatedObject obj = AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, "assets/images/lose", 24,false);
   
    


    while (!WindowShouldClose()) {

        GameState(gameState, gameStateNum);
       
       
        
        ClearBackground(BLACK);

        BeginDrawing();
       
       // scenes[gameStateNum]->Update();
        obj.UpdateAnimation();
       
        EndDrawing();
    }

    CloseWindow();
}






