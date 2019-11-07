#pragma once

#include "ofMain.h"


//create new class named Particle
class Particle {
public:
    
//    declare variables of object
    ofPoint pos;
    ofPoint dir;
    float rad;
    ofColor color;
    
//    declare functions of object
//    void setup();
    void setup(ofPoint ParticlePos);
    void update();
    void draw();
    
    
    
    
};




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
    
  
    //    create INSTANCE of Particle; e.g. "ofPoint point" is an instance of ofPoint object
//    Particle p;
    
    
//    create VECTOR INSTSANCE of Particle - empty container, nothing in it
    vector<Particle> particles;
    
    
};
