#pragma once

#include "ofMain.h"
#include "ofxSVG.h"

/*
 By Andreas Borg
 crea.tion.to
 */

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxSVG windmill_blades_svg;
		ofxSVG svg_background;
		/*ofxSVG window_large;
		ofxSVG window_small;
		ofxSVG window_square;*/

		ofPolyline polyline;
		ofPath path;

		ofImage background_map;
		ofImage windmill_blades;
		ofImage window_large;
		ofImage window_small;
		ofImage window_square;

		vector<ofPolyline> outlines;

		int deg;
		int y;

		ofVideoPlayer brouwerij_video;
		ofVideoPlayer tropen_video;

		// Other variables
		int frame;
		int s;
		
};
