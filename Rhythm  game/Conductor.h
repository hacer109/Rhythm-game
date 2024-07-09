#pragma once
#include <raylib.h>
#include <iostream>
#include <string>
#include<cmath>
class Conductor
{
	public:

			
			float songBpm = 178;
			
			float secPerBeat=0;
			
			float songLengthInSeconds=0;
			
			float songPosition=0;
			
			int songPositionInBeats=0;
			
			float dspSongTime=0;
			
			float firstBeatOffset=0;
			
			float stepLengthInSeconds=0;

			float timeSignatureNumerator = 4;

			bool isPaused = true;

			int curStep;
			std::string songPath;

			Music song;

			Conductor()
			{

			}

			Conductor(std::string songPath,float BPM):
				
				songBpm(BPM),
				songPath(songPath)
			{
				
				song = LoadMusicStream(songPath.c_str());
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

			void PauseSong() {

				PauseMusicStream(song);
				isPaused = true;
			}

			void PlaySong() {
				PlayMusicStream(song);
				isPaused = false;
			}

			void ConductorUpdate() {

				AssignValues();
               
				UpdateMusicStream(song);


			

				if (isPaused)PauseSong();
				else
				{
					PlaySong();
				}
				
				
				
				songPosition = GetMusicTimePlayed(song);//-dspSongTime - firstBeatOffset;
				songPositionInBeats = floor(songPosition / secPerBeat);//c++ math roundf sucks ass
				curStep = floor(songPosition / stepLengthInSeconds);
			//	std::cout << "SongPos: " << songPosition << " BPM: " << songBpm << " PosInBeats: " << songPositionInBeats << " SecPerBeat:" << secPerBeat << " step Length: " << stepLengthInSeconds <<  " song length" <<  songLengthInSeconds << std::endl;

				
			}


			~Conductor()
			{
				//UnloadMusicStream(song);
			}

};

