#pragma once
#include <iostream>
#include <raylib.h>



class GridSquare
{
public:

	int squareX, squareY, squareSize,noteLength,size, ID, ID2;
	bool hasNote = false;
	bool hoveredOver;
	Color color;
	Color hoveredColor;
	Color defaultColor;
	Rectangle rect;
	GridSquare()
	{

	}
	GridSquare(int squareX, int squareY, int size, Color color) :

		squareX(squareX),
		squareY(squareY),
		size(size),
		defaultColor(color)
		

	{
		//hasNote = false;
		rect = { float(squareX),float(squareY), float(16) * float(size), float(16) * float(size) };
	}




	void DrawSquare() {

		DrawRectangleRec(rect, color);
	}





	void IsMouseClickingThis() {

		Vector2 mousePos = GetMousePosition();
		switch (CheckCollisionPointRec(mousePos, rect)) {

		case true:

			color = GRAY;
			if (!IsKeyDown(KEY_G))hoveredOver = true;

			break;
		case false:

			color = defaultColor;
			hoveredOver = false;

			break;

		}


		

		
	}




	void SquareUpdate() {

		
		IsMouseClickingThis();
		DrawSquare();
	}
};

