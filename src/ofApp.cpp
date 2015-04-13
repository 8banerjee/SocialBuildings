#include "ofApp.h"

#include "ofUtils.h"
#include "ofImage.h"
#include "ofTypes.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

#include "Poco/String.h"
#include "Poco/LocalDateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/URI.h"

#include <cctype>


//--------------------------------------------------------------
void ofApp::setup(){

	//cout << getWorkingDir().toString();
	//svg.load("window.svg");
	
	//ofBackground(0,0,0);  

	ofPolyline polyline;

	windmill_blades_svg.load("dyn_windmill_blades.svg");
	
	//for (int i = 0; i < svg.getNumPath(); i++){
	//	ofPath p = svg.getPathAt(i);
	//	// svg defaults to non zero winding which doesn't look so good as contours
	//	p.setPolyWindingMode(OF_POLY_WINDING_ODD);
	//	vector<ofPolyline>& lines = p.getOutline();
	//	for(int j=0;j<(int)lines.size();j++){
	//		outlines.push_back(lines[j].getResampledBySpacing(1));
	//	}
	//}

	background_map = ofImage("bg_1024_768_map.jpg");
	window_large = ofImage("dyn_window_large.png");
	window_small = ofImage("dyn_window_small.png");
	window_square = ofImage("dyn_window_square.png");

	windmill_blades = ofImage("dyn_windmill_blades.png");

	// Loading downloaded movies from open archives
	brouwerij_video.loadMovie("brouwerij1.mp4");
	tropen_video.loadMovie("Tropenmuseum.mp4");
	
	deg = 0;

}


//--------------------------------------------------------------
void ofApp::update(){
	deg += 1;

	// Updating the frames of the video player
	brouwerij_video.update();

	tropen_video.update();
	


}

void ofApp::draw(){
    
	//svg_background.draw();
	
	background_map.draw(0,0);

	//ofSetColor(1,34,25);
	
	//polyline.draw();

	//ofColor a = redColor;
	//ofSetColor(128);

	//path.setStrokeColor(a);
	//path.setFilled(false);
	//path.setStrokeWidth(5);
	//path.setCurveResolution(200);

	//
	//path.moveTo(20,20);
 //   path.lineTo(40,20);
 //   path.lineTo(40,40);
 //   path.lineTo(20,40);
 //   path.close();

	//path.draw();

	/*for (int i = 0; i < (int)outlines.size(); i++){
			ofPolyline & line = outlines[i];

			int num = step * line.size();

			ofBeginShape();
			for (int j = 0; j < num; j++){
				ofVertex(line[j]);
			}
			ofEndShape();
		}*/

	// SVG stuff windmill rotation
	//ofTranslate(655,17,0);
	//ofRotate(x,0,0,1);
	//windmill_blades_svg.draw();

	// 2D Matrix transformation method
	ofPushMatrix();
      ofTranslate(windmill_blades.width/2 + 764, windmill_blades.height/2 + 53, 0);//move pivot to centre
      ofRotate(deg, 0, 0, 1);//rotate from centre
	  /*ofTranslate*/
      ofPushMatrix();
          ofTranslate(-windmill_blades.width/2,-windmill_blades.height/2,0);//move back by the centre offset
		  
          windmill_blades.draw(0,0);
      ofPopMatrix();
    ofPopMatrix();

	// Window flashing -- triggered by ?
	// Social media trigger? 

	frame = ofGetFrameNum();
	s = rand() % 3 + 1;

	if(frame % 7 == 0 || frame % 3 == 0 ){

		switch(s) {
		case 1: 
			window_large.draw(568, 552);
			break;
		case 2:
			window_small.draw(434, 571);
			break;
		case 3:
			window_square.draw(365, 609);
			break;
		}	
		
	}

	/*for(int x = 0; x < 500; x++) {

		ofTranslate(x, y, 0);
	}
*/
	
	// Video rendering 
	brouwerij_video.draw(782, 354, 177, 116);	
	brouwerij_video.play();
	tropen_video.draw(333,235,220,144);
	tropen_video.play();
    
	
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
