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

	
	PlayWeek.UpdateButton(0,0);//change if new buttons are added

}