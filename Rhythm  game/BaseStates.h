#pragma once

#include <iostream>
#include "Charter_menu.h"
#include "Song_Stage.h"
#include "mainMenuClass.h"

class BaseStates
{

public:
	virtual void Update();
	
};

class Main_Menu : public BaseStates
{
public:
	mainMenuClass mainMenu;
	void virtual Update();
};

class Debug_menu : public BaseStates
{
public:

	Charter_menu charterMenu;
	void virtual Update();
};

class SongPlay : public BaseStates
{
public:
	Song_Stage song_stage;

	void virtual Update();
};


class Select_Menu : public BaseStates
{
public:
	void virtual Update();
};