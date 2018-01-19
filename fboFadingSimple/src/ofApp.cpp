#include "ofApp.h"

ofFbo fbo, spFbo;  // our regular fbo and "scratchpad" fbo
ofColor ball(100,0,200);
ofColor black(0,0,0);

//--------------------------------------------------------------
void ofApp::setup(){
  //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);  // lower precision. leaves artifacts. way faster.
  fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
  spFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);   // not doing any blending here.  no alpha needed 
  
  fbo.begin();
    ofClear(255,255,255, 0);
  fbo.end();
  
  spFbo.begin();
    ofClear(255,255,255, 0);
  spFbo.end();
  
  ofSetBackgroundColor(black);
}

//--------------------------------------------------------------
void ofApp::update(){
}

int mouseX = 0;
int mouseY = 0;

//--------------------------------------------------------------
void ofApp::draw(){
  fbo.begin();
    ofSetColor(black, 10); // background color with alpha  / change color for halo effect
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(ball);
    ofNoFill();
    ofDrawCircle(mouseX, mouseY, 50);
    ofFill();
  fbo.end();
  
  spFbo.begin();  // write the existing fbo to the scratchpad but a bit smaller
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(10, 10, ofGetWidth()-20, ofGetHeight()-20);
  spFbo.end(); 
  
  fbo = spFbo;    // write the scratchpad back to the original
  
  ofSetColor(255,255,255);  // always set the color before drawing the fbo
  fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  mouseX = x;
  mouseY = y;
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
