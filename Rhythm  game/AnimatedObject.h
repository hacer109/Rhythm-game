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
	bool looping;
	vector<Xml::SubTexture> subTexture;
	Image image;
	string png = ".png";
	string path;
	AnimatedObject(int x,int y,string fileNamePath,bool Looping) : posX(x), posY(y),path(fileNamePath),looping(Looping)
	{
		PrepareFiles();

	}

	void PrepareFiles() {
		
		//subTexture = Xml::parseXML(fileNamePath + '.xml');
		image = LoadImage((path+png).c_str());
		atlas = LoadTextureFromImage(image);
		
		UnloadImage(image);
	}
	void Draw() {
		DrawTexture(atlas, posX, posY, WHITE);
	}
	
};

