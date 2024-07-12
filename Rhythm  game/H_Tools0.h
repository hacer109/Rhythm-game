#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tinyxml2.h>
#include <raylib.h>
#include <vector>
#include<chrono>
using namespace tinyxml2;
using namespace std;
using namespace std::chrono;
static class Xml {
public:
  
  static  std::string readXMLFileToString(const std::string& filePath) {
        // Load the XML file
        XMLDocument doc;
        XMLError result = doc.LoadFile(filePath.c_str());
        if (result != XML_SUCCESS) {
            std::cerr << "Error: Unable to load file " << filePath << std::endl;
            return "";
        }

        // Use a string stream to read the file contents into a string
        std::ostringstream oss;
        std::ifstream file(filePath);
        if (file.is_open()) {
            oss << file.rdbuf();
            file.close();
        }
        else {
            std::cerr << "Error: Unable to open file " << filePath << std::endl;
            return "";
        }

        return oss.str();
    }

  //diasdkjdsakdskaldsklk;ladksadslkasdl

  


  

  struct SubTexture {
      string name = "";
      int x;
      int y;
      int width;
      int height;
      int frameX=0;
      int frameY=0;
      int frameWidth=0;
      int frameHeight=0;
  };

  // Function to load and parse the XML file and extract SubTexture elements
  static vector<SubTexture> parseXML(const char* filename) {
      // Vector to store the extracted SubTextures
      vector<SubTexture> subTextures;

      // Load the XML file
      XMLDocument doc;
      if (doc.LoadFile(filename) != XML_SUCCESS) {
          cerr << "Failed to load file: " << filename << endl;
          return subTextures;
      }

      // Get the root element
      XMLElement* root = doc.RootElement();
      if (!root) {
          cerr << "No root element found in the XML file." << endl;
          return subTextures;
      }

      // Iterate through each SubTexture element
      for (XMLElement* elem = root->FirstChildElement("SubTexture"); elem != nullptr; elem = elem->NextSiblingElement("SubTexture")) {
          SubTexture st;

          // Extract attributes
          st.name = elem->Attribute("name");
          elem->QueryIntAttribute("x", &st.x);
          elem->QueryIntAttribute("y", &st.y);
          elem->QueryIntAttribute("width", &st.width);
          elem->QueryIntAttribute("height", &st.height);
          elem->QueryIntAttribute("frameX", &st.frameX);
          elem->QueryIntAttribute("frameY", &st.frameY);
          elem->QueryIntAttribute("frameWidth", &st.frameWidth);
          elem->QueryIntAttribute("frameHeight", &st.frameHeight);

          

          // Add the SubTexture to the vector
          subTextures.push_back(st);
      }

      return subTextures;
  }

};



static class Tweens {
public:


    static float Tween(float start, float end, float speed) {

        float dy = end - start;
        

        

        return start + speed *dy;
    }

  static float Ease(float start, float end, float speed) {

        float dy = end - start;
        float Vy = dy * speed;

        start += Vy;

        return start;
    }

};
    

class Tween {
public:
    float startValue;
    float endValue;
    float totalTime;
    float currentTime;

public:

    Tween()
    {

    }

    Tween(float start, float end, float time)
        : startValue(start), endValue(end), totalTime(time), currentTime(0.0f) {
    }

    float update() {
        currentTime += GetFrameTime();
        if (currentTime >= totalTime) {
            return endValue; // Tween completed
        }
        else {
            // Calculate t (normalized time)
            float t = currentTime / totalTime;

            // Perform linear interpolation (lerp)
            float currentValue = startValue + t * (endValue - startValue);

            return currentValue;
        }
    }
};




