#pragma once

#include <iostream>
#include "Charter_menu.h"
#include "Song_Stage.h"
#include "mainMenuClass.h"
#include "curState_.cpp"

class BaseStates
{

public:
	virtual void Update(curState &gameState);
	
};

class Main_Menu : public BaseStates
{
public:
	mainMenuClass mainMenu;
	void virtual Update(curState& gameState);
};

class Debug_menu : public BaseStates
{
public:

	Charter_menu charterMenu;
	void virtual Update(curState& gameState);
};

class SongPlay : public BaseStates
{
public:
	Song_Stage song_stage;

	void virtual Update(curState& gameState);
};


class Select_Menu : public BaseStates
{
public:
	void virtual Update(curState& gameState);
};