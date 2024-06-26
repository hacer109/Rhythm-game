#include "BaseStates.h"

void BaseStates::Update(curState& gameState) {

}

void Main_Menu::Update(curState& gameState) {

	mainMenu.mainMenuUpdate();
	//std::cout << "Main Menu" << std::endl;
}
void Select_Menu::Update(curState& gameState) {

	std::cout << "Select menu" << std::endl;
}
void SongPlay::Update(curState& gameState) {

	song_stage.SongStageUpdate();
	std::cout << "Song play" << std::endl;
}
void Debug_menu::Update(curState& gameState) {

	//charterMenu.CharterUpdate();
	std::cout << "Debug Menu" << std::endl;
}
