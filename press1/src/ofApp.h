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
		
    
    ofDirectory archive;
    vector <ofImage> archiveImages;
    ofImage image;
    ofImage keyImage; 
    
    vector <float> posX;
    vector <float> posY;
    vector <float> width;
    vector <float> height;
    vector <float> scales;
    vector <float> randomCircSizeBig;
    vector <float> randomCircSizeSmall;
    vector <float> randomSinStart;
    vector <int> randomShapeNum;
    
    float numPhotos; // number of photos in archive
    float focus = 1;
    float step;
    bool keyDown;
    bool base[8];
    int numPressed;
    int keyImageGrow;
    
     
     
     
    
    
    
};
