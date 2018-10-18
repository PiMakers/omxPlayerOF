#pragma once

#include "ofMain.h"
#include "ofxomxPlayerOF.h"
#include "puBHubPlayer.h"
#include "omxplayer.h"

#warning WARNING;
///*H
#include "OmxPubHubPlayer.h"
/// #include "ofxPubHubPlayer.h"
/// #include "ofxPubHubBasePlayer.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

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

		puBHubPlayer *phPlayer02 = new puBHubPlayer;

        OmxPubHubPlayer *phPlayer = new OmxPubHubPlayer;
///		OmxPubHubPlayer *phPlayer02 = new OmxPubHubPlayer;
		ofVideoPlayer videoPlayer;

};
