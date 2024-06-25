#include "BaseStates.h"


void BaseStates::Update() {

}

void Main_Menu::Update() {

	mainMenu.mainMenuUpdate();
	std::cout << "Main Menu" << std::endl;
}
void Select_Menu::Update() {

	std::cout << "Select menu" << std::endl;
}
void SongPlay::Update() {

	song_stage.SongStageUpdate();
	std::cout << "Song play" << std::endl;
}
void Debug_menu::Update() {

	//charterMenu.CharterUpdate();
	std::cout << "Debug Menu" << std::endl;
}
