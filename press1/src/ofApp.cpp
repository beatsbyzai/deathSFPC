#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::drawZero(float x, float y) {
         
        vector <ofPath> zero = canela.getStringAsPoints("I", true, false);
        for(int z = 0; z < zero.size(); z++) {
            vector < ofPolyline > zeroLines = zero[z].getOutline();
            
            for(int i = 0; i < zeroLines.size(); i++) {
                          ofPushMatrix();
                            ofTranslate((ofGetWidth() / 2) + 50, 0); // translate to right side
                            ofTranslate(x, y); // variables
                            ofScale(binScale);
                            zeroLines[i].draw();
                          ofPopMatrix();
                        }
        }
}


//--------------------------------------------------------------
void ofApp::drawOne(float x, float y) {
         
        vector <ofPath> one = canela.getStringAsPoints("II", true, false);
        for(int o = 0; o < one.size(); o++) {
            vector < ofPolyline > oneLines = one[o].getOutline();
            
            for(int i = 0; i < oneLines.size(); i++) {
                          ofPushMatrix();
                            ofTranslate((ofGetWidth() / 2) + 65, 0); // translate to right side
                            ofTranslate(x, y); // variables
                            ofScale(binScale);
                            oneLines[i].draw();
                          ofPopMatrix();
                        }
        }
}



