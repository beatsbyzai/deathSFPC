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
        ofRectangle oneRect = canela.getStringBoundingBox("1", 0, 0);
    
    
        for(int o = 0; o < one.size(); o++) {
            vector < ofPolyline > oneLines = one[o].getOutline();
            
            
            for(int i = 0; i < oneLines.size(); i++) {
                          ofPushMatrix();
                            ofTranslate((ofGetWidth() / 2) + 60 - (oneRect.width / 2), 0); // translate to right side
                            ofTranslate(x, y); // variables
                            ofScale(binScale);
                            oneLines[i].draw();
                          ofPopMatrix();
                        }
        }
}



//--------------------------------------------------------------
void ofApp::setup(){
     
    // serial settings
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup(0, baud);
    
    
     
    // display settings
    ofSetCircleResolution(20);
    
    // load fonts
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
            scales.push_back(ofRandom(0.010, 0.12));
            posX.push_back(ofRandom(10, (ofGetWidth()/2 - ((archiveImages[i].getWidth() * scales[i]))) - 20));
            posY.push_back(ofRandom(10, (ofGetHeight() - ((archiveImages[i].getHeight() * scales[i]))) -  10 ));
              
        
            // get random numbers for visual treatments
            randomCircSizeBig.push_back(ofRandom(6));
            randomCircSizeSmall.push_back(ofRandom(2));
            randomSinStart.push_back(ofRandom(20));
            randomShapeNum.push_back(ofRandom(1,2));
            randomPixelSpacing.push_back(ofRandom(1,3));
            
            focus.push_back(0); 
            reverseFocus.push_back(ofMap(focus[i], 0, 3, 5, 3));
            opacity.push_back(255);
        
             
    }
    
    
}






//--------------------------------------------------------------
void ofApp::update(){
    
    if(serial.available()){
    
        
         if (receiveString == "zero1" || receiveString == "one1" || receiveString == "two1" || receiveString == "three1" || receiveString == "four1" || receiveString == "five1" || receiveString == "six1" || receiveString == "seven1" ) {
                keyDown = true;
         }
        
        
        receiveString = ofxGetSerialString(serial, '\n'); //read until end of line

        
        // 7 booleans for each one
        // draw if boolean is true in DRAW
        
        
        if (receiveString == "zero1") { // key 0
            base[0] = true;
            
        } else if (receiveString == "zero0") { // key 0
            base[0] = false;
        }
        if (receiveString == "one1") { // key #1
            base[1] = true;
        } else if (receiveString == "one0") { // key #1
            base[1] = false;
        }
            
        if (receiveString == "two1") { // key #2
            base[2] = true;
        } else if (receiveString == "two0") { // key #2
            base[2] = false;
        }
            
        if (receiveString == "three1") { // key #3
            base[3] = true;
        } else if (receiveString == "three0") { // key #3
            base[3] = false;
        }
            
        if (receiveString == "four1") { // key #4
            base[4] = true;
        } else if (receiveString == "four0") { // key #4
            base[4] = false;
        }
            
        if (receiveString == "five1") { // key #5
            base[5] = true;
        } else if (receiveString == "five0") { // key #5
            base[5] = false;
        }
            
        if (receiveString == "six1") { // key #6
            base[6] = true;
        } else if (receiveString == "six0") { // key #6
            base[6] = false;
        }
            
        if (receiveString == "seven1") { // key #7
            base[7] = true;
        } else if (receiveString == "seven0") { // key #7
            base[7] = false;
         
        }
             
        
    }
        
}

string ofApp::ofxGetSerialString(ofSerial &serial, char until) {
    static string str;
    stringstream ss;
    char ch;
    int ttl = 1000;
    while ((ch = serial.readByte())>0 && (ttl--) > 0 && ch != until) {
        ss << ch;
    }
    str += ss.str();
    if (ch == until) {
        string tmp = str;
        str = "";
        return ofxTrimString(tmp);
    }
    else {
        return "";
    }
}

// trim right trailing spaces
string ofApp::ofxTrimStringRight(string str) {
    size_t endpos = str.find_last_not_of(" \t\r\n");
    return (string::npos != endpos) ? str.substr(0, endpos + 1) : str;
}

// trim left trailing spaces
string ofApp::ofxTrimStringLeft(string str) {
    size_t startpos = str.find_first_not_of(" \t\r\n");
    return (string::npos != startpos) ? str.substr(startpos) : str;
}

// trim trailing spaces
string ofApp::ofxTrimString(string str) {
    return ofxTrimStringLeft(ofxTrimStringRight(str));;
}






//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    
     
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofDrawLine(ofGetWidth() / 2 , 0, ofGetWidth() / 2, ofGetHeight());
      
    cout << receiveString << endl;
    
    ofSetColor(255,0,0);
    
    
