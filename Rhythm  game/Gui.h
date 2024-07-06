#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

class Gui
{




public:
	int noteOffset = 0;
	int SongSpeed = 1;
    int section = 0;
	int BPM = 0;
	int NoteLength = 0;
	float SongVolume = 0.1f;
	float curTime = 0;
	float songDuration=0;
	string painWhy;
	const char* str;
	string painWhy2;
	const char* str2;
	char moth;
	float LineY=0;
	int maxSections=0;
	int x=0;
	int y=0;
	int ID=0;
	int ID2=0;

	bool Button000Pressed = false;
    bool Button001Pressed = false;
    bool Button002Pressed = false;
    bool TextBox003EditMode = false;
    char TextBox003Text[128] = "Chart Path";




	bool hasHitCreate = false;
	void Draw();
	void Update();


};

