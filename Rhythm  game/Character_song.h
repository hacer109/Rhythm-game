#pragma once
#include <iostream>
#include <raylib.h>
#include "AnimatedObject.h"
#include <nlohmann/json.hpp>
using namespace std;

class Character_song
{
public:


		int fps;
		string charPath;
		string UPnote;
		string DOWNnote;
		string LEFTnote;
		string RIGHTnote;
		string filePath;
		int animState;
		int x, y, size;
		AnimatedObject idle;
		AnimatedObject up;
		AnimatedObject down;
		AnimatedObject left;
		AnimatedObject right;

	Character_song(int x,int y,int size,string charPath,string UPnote,string DOWNnote,string LEFTnote,string RIGHTnote,string IDLEanim,int fps)
	{
		idle = AnimatedObject(x,y,size,charPath,fps,IDLEanim,true);
		left = AnimatedObject(x, y, size, charPath, fps, LEFTnote, true);
		up = AnimatedObject(x, y, size, charPath, fps, UPnote, true);
		down = AnimatedObject(x, y, size, charPath, fps, DOWNnote, true);
		right = AnimatedObject(x, y, size, charPath, fps, RIGHTnote, true);




	}

	void CharSingState() {


		switch (animState) {

		case 0:
			
			left.UpdateAnimation();
			break;
		case 1:
			down.UpdateAnimation();

			break;
		case 2:

			up.UpdateAnimation();
			break;
		case 3:

			right.UpdateAnimation();
			break;
		case 4:
			idle.UpdateAnimation();
			break;




		}


	}

	void characterUpdate() {

		CharSingState();

		
	}

};