//    if (magBase[7]) {
//        ofFill();
//        ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, 100, 100);
//    } else if (magBase[7]  == false) {
//        ofNoFill();
//        ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, 100, 100);
//
//    }

        
 
    
    
    
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
    magKeyNumber = 0;
    randomPixelSpacing[keyNumber] = 1;
    
    
    for(int i = 0; i < 8; i++) {
        if (base[i]) {
             keyNumber += pow(2.0, i);
        }
    }
    
    
    for(int i = 0; i < 8; i++) {
        if (magBase[i]) {
             magKeyNumber += pow(2.0, i);
        }
    }
    
     
    // COUNTER FOR FADING ANIMATION
    
    if (keyDown) {
        
            for (int i = 0; i < numPhotos; i++) {
           
               // FADE IN PHOTOS
                
               focus[keyNumber] += 0.002;

               if (focus[keyNumber] > 3) {
                   focus[keyNumber] = 3;
               }
               
               
           }
        
        
        randomPixelSpacing[keyNumber] -= 1;
        
        if (randomPixelSpacing[keyNumber] < 1) {
            randomPixelSpacing[keyNumber] = 1;
        }
        
//        if (focus[keyNumber] > 0 && focus[keyNumber] < 2.75) {
//            randomPixelSpacing[keyNumber] -= 1;
//
//            if (randomPixelSpacing[keyNumber] < 1) {
//                randomPixelSpacing[keyNumber] = 1;
//            }
//        }
        
            if (focus[keyNumber] > 2.75) {
                // GET NEW RANDOM POSITION ON RELEASE
                
                posX[keyNumber] =  ofRandom(10, (ofGetWidth()/2 - (archiveImages[keyNumber].getWidth() * scales[keyNumber])) - 10 );
                posY[keyNumber] = ofRandom(10, (ofGetHeight() - (archiveImages[keyNumber].getHeight() * scales[keyNumber])) - 10);
                scales[keyNumber] = ofRandom(0.015, 0.12);
                randomPixelSpacing[keyNumber] = ofRandom(1,3);
                
            }

        
    }
     
        
        for (int i = 0; i < numPhotos; i++) {
            
            // FADE OUT IMG
            focus[i] -= 0.04;
             
 
                if (focus[i] < 0) {
                    focus[i] = 0;
                }
             
             
        }
 
//    cout << focus[1] << endl;
 
 
     
    
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
                    for(int x = 0; x < archiveImgWidth; x += step * randomPixelSpacing[i]) {
                        for(int y = 0; y < archiveImgHeight; y += step * randomPixelSpacing[i]) {

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

         
        
         
        
        
        
        // DRAW PORTAL IN PLACE OF ARCHIVE IMG
        
        ofPushMatrix();
//            ofNoFill();
//            ofSetLineWidth(focus[i] );
        
            ofTranslate(posX[i], posY[i]);
            ofScale(scales[i]);

            if (focus[i] > 0) {


//                float circleX = w1 / 2;
//                float circleY = h1 / 2;
//                float rad = w1 / 2;
//
//                float xOrigin = circleX;
//                float yOrigin = circleY;
//
//                ofDrawCircle(circleX,
//                             circleY,
//                             rad);
                
                
                for(int x = 0; x < 10; x++) {
                    float xOrig = w1 / 2;
                    float yOrig = h1 / 2;
                    float rad = w1 / 2;
                    float circW = (2 / scales[i]) * focus[i];
                    
                     //  + ((h1 - rad) / 2)
                    
                    float iMap = ofMap(x, 0, 10, 0, 2*PI);
                    
                    ofDrawCircle((xOrig) + cos(iMap + ofGetElapsedTimef()) * rad,
                                 (yOrig) + sin(iMap + (ofGetElapsedTimef() * focus[i]) ) * rad,
                                 circW);
                }
                
                
                
                
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
    
    
    ofSetLineWidth(1);
     
    
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
        drawOne(((ofGetWidth() / 2) - 250/2), 0);
    } else {
        drawZero(((ofGetWidth() / 2) - 250/2), 0);
    }
    
    
    if(keyDown && base[2]) {
        drawOne(((ofGetWidth() / 2) - 250/2), 1 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(((ofGetWidth() / 2) - 250/2), 1 * (numberSpace - zeroH * binScale));
    }
    
    
    if(keyDown && base[1]) {
        drawOne(((ofGetWidth() / 2) - 250/2), 2 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(((ofGetWidth() / 2) - 250/2), 2 * (numberSpace - zeroH * binScale));
    }
    
        
        
    if(keyDown && base[0]) {
        drawOne(((ofGetWidth() / 2) - 250/2), 3 * (numberSpace - zeroH * binScale));
    } else {
        drawZero(((ofGetWidth() / 2) - 250/2), 3 * (numberSpace - zeroH * binScale));
    }
        
    
     
    
    
    
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

                
