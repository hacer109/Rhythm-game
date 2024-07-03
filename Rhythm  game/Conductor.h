#pragma once
#include <raylib.h>
#include <iostream>
#include<cmath>
class Conductor
{
	public:

			
			float songBpm = 178;
			
			float secPerBeat;
			
			float songLengthInSeconds;
			
			float songPosition;
			
			int songPositionInBeats;
			
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

				AssignValues();
                //if(IsKeyReleased(KEY_A))
				UpdateMusicStream(song);


			//	stepLengthInSeconds = (60 / songBpm) * (1 / timeSignatureNumerator);

				
				if (IsKeyReleased(KEY_SPACE))PlaySong();
				
				
				songPosition = GetMusicTimePlayed(song);//-dspSongTime - firstBeatOffset;
				songPositionInBeats = floor(songPosition / secPerBeat);//c++ math roundf sucks ass
				
				std::cout << "SongPos: " << songPosition << " BPM: " << songBpm << " PosInBeats: " << songPositionInBeats << " SecPerBeat:" << secPerBeat << " step Length: " << stepLengthInSeconds <<  " song length" <<  GetMusicTimeLength(song) << std::endl;

				
			}


			~Conductor()
			{
				UnloadMusicStream(song);
			}

};

