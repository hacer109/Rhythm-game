#pragma once
#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include <fstream>
#include <vector>
#include "Conductor.h"
#include "Gui.h"
#include <map>
#include <nlohmann/json.hpp>
#include "Custom_Containers.h"

using namespace std;

 





class Charter_menu
{
public:



    Conductor conductor = Conductor("assets/sound/Philly_Nice.mp3", 175);
    Gui gui;
    std::vector<Grid> sections;
    std::map<int, int> set;
    float sectionDur;
  //  std::unordered_map<> sectionTimes;


    nlohmann::json jsonArray;


    void SaveToJsonChartData() {
       
        


        for (int i = 0; i < sections.size();i++) {

            for (int j = 0; j < 16; j++) {

                for (int k = 0; k < 8;k++) {
                    nlohmann::json jasonData;// who tf is Jason ??????
                    if (sections[i].allNotes[k][j].CONTAINS_NOTE == true) {

                        jasonData["songPath"] = conductor.songPath;
                        jasonData["BPM"] = conductor.songBpm;
                        jasonData["sectionID"] = sections[i].allNotes[k][j].note.sectionId;
                        jasonData["corridor"] = sections[i].allNotes[k][j].note.corridor;
                        jasonData["length"] = sections[i].allNotes[k][j].note.length;
                        jasonData["timeToHit"] = sections[i].allNotes[k][j].note.timeToHit;
                        jasonData["offset"] = sections[i].allNotes[k][j].note.offset;

                        jsonArray.push_back(jasonData);


                    }

                }

            }




        }

    }

    void SaveChart(string name) {
       
        
        string a = "assets/Chart_Data/" + name;
        ofstream outputFile(a);
        if (!outputFile) {
            cerr << "failed to open file,please create a file with a .json extension in order to write to it" << endl;

            
        }
        else {
            SaveToJsonChartData();
            outputFile << setw(4) << jsonArray << endl;
            outputFile.close();
        }
       


    }




    void AssignBoolChart(vector<PlayNote> data) {

        for (int i = 0; i < data.size();i++) {
            
           
                float sectionTime = conductor.stepLengthInSeconds * 16;
                int idY = (data[i].timeToHit - (data[i].sectionId * sectionTime)) / conductor.stepLengthInSeconds;

                sections[data[i].sectionId].containsNote[data[i].corridor][idY] = true;
                sections[data[i].sectionId].allNotes[data[i].corridor][idY].note = data[i];
                sections[data[i].sectionId].allNotes[data[i].corridor][idY].CONTAINS_NOTE = true;


                cout << "assigned " << i << endl << endl<<endl;
            
                //sections[data[i].sectionId].containsNote[data[i].corridor][calc];

            }




        


    }


    void LoadChart(string name) {
        string a = "assets/Chart_Data/" + name;
        ifstream inputFile(a);
        if (!inputFile) {

            cerr << "failed to open file,please put  the properly structured json file" << endl;
        }
        else {



        }

        nlohmann::json Jasondata;
        inputFile >> Jasondata;
        inputFile.close();

        vector<PlayNote> data;


        for (const auto& entry : Jasondata) {
            PlayNote note;
          //  jasonData["sectionID"] = sections[i].allNotes[k][j].note.sectionId;
          //  jasonData["corridor"] = sections[i].allNotes[k][j].note.corridor;
       //     jasonData["length"] = sections[i].allNotes[k][j].note.length;
           // jasonData["timeToHit"] = sections[i].allNotes[k][j].note.timeToHit;
          //  jasonData["offset"]

            note.sectionId = entry["sectionID"];
            note.corridor = entry["corridor"];
            note.length = entry["length"];
            note.timeToHit = entry["timeToHit"];
            note.offset = entry["offset"];
            conductor.songBpm = entry["BPM"];
            gui.BPM = entry["BPM"];
            data.push_back(note);

        }

        AssignBoolChart(data);

    }



    void ClearSection() {

        for (int i = 0;i < 16; i++) {
            for (int j = 0; j < 8; j++) {

                sections[gui.section].allNotes[i][j].CONTAINS_NOTE = false;
                
            }


        }


    }






