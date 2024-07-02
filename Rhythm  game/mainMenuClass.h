#pragma once
#include <iostream>
#include <vector>
#include "H_Tools0.h"
#include "AnimatedObject.h"
#include "curState_.cpp"
#include "MenuButton.h"


using namespace std;



class mainMenuClass
{
public:
	int test = 0;
	int* currentState;
   
	MenuButton Playsong = MenuButton(
		GetScreenWidth() / 2,
		GetScreenHeight() / 2,
		0.5,
		"assets/images/menu_freeplay",
		24, 
		true,
		1,
		"freeplay basic0",
		"freeplay white0",
		currentState,
		3
	);
	



	void mainMenuUpdate();
};