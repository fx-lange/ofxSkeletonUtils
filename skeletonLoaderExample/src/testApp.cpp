#include "testApp.h"

//--------------------------------------------------------------
void skeletonLoaderApp::setup() {
	ofBackground(0, 0, 0);

	startFrame = 10;

	filename = "5Try";
	player.loadMovie(filename+".mov");
	player.play();

	skeletonRecorder.setupForPlayback(filename+".xml",&player);
}


//--------------------------------------------------------------
void skeletonLoaderApp::update(){
	skeletonRecorder.update();

	if(eNextFrame){
		eNextFrame = false;
		skeletonRecorder.nextFrame();
	}else if(ePrevFrame){
		ePrevFrame = false;
		skeletonRecorder.prevFrame();
	}

	skeletonRecorder.play();
}

//--------------------------------------------------------------
void skeletonLoaderApp::draw(){

	player.draw(0,0);
	skeletonRecorder.drawSkeleton();

	stringstream msg;
	msg
	<< "    fps     : " << ofGetFrameRate() << endl
	<< " framecount : " << skeletonRecorder.getFrameCount() << endl
	<< "frame player: " << player.getCurrentFrame() << endl
	<< "frame offset: " << skeletonRecorder.getFrameOffset() << endl
	<< "start frame : " << startFrame << endl
	<< " used frame : " << skeletonRecorder.getFrameCountInUse() << endl
	<< "player time : " << player.getPosition()*player.getDuration() << endl;
	ofDrawBitmapString(msg.str(), 20, 560);

}

//--------------------------------------------------------------
void skeletonLoaderApp::keyPressed(int key){

	switch (key) {
		case 's':
			skeletonRecorder.saveXmlToFile(filename+".xml");
			break;
		case 'r':
			skeletonRecorder.firstFrame();
			break;
		case OF_KEY_LEFT:
			ePrevFrame = true;
			break;
		case OF_KEY_RIGHT:
			eNextFrame = true;
			break;
		case '+':
			skeletonRecorder.incFrameOffset();
			break;
		case '-':
			skeletonRecorder.decFrameOffset();
			break;
		case 'q':
			startFrame++;
			skeletonRecorder.setStartFrame(startFrame);
			break;
		case 'a':
			startFrame--;
			skeletonRecorder.setStartFrame(startFrame);
			break;
		case 'p':
			skeletonRecorder.setPaused(true);
			skeletonRecorder.enableGrabbing();
			break;
		default:
				break;
	}
}


//--------------------------------------------------------------
void skeletonLoaderApp::keyReleased(int key){

}

//--------------------------------------------------------------
void skeletonLoaderApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void skeletonLoaderApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void skeletonLoaderApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void skeletonLoaderApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void skeletonLoaderApp::windowResized(int w, int h){

}

void skeletonLoaderApp::exit(){
	player.close();
}

