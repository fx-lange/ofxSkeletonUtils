/*
 * ofxSkeletonInput.cpp
 *
 *  Created on: Jun 20, 2012
 *      Author: spta32
 */

#include "ofxSkeletonInput.h"

ofxSkeletonInput::ofxSkeletonInput() {
	// TODO Auto-generated constructor stub

}

ofxSkeletonInput::~ofxSkeletonInput() {
	// TODO Auto-generated destructor stub
}

void ofxSkeletonInput::setup(string videoFile, string xmlFilename, bool useVideoPlayer){
	ofxCvVideoInput::setup(videoFile);
	filename = xmlFilename;
	frameCount = 0;
	bUsePlayer = useVideoPlayer;
	bUpdate = false;
	frameOffset = 0;

	loadXmlFile(xmlFilename);
	firstFrame();

	if(bUsePlayer){
		int xmlFrames = xml.getNumTags("frame");
		frameFactor = (double)xmlFrames / (double)player.getTotalNumFrames();
	}else{
		frameFactor = 1.;
	}
}

void ofxSkeletonInput::loadXmlFile(string filename){
	xml.loadFile(filename);
	frameOffset = xml.getValue("frameOffset",0);
	startFrame = xml.getValue("startFrame",0);
	endFrame = xml.getValue("endFrame",600);
}

void ofxSkeletonInput::saveXmlToFile(string filename){
	if(bUsePlayer){
		if(!bPlay)
			updateFrameToXml();
		xml.setValue("frameOffset",frameOffset);
	}
	xml.saveFile(filename);
}

void ofxSkeletonInput::update(){
	if(bUsePlayer){
		ofxCvVideoInput::update();
	}
}

bool ofxSkeletonInput::useFrame(){
	if(getFrameCountInUse()>endFrame){
		setPaused(true);
//		ofSaveFrame(); //TODO grabScreen() crashes - PBO conflict
	}
	bUpdate = false;
	if(bPlay){
		if(bUsePlayer){
			if(player.isFrameNew()){
				frameCount = player.getCurrentFrame();
				bUpdate = true;
			}
		}else{
			frameCount++;
			bUpdate = true;
		}
	}

	loadFrameFromXml();

	return bUpdate;
}

void ofxSkeletonInput::drawDataLayer(float x, float y){
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x,y);

	skeleton.head.draw();
	skeleton.leftHand.draw();
	skeleton.rightHand.draw();
	skeleton.leftFoot.draw();
	skeleton.rightFoot.draw();

	skeleton.leftElbow.draw();
	skeleton.rightElbow.draw();
	skeleton.leftKnee.draw();
	skeleton.rightKnee.draw();

	skeleton.leftUpperTorso.draw();
	skeleton.rightUpperTorso.draw();
	skeleton.leftLowerTorso.draw();
	skeleton.rightLowerTorso.draw();

	ofPopMatrix();
	ofPopStyle();
}

void ofxSkeletonInput::loadFrameFromXml(){
	if(!bUpdate){
		return;
	}

	int frame = getFrameCountInUse();
	xml.pushTag("frame",frame);

	skeleton.head.loadFromXml(xml,"head");

	skeleton.leftHand.loadFromXml(xml,"leftHand");
	skeleton.leftElbow.loadFromXml(xml,"leftElbow");
	skeleton.leftUpperTorso.loadFromXml(xml,"leftUpperTorso");

	skeleton.rightHand.loadFromXml(xml,"rightHand");
	skeleton.rightElbow.loadFromXml(xml,"rightElbow");
	skeleton.rightUpperTorso.loadFromXml(xml,"rightUpperTorso");

	skeleton.leftFoot.loadFromXml(xml,"leftFoot");
	skeleton.leftKnee.loadFromXml(xml,"leftKnee");
	skeleton.leftLowerTorso.loadFromXml(xml,"leftLowerTorso");

	skeleton.rightFoot.loadFromXml(xml,"rightFoot");
	skeleton.rightKnee.loadFromXml(xml,"rightKnee");
	skeleton.rightLowerTorso.loadFromXml(xml,"rightLowerTorso");
	xml.popTag();
}

void ofxSkeletonInput::updateFrameToXml(){
	int frame = getFrameCountInUse();
	xml.pushTag("frame",frame);

	skeleton.head.updateToXml(xml,"head");

	skeleton.leftHand.updateToXml(xml,"leftHand");
	skeleton.leftElbow.updateToXml(xml,"leftElbow");
	skeleton.leftUpperTorso.updateToXml(xml,"leftUpperTorso");

	skeleton.rightHand.updateToXml(xml,"rightHand");
	skeleton.rightElbow.updateToXml(xml,"rightElbow");
	skeleton.rightUpperTorso.updateToXml(xml,"rightUpperTorso");

	skeleton.leftFoot.updateToXml(xml,"leftFoot");
	skeleton.leftKnee.updateToXml(xml,"leftKnee");
	skeleton.leftLowerTorso.updateToXml(xml,"leftLowerTorso");

	skeleton.rightFoot.updateToXml(xml,"rightFoot");
	skeleton.rightKnee.updateToXml(xml,"rightKnee");
	skeleton.rightLowerTorso.updateToXml(xml,"rightLowerTorso");
	xml.popTag();
}

void ofxSkeletonInput::nextFrame(){
	if(!bPlay){
		updateFrameToXml();
	}
	bPlay = false;

	frameCount++;
	bUpdate = true;

	loadFrameFromXml();

	if(bUsePlayer){
		player.nextFrame();
	}
}

void ofxSkeletonInput::prevFrame(){
	if(!bPlay){
		updateFrameToXml();
	}
	bPlay = false;

	frameCount--;
	bUpdate = true;

	loadFrameFromXml();

	if(bUsePlayer){
		player.previousFrame();
	}
}

void ofxSkeletonInput::firstFrame(){
	updateFrameToXml();
	frameCount = startFrame;
	bUpdate = true;
	loadFrameFromXml();
	if(bUsePlayer){
		player.setFrame(startFrame);
	}
}

void ofxSkeletonInput::enableGrabbing(){
	for(int i=0;i<skeleton.skeletonPoints.size();++i){
		skeleton.skeletonPoints[i]->registerMouse();
	}
}

void ofxSkeletonInput::disableGrabbing(){
	for(int i=0;i<skeleton.skeletonPoints.size();++i){
		skeleton.skeletonPoints[i]->unregisterMouse();
	}
}

void ofxSkeletonInput::setGrabbing(bool bGrabbing){
	if(bGrabbing){
		enableGrabbing();
	}else{
		disableGrabbing();
	}
}
