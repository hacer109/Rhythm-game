#include "BaseStates.h"

void BaseStates::Update(int* gameState) {

}

void Main_Menu::Update(int* gameState) {


	//mainMenu.currentState = gameState;
	mainMenu.Playsong.gameState4 = gameState;
	//cout << gameState << endl;
	mainMenu.mainMenuUpdate();

	//std::cout << "Main Menu" << std::endl;
}
void Select_Menu::Update(int* gameState) {

	std::cout << "Select menu" << std::endl;
}
void SongPlay::Update(int* gameState) {

	song_stage.SongStageUpdate();
	std::cout << "Song play" << std::endl;
}
void Debug_menu::Update(int* gameState) {

	charterMenu.CharterUpdate();
	//std::cout << "Debug Menu" << std::endl;
}
