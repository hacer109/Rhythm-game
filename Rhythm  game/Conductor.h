#pragma once
#include <raylib.h>
#include <iostream>
class Conductor
{
	public:

			
			float songBpm = 178;
			
			float secPerBeat;
			
			float songLengthInSeconds;
			
			float songPosition;
			
			float songPositionInBeats;
			
			float dspSongTime;
			
			float firstBeatOffset;
			
			float stepLengthInSeconds;

			float timeSignatureNumerator = 4;


			std::string songPath;

			Music song;

			

			Conductor(std::string songPath,float BPM):
				
				songBpm(BPM),
				songPath(songPath)
			{
				
				song = LoadMusicStream((songPath).c_str());
				AssignValues();
			}

			void SetBPM(float newBpm) {

				songBpm = newBpm;
			}

			void AssignValues() {

				secPerBeat = 60 / songBpm;
				dspSongTime = GetMusicTimePlayed(song);
				songLengthInSeconds = GetMusicTimeLength(song);
				stepLengthInSeconds = (60.0 / songBpm) * (1.0 / timeSignatureNumerator);

			}

			void PlaySong() {
				PlayMusicStream(song);
			}

			void ConductorUpdate() {

			//	stepLengthInSeconds = (60 / songBpm) * (1 / timeSignatureNumerator);

				
				
				UpdateMusicStream(song);
				PlayMusicStream(song);
				songPosition = GetMusicTimePlayed(song);//-dspSongTime - firstBeatOffset;
				songPositionInBeats = songPosition / secPerBeat;

				std::cout << "SongPos: " << songPosition << " BPM: " << songBpm << " PosInBeats: " << songPositionInBeats << " SecPerBeat:" << secPerBeat << " step Length: " << stepLengthInSeconds << std::endl;


			}


			~Conductor()
			{
				UnloadMusicStream(song);
			}

};