    std::vector<Grid> AssignSections(std::vector<Grid> sections) {
        
        
        int numOfSections = lroundf(conductor.songLengthInSeconds / (conductor.stepLengthInSeconds * 16))+2;
        
        sectionDur = conductor.stepLengthInSeconds * 16;
        for (int i = 0; i < numOfSections;i++) {

            sections.push_back(Grid(100, 360 + (768 * i), 3));
            sections[i].offsetY = 360 + (768 * i);
            sections[i].sectionStartTime = sectionDur * i;
            sections[i].sectionEndTime = sectionDur * (i + 1);
            sections[i].sectionBeatStart = roundf(sections[i].sectionStartTime / conductor.secPerBeat);
            sections[i].sectionBeatEnd = roundf(sections[i].sectionEndTime / conductor.secPerBeat);
            std::cout << sections[i].sectionBeatStart << " / " << sections[i].sectionBeatEnd << " | " << sections[i].sectionStartTime <<" / "<< sections[i].sectionEndTime <<  std::endl;
            set[sections[i].sectionBeatEnd] = i;

        }

        return sections;
    }
    
    Charter_menu()
    {
        sections = AssignSections(sections);
        gui.maxSections = sections.size();
    }

	bool startHasRun = false;
    
    Vector2 currentID;
        
    
    void CharterUpdate() {



        currentID = { (float)sections[gui.section].hoveredId,(float)sections[gui.section].hoveredId2 };
        conductor.ConductorUpdate();
        SetMusicVolume(conductor.song, gui.SongVolume);
        gui.curTime = conductor.songPosition;
        gui.songDuration = conductor.songLengthInSeconds;
        gui.x = sections[gui.section].hoveredX;
        gui.y = sections[gui.section].hoveredY;
        gui.ID = currentID.x;
        gui.ID2 = currentID.y;
        sections[gui.section].stepLengthInSeconds = conductor.stepLengthInSeconds;

        sections[gui.section].posY = -gui.curTime * ((16 * 16 * sections[0].size) / (conductor.stepLengthInSeconds * 16)) + sections[gui.section].offsetY;
      
        sections[gui.section].AssignGrid();
        //std::cout << sections[gui.section].allNotes[0][0].CONTAINS_NOTE << std::endl;
        
        if (IsMouseButtonReleased(0) && sections[gui.section].square[gui.ID][gui.ID2].hoveredOver == true && gui.ID >= 0 && gui.ID2 >= 0) {

          //  sections[gui.section].square[gui.ID][gui.ID2].hasNote = true; fml
            sections[gui.section].AddNoteToArr(gui.NoteLength, gui.ID, gui.ID2, gui.noteOffset, gui.section, conductor.stepLengthInSeconds);

        }
        
        if (GetMouseWheelMoveV().y < 0) {

            if (GetMusicTimePlayed(conductor.song) + conductor.stepLengthInSeconds < GetMusicTimeLength(conductor.song))
            SeekMusicStream(conductor.song, GetMusicTimePlayed(conductor.song) + conductor.stepLengthInSeconds);

        }
        else if (GetMouseWheelMoveV().y > 0) {

            double temp = double(GetMusicTimePlayed(conductor.song));
            temp -= 0.001;
            if (temp <= 0.08l) //annoying little thing...hate that it doesnt stop right at 0.00 but if it works it works ¯\_(ツ)_/¯ 
            { 
                
                temp = 0;
            
            }
            else {

                SeekMusicStream(conductor.song, temp);
            }
            
            std::cout << temp << std::endl;

        }
        if (IsKeyReleased(KEY_D)) {

            if (gui.section != sections.size() - 1) {

                SeekMusicStream(conductor.song, sections[gui.section].sectionEndTime+0.5);
            }


        }
        else if (IsKeyReleased(KEY_A)) {

            if (gui.section  != 0) {

                SeekMusicStream(conductor.song, sections[gui.section-1].sectionEndTime);
            }
        }


        if (IsKeyReleased(KEY_SPACE)) conductor.isPaused = !conductor.isPaused;
       
        if (gui.Button001Pressed) SaveChart(gui.TextBox003Text);
        if (gui.Button000Pressed)LoadChart(gui.TextBox003Text);
        if (gui.Button002Pressed) ClearSection();

       // if (conductor.songPositionInBeats == sections[gui.section].sectionBeatEnd) gui.section++;
        auto section = set.upper_bound(conductor.songPositionInBeats);
        gui.section = section->second;
        gui.Update();
    }
    
};

