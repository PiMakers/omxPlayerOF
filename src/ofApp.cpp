#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
/// char* argv[] = { "OmxPlayerOF", "/mnt/LinuxData/Videos/00Timecoded_Big_bunny_1.mov" , "--loop", "-r", "-b" };
    char* argv[] = { "OmxPlayerOF", "--loop",/* "-r", "-b", */"--layer", "-1", "--alpha", "255", "--win", "0,0,500,960", "/mnt/LinuxData/Videos/00Timecoded_Big_bunny_1.mov"  };
int argc = sizeof (argv)/4;
/*
if (phPlayer) { phPlayer->omxPlayerCli( argc, argv); }
*/

/// omxplayer ( argc, argv );

char* argV[] = { "OmxPlayerOF", "--loop",/* "-r", "-b", */"--layer", "-1", "--alpha", "255", "--win", "300,0,600,500", "/mnt/LinuxData/Videos/1.mp4"  };
argc = sizeof (argV)/4;
if (phPlayer02) {
    phPlayer02->omxPlayerCli( argc, argV);
}

videoPlayer.load("/mnt/LinuxData/Videos/2.mp4" );
videoPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoPlayer.draw(450, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::exit(){
/*
    if (phPlayer02) delete phPlayer02;
    if (phPlayer) delete phPlayer;
    ofLogError(__func__) << "#####################";   sleep(1000000);
*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'y') {
        phPlayer->m_keyboard->send_action('p');
        phPlayer02->m_keyboard->send_action('p');
        ofLogNotice(__func__) << "key pressed: " << key;
    }
    ofLogNotice(__func__) << "key pressed: " << key;

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
