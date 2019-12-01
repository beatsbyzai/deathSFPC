//#include "ofMain.h"
//#include "ofApp.h"
//
////========================================================================
//int main( ){
//	ofSetupOpenGL(1080 + 1080, 1920, OF_WINDOW);			// <-------- setup the GL context
//
//	// this kicks off the running of my app
//	// can be OF_WINDOW or OF_FULLSCREEN
//	// pass in width and height too:
//
////    ofSetFullscreen(true);
//	ofRunApp(new ofApp());
//
//}




//#include "ofMain.h"
//#include "ofApp.h"
////========================================================================
//int main( ){
//    ofGLFWWindowSettings s;
//    s.multiMonitorFullScreen = true;
//    ofCreateWindow(s);
//    ofRunApp(new ofApp());
//    ofSetupOpenGL(1080 + 1080, 1920, OF_WINDOW);            // <-------- setup the GL context
//}
//


#include "ofMain.h"
#include "ofApp.h"
//========================================================================

int main( ){
    ofGLFWWindowSettings s;
    s.multiMonitorFullScreen = true;
    ofCreateWindow(s);
    ofRunApp(new ofApp());
    //ofSetupOpenGL(768,1024,OF_WINDOW);            // <-------- setup the GL context
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    //ofRunApp(new ofApp());
}
