#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include <raylib.h>
#include <vector>
#include "H_Tools0.h"
#include <ctime>

using namespace std;

class AnimatedObject
{public:
	int posX, posY;
	const char* fileNamePath;
	Texture2D atlas;
	int maxFps;
	
	int frameCounter;
	float sizeSprite;
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
	 float timePerFrame;
	
	 float elapsedTime = 0.0f;


	AnimatedObject(int x,int y,float Size,string fileNamePath,int fps,bool Looping) : posX(x),sizeSprite(Size), posY(y), path(fileNamePath), maxFps(fps), looping(Looping)
	{
		PrepareFiles();

	}

	void PrepareFiles() {
		
		subTexture = Xml::parseXML((path + xml).c_str());
		image = LoadImage((path+png).c_str());
		atlas = LoadTextureFromImage(image);
		totalFrames = subTexture.size();
		timePerFrame = 1.0f / maxFps;
		UnloadImage(image);
	}



	

	unsigned int currentFrame = 0;
	void ReturnBounds(Rectangle* rectangle) {


		
		rectangle->x = subTexture[currentFrame].x;
		rectangle->y = subTexture[currentFrame].y;
		rectangle->width = subTexture[currentFrame].width;
		rectangle->height = subTexture[currentFrame].height;

	}
	

	int framesToAdvance;
   void UpdateAnimation() {
	    

	  /* frameCounter++;

	   if (frameCounter >= (GetFPS() / maxFps)) {

		   frameCounter = 0;
		   currentFrame++;

		   if (currentFrame == totalFrames - 1) currentFrame = 0;
	   }*/
	  
	  elapsedTime += GetFrameTime();

	 /*  while (elapsedTime >= timePerFrame) {
		   elapsedTime -= timePerFrame;
		   currentFrame++;

		   if (currentFrame >= totalFrames) {
			   currentFrame = 0;
		   }
	   }*/

	   if (elapsedTime >= timePerFrame) {
		   elapsedTime = 0.0f;
		   currentFrame++;
		   if (currentFrame >= totalFrames) {
			   currentFrame = 0;
		   }
	   }
		


	 /*  elapsedTime += GetFrameTime();

	   framesToAdvance = static_cast<int>(elapsedTime / timePerFrame);
	   elapsedTime -= framesToAdvance * timePerFrame;

	   currentFrame += framesToAdvance;

	   if (currentFrame >= totalFrames) {
		   currentFrame = currentFrame % totalFrames;
	   }*/

	    



	   



	    
		ReturnBounds(&frameRec);
		pos.x = posX;
		pos.y = posY;
		pos.height = subTexture[currentFrame].height*sizeSprite;
		pos.width = subTexture[currentFrame].width*sizeSprite;

		
		




		
		DrawTexturePro(atlas, frameRec,pos ,origin , 0, WHITE);

	}

	
	
};

