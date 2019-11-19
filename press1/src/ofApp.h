#pragma once

#include "ofMain.h"

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
    
    void drawZero(float x, float y);
	void drawOne(float x, float y);
    
    
    
    ofDirectory archive;
    vector <ofImage> archiveImages;
    ofImage image;
    ofImage keyImage; 
    
    // RANDOM VARIABLES
    vector <float> posX;
    vector <float> posY;
    vector <float> width;
    vector <float> height;
    vector <float> scales;
    vector <float> randomCircSizeBig;
    vector <float> randomCircSizeSmall;
    vector <float> randomSinStart;
    vector <int> randomShapeNum;
    
    
    // REMEMBER PREVIOUS IMGS
    vector <float> drawnImgSizeW;
    vector <float> drawnImgSizeH;
    ofPoint eachDrawImgSize;
    
    vector <ofColor> drawnImgColor;
    ofColor eachDrawnImgColor;
    
    vector <ofPoint> drawnImgColorPts;
    ofPoint eachDrawnImgColorPts;
    
    float numRetrievals = 0; // # of times images have been retreived  
    vector <float> retreivedImg; // store keyNumbers
    vector <float> focus; // store seconds pressed per img
    vector <float> reverseFocus; // store reverse values to focus
    vector <float> opacity; // store 0 - 255 based on focus
    
    
    float time = ofGetElapsedTimef();
    
    // ANIMATOR VARIABLES 
    float step; // frequency of shapes to draw img
    float lineT; // random line thickness
    float lineX; // line width
    float lineY; // line height
    float randomRot; // random rotate 
    
    // KEY NUMBER COUNTER
    bool keyDown;
    bool base[8];
    int numPressed;
    int keyImageGrow;
    int keyNumber; 
     
    // ARCHIVE VARIABLES
    float numPhotos; // number of photos in archive
    float archiveImgHeight; // height of archive img
    float archiveImgWidth; // width of archive img
    float shapeSizeSin; // animate shape in archive img
    float shapeSize; // size of shape for archive img
     
    
    float w1; // img original size
    float h1;
    float w2; // img new size
    float h2;
    
     
    // FONTS + BINARY 
    ofTrueTypeFont canelaThin;
    ofTrueTypeFont canela;
    float binScale = 0.6;
    
    
    
};
