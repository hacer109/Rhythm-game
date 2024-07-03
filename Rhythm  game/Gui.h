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
	float songDuration;
	string painWhy;
	const char* str;
	string painWhy2;
	const char* str2;
	char moth;
	float LineY;
	int maxSections;
	int x;
	int y;
	int ID;
	int ID2;
	bool hasHitCreate = false;
	void Draw();
	void Update();


};

