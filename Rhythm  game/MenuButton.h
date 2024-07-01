#pragma once
#include <iostream>
#include <raylib.h>
#include "AnimatedObject.h"
#include "curState_.cpp"




class MenuButton
{
public:
	int* gameState4 = nullptr;
	AnimatedObject animSelected;
	AnimatedObject animIdle;
	int buttonX, buttonY,animFps;
	float size;
	bool looping;
	std::string animPath;
	bool isHoveredOver;
	int buttonId;
	std::string selectedAnim;
	std::string idleAnim;

	MenuButton(int buttonX, int buttonY, float size, std::string animPath, int fps, bool loopAnim, int buttonId, string selectedAnim, string idleAnim, int* state) :
		selectedAnim(selectedAnim),
		idleAnim(idleAnim),
		buttonX(buttonX),
		buttonY(buttonY),
		animPath(animPath),
		size(size),
		animFps(fps),
		looping(loopAnim),
		buttonId(buttonId),
		gameState4(state)
	{
		//gameState4 = state;
		animSelected = AnimatedObject(buttonX, buttonY, size, animPath, animFps, selectedAnim, looping);
		animIdle = AnimatedObject(buttonX, buttonY, size , animPath, animFps, idleAnim, looping);
	}

	int test;
	void TransitionScene(int gameStateNum) {

		cout << " state to song" << endl;
		test = gameStateNum;
		*gameState4 = test;
	}

	void PressedEnter() {

		if (IsKeyReleased(KEY_ENTER)) { TransitionScene(2);cout << "Pressed enter" << endl;
		}
		
	}




	void UpdateButton(int currentButtonId) {
		

		if (currentButtonId == buttonId) {
			isHoveredOver = true;
			animSelected.UpdateAnimation();
			PressedEnter();
		}
		else {
			animIdle.UpdateAnimation();
			isHoveredOver = false;
		}
		//cout << animSelected.subTexture[0].frameHeight << endl;
		//cout << gameState4 << endl;




	}





};

