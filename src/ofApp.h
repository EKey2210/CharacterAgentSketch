#pragma once

#include "ofMain.h"
#include "Agent.hpp"

using namespace glm;

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void makeLetterPoints(string letter,float positionPercentage1,float positionPercentage2);
    
    
    ofTrueTypeFont font;
    int fontSize;
    string letter1;
    string letter2;
    string letter3;
    
    vector<Agent*> agents;
    vector<ofPoint> letterPoints;
    vector<ofPolyline> outline;
    vector<ofPath> word_path;
};
