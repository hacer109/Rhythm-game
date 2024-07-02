#pragma once
#include "GridSquare.h"
#include <iostream>
class Grid
{
public:

	int posX, posY, size;
	int hoveredX;
	int hoveredY;
	int hoveredId;
	int hoveredId2;
	int offsetY;
	
	Grid(int x, int y, int size) :posX(x), posY(y), size(size) {};
	Color cellColor;
	const int colnum = 16;
	GridSquare square[8][16];// GridSquare(posX, posY, 0, LIGHTGRAY, size);
	double sectionStartTime;
	double sectionEndTime;
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


				square[i][j] = GridSquare(posX + (16 * i * size), posY + (16 * j * size),size, cellColor);

				if (j % 1 == 0) {
					isGray = !isGray;
				}
				GridUpdate();
			}
		}
		GridUpdate();

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

