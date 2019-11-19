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
           
         
            // get random positions and sizes for archive photos
            scales.push_back(ofRandom(0.02, 0.15));
            posX.push_back(ofRandom(5,ofGetWidth()/2 - (archiveImages[i].getWidth() * scales[i]) - 5 ));
            posY.push_back(ofRandom(5, ofGetHeight() - (archiveImages[i].getHeight() * scales[i]) - 5 ));
              
        
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
    
    // calculate which keys are pressed through keyNumber
    keyNumber = 0;
    
    for(int i = 0; i < 8; i++) {
        if (base[i]) {
             keyNumber += pow(2.0, i);
        }
    }
    
     
    // counter for fading animation
    
    if (keyDown) {
//        focus[keyNumber] = 20;
        
            for (int i = 0; i < numPhotos; i++) {
           
               // FADE IN
               
               focus[keyNumber] += 0.01;
               
               opacity[keyNumber] -= 1;

               if (focus[keyNumber] > 3) {
                   focus[keyNumber] = 3;
                   
               }
               
               
           }

        // GET NEW RANDOM POSITION ON RELEASE
        
        posX[keyNumber] =  ofRandom(10,ofGetWidth()/2 - (archiveImages[keyNumber].getWidth() * scales[keyNumber]) - 10 );
        posY[keyNumber] = ofRandom(10, ofGetHeight() - 20);
        scales[keyNumber] = ofRandom(0.05, 0.2);
         
    }
    
//    else {
        
        for (int i = 0; i < numPhotos; i++) {
            
            // FADE OUT
            focus[i] -= 0.04;
             
 
                if (focus[i] < 0) {
                    focus[i] = 0;
                }
            
            opacity[keyNumber] += 1;
            
             
            
        }
         
//    }
    
     
 
 
     
    
// ARCHIVE OF MEMORIES ————————————————————————————————————————————————————
    
    // DRAW ALL PHOTOS IN ARCHIVE
    
    
    
    for(int i = 0; i < numPhotos; i++) {
        
        
        ofPushMatrix();
         
        
            w1 = archiveImages[i].getWidth();
            h1 = archiveImages[i].getHeight();
            w2 = (ofGetWidth() / 2) - 100;
            h2 = (w2 * h1) / w1;
               
        
            // IF KEY NUMBER IS NOT BEING RECALLED, DRAW RANDOM POS X Y AND SIZE W H
 
                if(focus[i] == 0) {
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
                        lineY = ofRandom(1, shapeSize/2 + reverseFocus[i]);
                    
                    
                         for(int x = 0; x < archiveImgWidth; x += step) {
                             for(int y = 0; y < archiveImgHeight; y += step) {
                                  
                                 
                                ofColor c = archiveImages[i].getColor(x, y);
                                 
                                   
                                if (focus[i] == 0) { // IF NOT BEING RECALLED, DRAW ARCHIVE

                                    ofFill();
                                    ofSetColor(c);
                                    ofSetLineWidth(lineT);
                                    
                                    ofDrawLine(
                                          x,
                                          y,
                                          x + lineX,
                                          y + lineY);
        //
                                    }
              
                                } //end for y
                         } // end for x
                    
                    ofPopMatrix();
                        
                }
        
        
        
//             IF KEY NUMBER IS BEING RECALLED, DRAW ON RIGHT SIDE
                if(focus[i] > 0) {
                        archiveImgWidth = archiveImages[i].getWidth();
                        archiveImgHeight = archiveImages[i].getHeight();

                        ofPushMatrix();
                            ofTranslate((ofGetWidth() / 2) + 50,
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
                                  
                                if (focus[i] > 0) { // IF BEING RECALLED, DRAW ON RIGHT

                                    ofFill();
                                    ofSetColor(c);
                                    ofDrawCircle(x + ofRandom(1),
                                    y + ofRandom(1),
                                    focus[i] );

                                }
              
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

                ofDrawCircle(circleX,
                             circleY,
                             rad);
                }

        ofPopMatrix();
        
         
      
         
    } // end for i
 
     
 
    
    
    
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

                
