#include "Gui.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"






void Gui::Draw() {

	Vector2 mousePos = GetMousePosition();
	Rectangle rec{ 600,144,392,600 };
	GuiWindowBox(rec, "Debug Options");
	Rectangle rec2{ 688,192,120,24 };
	GuiSpinner(rec2, "section   ", &section, 0, maxSections-1, false);
	

	DrawText(("Sections: "+ to_string(maxSections-2)).c_str(), 688, 100, 50, WHITE);
	Rectangle rec3{ 688,230,120,24 };
	
	if(GuiValueBox(rec3, "BPM     ", &BPM, 0, 335, CanEditValue)) CanEditValue = !CanEditValue;
	Rectangle rec4{ 688,260,120,24 };
	Rectangle rec5{ 688,290,120,24 };
	Rectangle rec6{ 688,320,120,24 };
	GuiSpinner(rec4, "NoteLength   ", &NoteLength, 0, 100, false);
	GuiSpinner(rec5, "song speed   ", &SongSpeed, 0, 10, false);
	GuiSpinner(rec6, "Note offset   ", &noteOffset, 0, 10, false);
	Rectangle rec7{ 688,350,60,24 };
	Rectangle rec8{ 750,350,60,24 };
	Rectangle rec9{ 750,380,60,24 };
	Rectangle rec10{ 750,410,60,24 };
	GuiValueBox(rec7, "X Y", &x, 0, 99999, false);
	GuiValueBox(rec8, "", &y, 0, 99999, false);
	GuiValueBox(rec9, "cell ID x ", &ID, 0, 99999, false);
	GuiValueBox(rec10, "cell ID y ", &ID2, 0, 99999, false);
	Rectangle rec11{ 750,440,60,24 };
	GuiSliderBar(rec11, "Music Volume(editor only) 0", "1", &SongVolume, 0, 1);
	Rectangle rec12{ 750,470,150,24 };
	painWhy = std::to_string(songDuration);
	str = painWhy.c_str();
	painWhy2 = std::to_string(curTime);
	str2 = painWhy2.c_str();

	Rectangle rec13{ 750,470,150,24 };
	GuiProgressBar(rec12, "Song Progress", str, &curTime, 0, songDuration);
	GuiDrawText(str2, rec13, 1, GREEN);
	LineY = 360;
	Rectangle rec14{ 50, LineY, 400, 4 };
	//test test
	DrawRectangleRec(rec14, RED);
	Rectangle rec15{ 750,490, 400, 4 };
	

	Rectangle a{ 848, 144+100, 120, 24 };
	Rectangle b{ 848, 176 + 100, 120, 24 };
	Rectangle c{ 848, 208 + 100, 120, 24 };
	Rectangle d{ 848, 240 + 100, 120, 24 };

	Rectangle layoutRecs[4] = { a,b,c,d };
	Button000Pressed = GuiButton(layoutRecs[0], "Load Json");
	Button001Pressed = GuiButton(layoutRecs[1], "Export to Song");
	Button002Pressed = GuiButton(layoutRecs[2], "Clear Section");
	if (GuiTextBox(layoutRecs[3], TextBox003Text, 128, TextBox003EditMode)) TextBox003EditMode = !TextBox003EditMode;

	if (ID > 7 || ID< 0) ID = 7;
	if (ID2 > 15 || ID2 < 0) ID2 = 15;
}


void Gui::Update() {

	Draw();


	

}