//--------------------------------------------------------------
void ofApp::setup(){
    
    
    canelaThin.load("canela-thin.ttf", 120, true, true, true);
    canela.load("canela.ttf", 120, true, true, true);
    
    // create new directory of images
    archive.listDir("archive");
    numPhotos = archive.size();
    archive.sort();
    
    
    for (int i = 0; i < numPhotos; i++) {
  
            // load images from directory
            ofImage img;
            archiveImages.push_back(img);
            archiveImages.back().load(archive.getPath(i));
           
         
            // get random positions and sizes for archive photos
            scales.push_back(ofRandom(0.015, 0.12));
            posX.push_back(ofRandom(10,ofGetWidth()/2 - (archiveImages[i].getWidth() * scales[i]) - 10));
            posY.push_back(ofRandom(10, ofGetHeight() - (archiveImages[i].getHeight() * scales[i]) -  10 ));
              
        
            // get random numbers for visual treatments
            randomCircSizeBig.push_back(ofRandom(6));
            randomCircSizeSmall.push_back(ofRandom(2));
            randomSinStart.push_back(ofRandom(20));
            randomShapeNum.push_back(ofRandom(1,2));
            
            focus.push_back(0); 
            reverseFocus.push_back(ofMap(focus[i], 0, 3, 5, 3));
            opacity.push_back(255);
        
             
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

     
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
      
     
      
    
    
//    cout << focus << endl;
    
    int step;

    if(step < 1) {
        step = 1;
    }

    if (step > 100) {
        step -= 1;
    }
     

// GET NUMBER IN BINARY ————————————————————————————————————————————————————
    
    // CALCULATE WHICH KEYS ARE PRESSED THRU keyNumber
    keyNumber = 0;
    
    for(int i = 0; i < 8; i++) {
        if (base[i]) {
             keyNumber += pow(2.0, i);
        }
    }
    
     
    // COUNTER FOR FADING ANIMATION
    
    if (keyDown) {
        
            for (int i = 0; i < numPhotos; i++) {
           
               // FADE IN PHOTOS
               
               focus[keyNumber] += 0.005;

               if (focus[keyNumber] > 3) {
                   focus[keyNumber] = 3;
               }
               
               
           }
        
            if (focus[keyNumber] > 2.75) {
                // GET NEW RANDOM POSITION ON RELEASE
                
                posX[keyNumber] =  ofRandom(10,ofGetWidth()/2 - (archiveImages[keyNumber].getWidth() * scales[keyNumber]) - 10 );
                posY[keyNumber] = ofRandom(10, ofGetHeight() - (archiveImages[keyNumber].getHeight() * scales[keyNumber]) - 10);
                scales[keyNumber] = ofRandom(0.015, 0.12);
            }

        
    }
     
        
        for (int i = 0; i < numPhotos; i++) {
            
            // FADE OUT IMG
            focus[i] -= 0.04;
             
 
                if (focus[i] < 0) {
                    focus[i] = 0;
                }
             
             
        }
 
    cout << focus[1] << endl;
 
 
     
    
// ARCHIVE OF MEMORIES ————————————————————————————————————————————————————
    
    // DRAW ALL PHOTOS IN ARCHIVE
    
    
    
    for(int i = 0; i < numPhotos; i++) {
        
        
        ofPushMatrix();
         
            margin = 250;
            w1 = archiveImages[i].getWidth();
            h1 = archiveImages[i].getHeight();
            w2 = (ofGetWidth() / 2) - margin;
            h2 = (w2 * h1) / w1;
               
        
            // IF KEY NUMBER IS NOT BEING RECALLED, DRAW RANDOM POS X Y AND SIZE W H
 
                if(focus[i] < 3) {
                       archiveImgHeight = h1;
                       archiveImgWidth = w1;
                
                        ofPushMatrix();
                            ofTranslate(posX[i], posY[i]);
                            ofScale(scales[i]);
                
                        shapeSizeSin = sin((ofGetElapsedTimef() + randomSinStart[i]));

                        shapeSize = ofMap(shapeSizeSin, -1, 1, randomCircSizeSmall[i], randomCircSizeBig[i]);
                
                        step = 20;
                        lineT = ofRandom(3);
                        randomRot = ofRandom(360);
                        lineX = shapeSize/2;
                        lineY = ofRandom(1, shapeSize/2);
                    
                    
//                         for(int x = 0; x < archiveImgWidth; x += step * 1.5) {
//                             for(int y = 0; y < archiveImgHeight; y += step * 1.5) {
                    for(int x = 0; x < archiveImgWidth; x += step) {
                        for(int y = 0; y < archiveImgHeight; y += step) {

                                ofColor c = archiveImages[i].getColor(x, y);

 

                                    ofFill();
                                    ofSetColor(c);
                                    ofSetLineWidth(lineT);

                            
                            
                            
                                    if (focus[i] > 0) {
                                        ofDrawLine(
                                        x,
                                        y,
                                        x + (3 - focus[i]),
                                        y + (3 - focus[i]) );
                                    
                                        
                                        
                                        
                                    } else {
                                        
                                        ofDrawLine(
                                             x,
                                             y,
                                             x + lineX,
                                             y + lineY +  (3 - focus[i]) );
                                    }
//

 

                                } //end for y
                         } // end for x
                    
                    ofPopMatrix();
                        
                }
        
        
        
//             IF KEY NUMBER IS BEING RECALLED, DRAW ON RIGHT SIDE
                if(focus[i] > 0) {
                        archiveImgWidth = archiveImages[i].getWidth();
                        archiveImgHeight = archiveImages[i].getHeight();

                        ofPushMatrix();
                            ofTranslate((ofGetWidth() / 2) + (margin/2),
                                        (ofGetHeight() - h2) / 2);
                            ofScale(w2/w1);

                        shapeSizeSin = sin((ofGetElapsedTimef() + randomSinStart[i]));

                        shapeSize = ofMap(shapeSizeSin, -1, 1, randomCircSizeSmall[i], randomCircSizeBig[i]);

                        step = 6;
                        lineT = 1;
                        randomRot = 0;

                        lineX = shapeSize*2;
                        lineY = shapeSize*2;
                    
                    

                         for(int x = 0; x < archiveImgWidth; x += step) {
                             for(int y = 0; y < archiveImgHeight; y += step) {
                                  
                                 
                                ofColor c = archiveImages[i].getColor(x, y);
                                   
                                    ofFill();
                                    ofSetColor(c);
                                    ofDrawCircle(x + ofRandom(1),
                                    y + ofRandom(1),
                                    focus[i] - ofRandom(1) + ofRandom(1));
 
              
                                } //end for y
                         } // end for x
                    
                    ofPopMatrix();
 
                }

         
        
         
        
        
        
//         DRAW PORTAL IN PLACE OF ARCHIVE IMG
        
        ofPushMatrix();

            ofTranslate(posX[i], posY[i]);
            ofScale(scales[i]);

            if (focus[i] > 0) {


                float circleX = 0 + w1 / 2;
                float circleY = 0 + h1 / 2;
                float rad = w1 / 2;

                ofNoFill();
                ofDrawCircle(circleX,
                             circleY,
                             rad);
                }

        ofPopMatrix();

         
      
         
    } // end for i
 
     
    
    
    
    // DRAW BINARY DIGITS
  
    float numberSpace = (ofGetHeight()) / 4;
    ofRectangle zeroRect = canela.getStringBoundingBox("0", 0, 0);
    ofRectangle oneRect = canela.getStringBoundingBox("1", 0, 0);

    float zeroW = zeroRect.width;
    float zeroH = zeroRect.height;
    float oneW = oneRect.width;
    float oneH = oneRect.height;
    
    
    ofNoFill();
    ofSetColor(255);
    
    ofTranslate(0, (ofGetHeight() - ((numberSpace * 4) + (zeroH * 4)) / 2) + 40);
    
    
    
    if(keyDown && base[7]) {
        drawOne(0, 0);
    } else {
        drawZero(0, 0);
    }
    
    
    if(keyDown && base[6]) {
        drawOne(0, 1 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(0, 1 * (numberSpace - zeroH * binScale));
    }
    
    
    if(keyDown && base[5]) {
        drawOne(0, 2 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(0, 2 * (numberSpace - zeroH * binScale));
    }
    
    
    
    if(keyDown && base[4]) {
        drawOne(0, 3 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(0, 3 * (numberSpace - zeroH * binScale));
    }
    
    
    if(keyDown && base[3]) {
        drawOne(ofGetWidth()/2 - 165, 0);
    } else {
        drawZero(ofGetWidth()/2 - 165, 0);
    }
    
    
    if(keyDown && base[2]) {
        drawOne(ofGetWidth()/2 - 165, 1 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(ofGetWidth()/2 - 165, 1 * (numberSpace - zeroH * binScale));
    }
    
    
    if(keyDown && base[1]) {
        drawOne(ofGetWidth()/2 - 165, 2 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(ofGetWidth()/2 - 165, 2 * (numberSpace - zeroH * binScale));
    }
    
        
        
    if(keyDown && base[0]) {
        drawOne(ofGetWidth()/2 - 165, 3 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(ofGetWidth()/2 - 165, 3 * (numberSpace - zeroH * binScale));
    }
        
    
    
    
    
    
//        ofPushMatrix();
    
//            // 0,0
//            for(int i = 0; i < zeroLines.size(); i++) {
//              ofPushMatrix();
//                ofTranslate((ofGetWidth() / 2) + 50, 100);
//
//                ofTranslate(0, 0);
//                ofScale(0.5);
//                zeroLines[i].draw();
//              ofPopMatrix();
//            }
//
//
//            // 0,1
//            for(int i = 0; i < zero.size(); i++) {
//            ofPushMatrix();
//                ofTranslate((ofGetWidth() / 2) + 50, 100);
//              ofTranslate(0, 1 * (numberSpace - zeroH));
//                ofScale(0.5);
//                  zero[i].draw();
//            ofPopMatrix();
//            }
//
//
//            // 0,2
//            for(int i = 0; i < zero.size(); i++) {
//            ofPushMatrix();
//                ofTranslate((ofGetWidth() / 2) + 50, 100);
//
//              ofTranslate(0, 2 * (numberSpace - zeroH));
//                ofScale(0.5);
//                  zero[i].draw();
//            ofPopMatrix();
//            }
//
//
//            // 0,3
//            for(int i = 0; i < zero.size(); i++) {
//            ofPushMatrix();
//                ofTranslate((ofGetWidth() / 2) + 50, 100);
//              ofTranslate(0, 3 * (numberSpace - zeroH));
//                ofScale(0.5);
//                  zero[i].draw();
//            ofPopMatrix();
//            }
//
    
    
    
    
    
    
    
//        // (1,1)
//        canela.drawString(
//        "0",
//        0,
//        0 * (numberSpace - zeroH));
//
//        // (1,2)
//        canela.drawString(
//        "0",
//        0,
//        1 * (numberSpace - zeroH));
//
//        // (1,3)
//        canela.drawString(
//        "0",
//        0,
//        2 * (numberSpace - zeroH));
//
//        // (1,4)
//        canela.drawString(
//        "0",
//        0,
//        3 * (numberSpace - zeroH));
//
//        // (2,1)
//        canela.drawString(
//        "0",
//        ofGetWidth()/2 - zeroW,
//        0 * (numberSpace - zeroH));
//
//        // (2,2)
//        canela.drawString(
//        "0",
//        ofGetWidth()/2 - zeroW,
//        1 * (numberSpace - zeroH));
//
//        // (2,3)
//        canela.drawString(
//        "0",
//        ofGetWidth()/2 - zeroW,
//        2 * (numberSpace - zeroH));
//
//        // (2,4)
//        canela.drawString(
//        "0",
//        ofGetWidth()/2 - zeroW - 105,
//        3 * (numberSpace - zeroH));
//
    
    
    
    
    ofPopMatrix();
     
     
    
    
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







                                       
                //                // DRAW WHITE RECT UNDER IMG
                //                ofSetColor(255);
                //                ofDrawRectangle((ofGetWidth() / 2) + 50,
                //                                (ofGetHeight() - h2) / 2,
                //                                w2,
                //                                h2);
                //
                //
                //                // DRAW FULL NON-PIXEL IMG
                //                archiveImages[i].draw(
                //                                      (ofGetWidth() / 2) + 50,
                //                                      (ofGetHeight() - h2) / 2,
                //                                      w2,
                //                                      h2);
                //

                
