#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // create new directory of images
    archive.listDir("archive");
    numPhotos = archive.size();
    archive.sort();
    
    
    for (int i = 0; i < numPhotos; i++) {
  
            // load images from directory
            ofImage img;
            archiveImages.push_back(img);
            archiveImages.back().load(archive.getPath(i));
         
            // random positions and sizes
            posX.push_back(ofRandom(10,ofGetWidth()/2 ));
            posY.push_back(ofRandom(10, ofGetHeight() - 20));
            scales.push_back(ofRandom(0.05, 0.2));
        
            // random visual treatments
            randomCircSizeBig.push_back(ofRandom(6));
            randomCircSizeSmall.push_back(ofRandom(2));
            randomSinStart.push_back(ofRandom(20));
            randomShapeNum.push_back(ofRandom(1,2));
        
         
//             cout << randomShapeNum[x] << endl;
            
         
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

     
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
       
    
    int step = 20;

    if(step < 1) {
        step = 1;
    }

    if(step > 100) {
        step -= 1;
    }
     

// ARCHIVE ————————————————————————————————————————————————————
    
    // calculate which keys are pressed through keyNumber
    int keyNumber = 0;
    
    for(int i = 0; i < 8; i++) {
        if (base[i]) {
             keyNumber += pow(2.0, i);
     }
    }
        
         

    focus += 1;
    
    
// ARCHIVE ————————————————————————————————————————————————————
    
    // draw all photos into the archive
    
    for(int i = 0; i < numPhotos; i++) {
        ofPushMatrix();
        
            // SCALE IMGE AND POS IMG RANDOMLY
            ofTranslate(posX[i], posY[i]);
            ofScale(scales[i]);
 
        
            for(int x = 0; x < archiveImages[i].getWidth(); x += step) {
                
                 for(int y = 0; y < archiveImages[i].getHeight(); y += step) {
                     
                    ofColor c = archiveImages[i].getColor(x, y);

                    ofSetColor(c);

                    float circleSizeSin = sin((ofGetElapsedTimef() + randomSinStart[i]));

                    float circleSize = ofMap(circleSizeSin, -1, 1, randomCircSizeSmall[i], randomCircSizeBig[i]);
 
                     
                     
//
//                         ofDrawCircle(x  ,
//                         y,
//                         circleSize);


                     
                         ofSetLineWidth(ofRandom(3));

                         if (keyNumber != i+1) {
                             ofDrawLine(x,
                                        y,
                                        x + circleSize/2,
                                        y + ofRandom(1, circleSize/2 + 5)) ;

                         }
                     
                     
                     
                     
                     
                     
                     
                             
                            
                    }
             }
           
        
        ofPopMatrix();
          

        if (keyNumber == i+1) {
                
            //draw white rect under img
                ofSetColor(255);
                ofDrawRectangle(ofGetWidth() / 2, 0 , ofGetWidth() / 2, ofGetHeight());
            
//            draw large img
                archiveImages[i].draw(ofGetWidth() / 2, 0 , ofGetWidth() / 2, ofGetHeight() );
            
                    
            
//                ofPushMatrix();
//                ofTranslate(
//                            ofGetWidth()/2 + ((ofGetWidth()/2 - archiveImages[i].getWidth())/2),
//                            (ofGetHeight() - archiveImages[i].getHeight()) / 2);
//
//
//
//
//
//                        for(int x = 0; x < archiveImages[i].getWidth(); x += keyImageGrow) {
//                           for(int y = 0; y < archiveImages[i].getHeight(); y += keyImageGrow) {
//
//                               ofColor c = archiveImages[i].getColor(x, y);
//
//                               if (keyDown) {
//                                   keyImageGrow = focus / 3;
//                               } else {
//                                   focus = 0;
//                                   keyImageGrow = 2.0;
//                               }
//
//                               if(keyImageGrow < 1) {
//                                   keyImageGrow = 1;
//                               }
//
//                               ofSetColor(c);
//                               ofDrawCircle(x, y, keyImageGrow/2.0);
//
//                           }
//                        }
//                ofPopMatrix();
//
//
//
             }
    }
//
     
// ///////////////
    // DRAW KEY IMAGE ON RIGHT HALF
    
     
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keyDown = true;
    
     
     
    
    if (key == 48) { // key 0
        base[0] = true;
    }
    
    if (key == 49) { // key #1
        base[1] = true;
    }
    if (key == 50) { // key #2
        base[2] = true;
    }
    if (key == 51) { // key #3
        base[3] = true;
    }
    if (key == 52) { // key #4
        base[4] = true;
    }
    if (key == 53) { // key #5
        base[5] = true;
    }
    if (key == 54) { // key #6
        base[6] = true;
    }
    if (key == 55) { // key #7
        base[7] = true;
    }
    
    
      
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyDown = false;
    
//    keyNumber = 0;
//    keyImageGrow = 2;
    
    
    
    if (key == 48) { // key 0
           base[0] = false;
       }
       
       if (key == 49) { // key #1
           base[1] = false;
       }
       if (key == 50) { // key #2
           base[2] = false;
       }
       if (key == 51) { // key #3
           base[3] = false;
       }
       if (key == 52) { // key #4
           base[4] = false;
       }
       if (key == 53) { // key #5
           base[5] = false;
       }
       if (key == 54) { // key #6
           base[6] = false;
       }
       if (key == 55) { // key #7
           base[7] = false;
       }

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
