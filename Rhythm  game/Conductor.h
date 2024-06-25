#pragma once
#include <raylib.h>
class Conductor
{
public:

	float songBpm = 175;
	float secPerBeat;
	float songPosition;
	float songPositionInBeats;
	float dspSongTime; // seconds passed since the song started
	float firstBeatOffset;
	Music* mainSong;
	Conductor(Music &mainSong): mainSong(&mainSong)
	{
		PlayMusicStream(mainSong);
		secPerBeat = 60 / songBpm;
		dspSongTime = float(GetMusicTimePlayed(mainSong));
	}

	void ConductorUpdate();

	
};

