#include "Conductor.h"
#include <iostream>

void Conductor::ConductorUpdate()
{
	songPosition = float(GetMusicTimePlayed(*mainSong) - dspSongTime - firstBeatOffset);
	songPositionInBeats = songPosition / secPerBeat;
	UpdateMusicStream(*mainSong);

	std::cout << "SongPos: " << songPosition << " BPM: " << songBpm << " PosInBeats: " << songPositionInBeats << " SecPerBeat:" << secPerBeat << std::endl;
}