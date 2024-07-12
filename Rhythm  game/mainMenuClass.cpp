#include "mainMenuClass.h"






void mainMenuClass::mainMenuUpdate() {

	
	if (IsKeyReleased(KEY_UP)) test++;
	else if (IsKeyReleased(KEY_DOWN)) test--;

	//cout << currentState << endl;
	
	Playsong.UpdateButton(test);
	charter.UpdateButton(test);

	

}