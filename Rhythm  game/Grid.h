#pragma once
#include "GridSquare.h"
#include <iostream>
#include <vector>
#include "Custom_Containers.h"


class Grid
{
public:

	int posX, posY, size;
	int hoveredX;
	int hoveredY;
	int hoveredId;
	int hoveredId2;
	int offsetY;
	bool isInitialized[8][16];
	bool containsNote[8][16];

	void MyGod() {

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 16;j++) {

				isInitialized[i][j] = false;
				containsNote[i][j] = false;
			}


		}
	}


	Grid(int x, int y, int size) :posX(x), posY(y), size(size)  {
	
		MyGod();
	};
	Color cellColor;
	const int colnum = 16;
	GridSquare square[8][16];// GridSquare(posX, posY, 0, LIGHTGRAY, size);
	double sectionStartTime;
	double sectionEndTime;
	int sectionBeatStart;
	int sectionBeatEnd;
	float stepLengthInSeconds;
	////////////////////////////////*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//																   \\
	//																   \\
	//	Note saving section,which works by  saving the notes		   \\
	//  inside a vector,the notes themselves are a struct that		   \\
	//  contains the time they should be hit(calculated by step and    \\
	//  section multiplied by step time),the corridor/ x position of   \\ 
	//  the array in the grid,the lenghth smh implemented,			   \\
	//  and smth more idk											   \\
	//																   \\
	////////////////////////////////*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	/*std::vector<DisplayPlayNote> sectionNotes;

	void AddNoteToVector(int length,int posXId,int posYId,float timeToPlay,int offset,int SectionId) {

		DisplayPlayNote note = DisplayPlayNote(length,posXId,posYId,timeToPlay,offset,SectionId);

		
		
		sectionNotes.push_back(note);
		
		
	}*/

	DisplayPlayNote allNotes[8][16];


	void AddNoteToArr( int length, int posXId, int posYId, int offset, int SectionId,float StepLengthSec) {

		allNotes[posXId][posYId] = DisplayPlayNote(length, posXId, posYId, offset, SectionId,StepLengthSec);
		containsNote[posXId][posYId] = !containsNote[posXId][posYId];
		allNotes[posXId][posYId].CONTAINS_NOTE = containsNote[posXId][posYId];

	}




	// TO DO: finnish
	

	

	void AssignGrid() {

		bool isGray = true;
		

		for (int i = 0; i < 8; i++) {

			isGray = !isGray;

			for (int j = 0; j < colnum; j++) {

				switch (isGray) {

				case true:
					cellColor = LIGHTGRAY;
					break;
				case false:
					cellColor = WHITE;
					break;
				}

				if (isInitialized[i][j] == false) {
				square[i][j] = GridSquare(posX + (16 * i * size), posY + (16 * j * size), size, cellColor);
				isInitialized[i][j] == true;
			    }
				else {
					square[i][j].squareX = posX + (16 * i * size);
					square[i][j].squareY = posY + (16 * j * size);
					square[i][j].size = size;
					square[i][j].color = cellColor;
				}

				if (j % 1 == 0) {
					isGray = !isGray;
				}
				GridUpdate();
			}
		}
		
		GridUpdate();
		DisplayNotes();
	}


	void DisplayNotes() {

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < colnum; j++) {
			
				if (allNotes[i][j].CONTAINS_NOTE == true)
					allNotes[i][j].DisplayNote(square[i][j].squareX,square[i][j].squareY);
			}
		}
	}


	void GridUpdate() {


		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < colnum; j++) {

				square[i][j].SquareUpdate();
				square[i][j].ID = i;
				square[i][j].ID2 = j;
				switch (square[i][j].hoveredOver) {
				case true:

					hoveredX = square[i][j].squareX;
					hoveredY = square[i][j].squareY;
					hoveredId = square[i][j].ID;
					hoveredId2 = square[i][j].ID2;
					break;
				case false:
					break;


				}

				

			}
		}
	
		DrawRectangle(posX + (16 * 4 * size), posY, 5, 16 * 16 * size, GREEN);

	}
};

