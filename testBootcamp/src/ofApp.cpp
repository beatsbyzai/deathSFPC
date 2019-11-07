#include "ofApp.h"


void Particle:: setup (ofPoint ParticlePos) {
    //    define radius
    rad = ofRandom(2,5);
    
    pos = ParticlePos;
    
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //    define x and y values of position
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    
    //    define x and y of direction
    dir.x = ofRandom(-10, 10);
    dir.y = ofRandom(-10, 10);
    
}

void Particle:: update () {
    dir.y = dir.y + 0.2;
    
    pos = pos + dir;
    
    //    SHORTHAND FOR
    //    pos.x = pos.x + dir.x
    //    pos.y = pos.y + dir.y
    
    
    
    //    if position in the x is past the left edge of screen, bring ball back and change its direction
    if(pos.x < rad) {
        pos.x = rad;
        dir.x = -dir.x;
    }
    
    if(pos.y < rad) {
        pos.y = rad;
        dir.y = -dir.y;
    }
    
    if(pos.x > ofGetWidth() - rad) {
        pos.x = ofGetWidth() - rad;
        dir.x = -dir.x;
    }
    
    if(pos.y > ofGetHeight() - rad) {
        pos.y = ofGetHeight() - rad;
        dir.y = -dir.y;
    }
}





void Particle:: draw () {
    ofSetColor(color);
    
    //    draw circle at random
    ofDrawCircle(pos.x, pos.y, rad);
    
    
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofPoint random;
    random.x = ofRandom(ofGetWidth());
    random.y = ofRandom(ofGetHeight());
    
    
//    1000 create a particle and add to array, and push to particles vector
    for(int i = 0; i < 1000; i++) {
//        create 1000 instances of Particles
        Particle p;
        
        
//        setup 1000 times
        p.setup(random);
//        add to array
        particles.push_back(p);
    }
    
 
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    run Particles update function many times
    for(int i = 0; i < particles.size(); i++) {
         particles[i].update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
//    run Particle draw function many times
    for(int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
