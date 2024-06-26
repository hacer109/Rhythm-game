#include "mainMenuClass.h"



void AnimatedButton::changeScene(curState& gameScene, curState &changeScene) {


	gameScene = changeScene;

}

void AnimatedButton::pressedKeyToState(KeyboardKey key,curState changeState, curState& gameState) {

	if (IsKeyReleased(key)) {

		changeScene(gameState, changeState);
	}
	
}

void AnimatedButton::UpdateButton(int activeNum,int currentNum) {

	anim.posX = posX;
	anim.posY = posY;
	anim.sizeSprite = size;
	anim.UpdateAnimation();
	

}


void mainMenuClass::mainMenuUpdate() {

	
	if (IsKeyDown(KEY_D)) num = 0;
	else if (IsKeyDown(KEY_F)) num = 1;
	else if (IsKeyDown(KEY_J)) num = 2;
	else if (IsKeyDown(KEY_K)) num = 3;


	switch (num) {

	case 0:
		obj0->UpdateAnimation();
		break;
	case 1: obj1->UpdateAnimation();
		break;
	case 2: obj2->UpdateAnimation();
		break;
	case 3: obj3->UpdateAnimation();
		break;
	}

	


	//PlayWeek.UpdateButton(0,0);//change if new buttons are added

}