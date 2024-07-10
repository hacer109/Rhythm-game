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
	bool CONTAINS_NOTE = false;

	DisplayPlayNote()
	{
		
	}

	void CalculateNotePlayTime(int gridY,float stepLengthInSec,int SectionId) {

		float PrevSectionTime;
		if (SectionId == 0) PrevSectionTime = 0;
		else PrevSectionTime = 16 * stepLengthInSec * SectionId;

		float currentSectionPlayTime = gridY * stepLengthInSec;


		note.timeToHit = currentSectionPlayTime + PrevSectionTime;
		std::cout << note.timeToHit << std::endl;;

	}

	DisplayPlayNote(int length, int posXId, int posYId, int offset, int SectionId,float StepLengthInSec)
	{

		
		note.corridor = posXId;
		note.length = length;
		//calculate the note timehit with sectionid and posY
		note.offset = offset;
		note.sectionId = SectionId;
		CalculateNotePlayTime(posYId, StepLengthInSec, SectionId);
	}

	void DisplayNote(int X,int Y) {

		
		int y = Y + (16 * 3 / 2);
		std::cout << "asdasd" << std::endl;
		DrawRectangle((X + (3 * 16 / 2))- 25/2, y, 25, note.length*(16*3)/2, BLUE);
		DrawCircle(X + (3 * 16 / 2), Y + (3 * 16 / 2), 20, RED);// add (3 * 16 / 2) to length when exporting :/

	}

	
};
