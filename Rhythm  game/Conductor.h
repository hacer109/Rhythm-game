#pragma once
#include <raylib.h>
#include <iostream>
class Conductor
{
public:

	float songBpm = 175;
	float secPerBeat;
	float songLengthInSeconds;
	float songPosition;
	float songPositionInBeats;
	float dspSongTime; // seconds passed since the song started
	float firstBeatOffset;
	float stepLengthInSeconds;
	int timeSignatureNumerator = 4;
	Music mainSong;

	Conductor()
	{
		PlayMusicStream(mainSong);
		AssignValues(mainSong);
	}
	void AssignValues(Music& mainSong) {

		secPerBeat = 60 / songBpm;
		dspSongTime = float(GetMusicTimePlayed(mainSong));
		songLengthInSeconds = GetMusicTimeLength(mainSong);
		stepLengthInSeconds = (60 / songBpm) * (1 / timeSignatureNumerator);

	}

	Conductor(Music &mainSong): mainSong(mainSong)
	{
		
		PlayMusicStream(mainSong);
		AssignValues(mainSong);
	}

	

	void ConductorUpdate() {


		UpdateMusicStream(mainSong);
		AssignValues(mainSong);
		songPosition = float(GetMusicTimePlayed(mainSong) - dspSongTime - firstBeatOffset);
		songPositionInBeats = songPosition / secPerBeat;
		

		std::cout << "SongPos: " << songPosition << " BPM: " << songBpm << " PosInBeats: " << songPositionInBeats << " SecPerBeat:" << secPerBeat << " step Length: " << stepLengthInSeconds << std::endl;
	
	}

	
};

