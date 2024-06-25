#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include <raylib.h>
#include <vector>
#include "H_Tools0.h"
using namespace std;

class AnimatedObject
{public:
	int posX, posY;
	const char* fileNamePath;
	Texture2D atlas;
	int maxFps;
	
	int frameCounter;
	
	int totalFrames = 0;
	bool looping;
	vector<Xml::SubTexture> subTexture;
	Image image;
	string png = ".png";
	string xml = ".xml";
	string path;
	Rectangle pos;
	Vector2 origin = { 0,0 };
	Rectangle frameRec;
	AnimatedObject(int x,int y,string fileNamePath,int fps,bool Looping) : posX(x), posY(y),path(fileNamePath),maxFps(fps), looping(Looping)
	{
		PrepareFiles();

	}

	void PrepareFiles() {
		
		subTexture = Xml::parseXML((path + xml).c_str());
		image = LoadImage((path+png).c_str());
		atlas = LoadTextureFromImage(image);
		totalFrames = subTexture.size();
		UnloadImage(image);
	}



	

	unsigned int currentFrame = 0;
	void ReturnBounds(Rectangle* rectangle) {


		
		rectangle->x = subTexture[currentFrame].x;
		rectangle->y = subTexture[currentFrame].y;
		rectangle->width = subTexture[currentFrame].width;
		rectangle->height = subTexture[currentFrame].height;

	}
	


	void UpdateAnimation() {

		
		
		
		


		ReturnBounds(&frameRec);
		pos.x = posX;
		pos.y = posY;
		pos.height = subTexture[currentFrame].height;
		pos.width = subTexture[currentFrame].width;

		
		




		
		DrawTexturePro(atlas, frameRec,pos ,origin , 0, WHITE);

	}

	
	
};

