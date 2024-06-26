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
		anim = AnimatedObject(x,y,size,filePathName,framerate,"BF NOTE DOWN", loopAnim);
	}


	void changeScene(curState& gameState, curState &changeScene);

	void pressedKeyToState(KeyboardKey key, curState changeState, curState& gameState);


	


	void UpdateButton(int activeNum, int currentNum);




};

class mainMenuClass
{
public:
	
	int num = 0;
	//AnimatedButton PlayWeek = AnimatedButton(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, 24, "assets/images/BOYFRIEND", true);
	string a = "assets/images/BOYFRIEND";
	AnimatedObject* obj0 =new AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, a, 24, "BF NOTE LEFT0", true);
	AnimatedObject* obj1 =new AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, a, 24, "BF NOTE DOWN0", true);
	AnimatedObject* obj2 =new AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, a, 24, "BF NOTE UP0", true);
	AnimatedObject* obj3 =new AnimatedObject(GetScreenWidth() / 2, GetScreenHeight() / 2, 0.5, a, 24, "BF NOTE RIGHT0", true);
	void mainMenuUpdate();
};