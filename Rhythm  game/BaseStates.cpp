#include "BaseStates.h"

void BaseStates::Update(int* gameState) {

}

void Main_Menu::Update(int* gameState) {


	//mainMenu.currentState = gameState;
	mainMenu.Playsong.gameState4 = gameState;
	mainMenu.charter.gameState4 = gameState;
	//cout << gameState << endl;
	mainMenu.mainMenuUpdate();

	//std::cout << "Main Menu" << std::endl;
}
void Select_Menu::Update(int* gameState) {

	std::cout << "Select menu" << std::endl;
}
void SongPlay::Update(int* gameState) {

	if (IsKeyReleased(KEY_F7)) *gameState = 0;


	song_stage.SongStageUpdate();
}
void Debug_menu::Update(int* gameState) {

	if (IsKeyReleased(KEY_F7)) *gameState = 0;

	charterMenu.CharterUpdate();
	
	//std::cout << "Debug Menu" << std::endl;
}
