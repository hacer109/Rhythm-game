#pragma once
#include <iostream>
#include <raylib.h>
#include "AnimatedObject.h"
#include <nlohmann/json.hpp>
class PlayerButton
{public:
	int fps;
	string charPath;
	
	string filePath;
	int animState;
	int x, y, size;
	AnimatedObject idle;
	AnimatedObject pressedActive;

	AnimatedObject pressedStatic;


	PlayerButton(int x, int y, int size, string charPath, string PressedActiveAnim, string PressedStaticAnim, string IDLEanim, int fps)
	{
		idle = AnimatedObject(x, y, size, charPath, fps, IDLEanim, false);
		pressedActive = AnimatedObject(x-30, y-30, size-10, charPath, fps, PressedActiveAnim, false);
		pressedStatic = AnimatedObject(x-20, y-20, size-10, charPath, fps, PressedStaticAnim, false);
		



	}


	void ButtonStates() {

		switch (animState) {

		case 0:
			
			idle.UpdateAnimation();
			break;


		case 1:
			


			pressedStatic.UpdateAnimation(); break;
		case 2:
			
			pressedActive.UpdateAnimation(); break;

		}
	}


	void UpdatePlayerButton() {

		ButtonStates();
		//std::cout << pressedStatic.hasFinished << std::endl;
	}
};

