#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include <raylib.h>
#include <vector>
#include "H_Tools0.h"
#include <ctime>
#include <unordered_map>
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
	 string specificAnimationName;
	 float elapsedTime = 0.0f;
	 bool isPaused = false;
	// unordered_map<string,int> indexsOfSameAnim;
	 vector<Xml::SubTexture> subsOfSameAnim;
	 vector<Xml::SubTexture> renderTextures;

	 //TO DO:
	 //
	 //		Add a way to separate multiple animations inside an xml file,or have it accept the raw values(sorted)
	 //		extracted from the xml externally,string? do it in H_tools01.h
	 //DONE!!! (left for record)


	 


	 AnimatedObject()
	 {

	 }
	AnimatedObject(int x,int y,float Size,string fileNamePath,int fps,bool Looping) : posX(x),sizeSprite(Size), posY(y), path(fileNamePath), maxFps(fps), looping(Looping)
	{
		PrepareFiles();


		renderTextures = subTexture;
	}


	AnimatedObject(int x, int y, float Size, string fileNamePath, int fps,string specificAnimationName, bool Looping) : posX(x), sizeSprite(Size), posY(y), path(fileNamePath), maxFps(fps), specificAnimationName(specificAnimationName), looping(Looping)
	{
		PrepareFiles();
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i < totalFrames;i++) {

			if (subTexture[i].name.find(specificAnimationName) != string::npos){
				
				subsOfSameAnim.push_back(subTexture[i]);
				cout << i << " ,";
			}


		}
		renderTextures = subsOfSameAnim;
		totalFrames = renderTextures.size();
		cout << endl;
		cout << renderTextures.size();
		cout << endl;
		cout << endl;
		cout << endl;
		
	}

	void checkValues() {

		for (int i = 0; i < subTexture.size();i++) {

			if (subTexture[i].frameHeight == 0) { subTexture[i].frameHeight = subTexture[i].height; }
			if (subTexture[i].frameWidth == 0) { subTexture[i].frameWidth = subTexture[i].width; }
		}

	}

	void PrepareFiles() {
		
		subTexture = Xml::parseXML((path + xml).c_str());
		image = LoadImage((path+png).c_str());
		atlas = LoadTextureFromImage(image);
		totalFrames = subTexture.size();
		timePerFrame = 1.0f / maxFps;
		checkValues();
		UnloadImage(image);
	}



	

	unsigned int currentFrame = 0;
	void ReturnBounds(Rectangle* rectangle) {


		
		rectangle->x = renderTextures[currentFrame].x;
		rectangle->y = renderTextures[currentFrame].y;
		rectangle->width = renderTextures[currentFrame].frameWidth;
		rectangle->height = renderTextures[currentFrame].frameHeight;

	}
	

	int framesToAdvance;
   void UpdateAnimation() {
	    

	  /* frameCounter++;

	   if (frameCounter >= (GetFPS() / maxFps)) {

		   frameCounter = 0;
		   currentFrame++;

		   if (currentFrame == totalFrames - 1) currentFrame = 0;
	   }*/
	  
	 // elapsedTime += GetFrameTime();

	 /*  while (elapsedTime >= timePerFrame) {
		   elapsedTime -= timePerFrame;
		   currentFrame++;

		   if (currentFrame >= totalFrames) {
			   currentFrame = 0;
		   }
	   }*/

	 /*  if (elapsedTime >= timePerFrame) {
		   elapsedTime = 0.0f;
		   currentFrame++;
		   if (currentFrame >= totalFrames) {
			   currentFrame = 0;
		   }
	   }*/
		


	 /*  elapsedTime += GetFrameTime();

	   framesToAdvance = static_cast<int>(elapsedTime / timePerFrame);
	   elapsedTime -= framesToAdvance * timePerFrame;

	   currentFrame += framesToAdvance;

	   if (currentFrame >= totalFrames) {
		   currentFrame = currentFrame % totalFrames;
	   }*/

	    

	   elapsedTime += GetFrameTime();
	   if (elapsedTime >= 1.0f / maxFps) {
		   
		   
		   if(isPaused == false)currentFrame++;
		   elapsedTime = 0;

		   if (currentFrame >= totalFrames) {
			   currentFrame = 0;
		   }

	   }

	   

		ReturnBounds(&frameRec);

		pos.x = posX - (renderTextures[currentFrame].frameX);
		pos.y = posY - (renderTextures[currentFrame].frameY);
		pos.height = renderTextures[currentFrame].frameHeight*sizeSprite;
		pos.width = renderTextures[currentFrame].frameWidth*sizeSprite;//used to be on width and height for some reason i forgot why :/

		DrawTexturePro(atlas, frameRec,pos ,origin , 0, WHITE);
		

	}

   void PauseAnimation() {

	   isPaused = true;
	}
   void PlayAnimation() {
	   isPaused = false;
   }
   void StopAnimation() {
	   isPaused = false;
	   currentFrame = 0;
   }
	
   bool IsFinnished() {

	   if (currentFrame == totalFrames) {
		   return true;
	   }
	   else return false;
	   
   }

};

