#pragma once
#include <iostream>
#include <vector>
#include "H_Tools0.h"
#include "AnimatedObject.h"
#include "curState_.cpp"


class AnimatedButton {
public:
	
	int posX, posY,framerate;
	float size;
	string filePathName;
	AnimatedObject anim = AnimatedObject();
	bool loopAnim;
	AnimatedButton(int x,int y,float size,int framerate,string filePathName,bool loopAnim): posX(x) , posY(y), size(size) , framerate(framerate),filePathName(filePathName),loopAnim(loopAnim)
	{
		anim = AnimatedObject(x,y,size,filePathName,framerate,loopAnim);
	}


	void changeScene(curState& gameState, curState &changeScene);

	void pressedKeyToState(KeyboardKey key, curState changeState, curState& gameState);


	


	void UpdateButton(int activeNum, int currentNum);




};

class mainMenuClass
{
public:
	

	AnimatedButton PlayWeek = AnimatedButton(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, 24, "assets/images/menu_freeplay", true);

	void mainMenuUpdate();
};