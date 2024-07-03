#pragma once
#include <iostream>
#include <raylib.h>
/*class Custom_Containers
{
};*/


typedef struct {

	int sectionId;
	int corridor;
	int length;
	float timeToHit;
	int offset;

}PlayNote;

typedef struct DisplayPlayNote{
	public:

	PlayNote note;
	
	

	DisplayPlayNote(int length, int posXId, int posYId, float timeToPlay, int offset, int SectionId)
	{

		
		note.corridor = posXId;
		note.length = length;
		note.timeToHit = timeToPlay;
		note.offset = offset;
		note.sectionId = SectionId;

	}

	void DisplayNote(int X,int Y) {

		
		DrawRectangle(X, Y, 25, note.length, BLUE);
		DrawCircle(X, Y, 50, RED);

	}

	
};
