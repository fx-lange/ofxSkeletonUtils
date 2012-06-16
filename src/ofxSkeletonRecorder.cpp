/*
 * ofxSkeletonRecorder.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: spta32
 */

#include "ofxSkeletonRecorder.h"


//=================== SKELETON DATA =====================

SkeletonData::SkeletonData(){
	skeletonPoints.push_back(&head);
	head.color.set(255,0,0);

	skeletonPoints.push_back(&leftUpperTorso);
	leftUpperTorso.color.set(0,255,255);
	skeletonPoints.push_back(&leftElbow);
	leftElbow.color.set(0,255,0);
	skeletonPoints.push_back(&leftHand);
	leftHand.color.set(255,0,0);

	skeletonPoints.push_back(&rightUpperTorso);
	rightUpperTorso.color.set(0,255,255);
	skeletonPoints.push_back(&rightElbow);
	rightElbow.color.set(0,255,0);
	skeletonPoints.push_back(&rightHand);
	rightHand.color.set(255,0,0);

	skeletonPoints.push_back(&leftLowerTorso);
	leftLowerTorso.color.set(0,255,255);
	skeletonPoints.push_back(&leftKnee);
	leftKnee.color.set(0,255,0);
	skeletonPoints.push_back(&leftFoot);
	leftFoot.color.set(255,0,0);

	skeletonPoints.push_back(&rightLowerTorso);
	rightLowerTorso.color.set(0,255,255);
	skeletonPoints.push_back(&rightKnee);
	rightKnee.color.set(0,255,0);
	skeletonPoints.push_back(&rightFoot);
	rightFoot.color.set(255,0,0);
}

//================= SKELETON RECORDER ===================

ofxSkeletonRecorder::ofxSkeletonRecorder() {
	bUsedAsPlayer = bPlay = false;
	bUpdate = false;
}

ofxSkeletonRecorder::~ofxSkeletonRecorder() {
	// TODO Auto-generated destructor stub
}

void ofxSkeletonRecorder::setupForPlayback(string xmlFilename, ofVideoPlayer * _player){
	bUsedAsPlayer = bPlay = true;
	bUpdate = false;
	frameOffset = 0;

	loadXmlFile(xmlFilename);
	player = _player;
	firstFrame();

	if(player != NULL){
		int xmlFrames = xml.getNumTags("frame");
		frameFactor = (double)xmlFrames / (double)player->getTotalNumFrames();
	}else{
		frameFactor = 1.;
	}
}

void ofxSkeletonRecorder::enableGrabbing(){
	for(int i=0;i<skeleton.skeletonPoints.size();++i){
		skeleton.skeletonPoints[i]->registerMouse();
	}
}

void ofxSkeletonRecorder::disableGrabbing(){
	for(int i=0;i<skeleton.skeletonPoints.size();++i){
		skeleton.skeletonPoints[i]->unregisterMouse();
	}
}

void ofxSkeletonRecorder::setGrabbing(bool bGrabbing){
	if(bGrabbing){
		enableGrabbing();
	}else{
		disableGrabbing();
	}
}

void ofxSkeletonRecorder::drawSkeleton(float x, float y){
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

void ofxSkeletonRecorder::saveFrameToXml(int frame,int timeMS){
	xml.addTag("frame");
	xml.pushTag("frame",frame);

	xml.setValue("frameCount",ofToString(frame));
	xml.setValue("time",ofToString(timeMS));

	skeleton.head.saveToXml(xml,"head");

	skeleton.leftHand.saveToXml(xml,"leftHand");
	skeleton.leftElbow.saveToXml(xml,"leftElbow");
	skeleton.leftUpperTorso.saveToXml(xml,"leftUpperTorso");

	skeleton.rightHand.saveToXml(xml,"rightHand");
	skeleton.rightElbow.saveToXml(xml,"rightElbow");
	skeleton.rightUpperTorso.saveToXml(xml,"rightUpperTorso");

	skeleton.leftFoot.saveToXml(xml,"leftFoot");
	skeleton.leftKnee.saveToXml(xml,"leftKnee");
	skeleton.leftLowerTorso.saveToXml(xml,"leftLowerTorso");

	skeleton.rightFoot.saveToXml(xml,"rightFoot");
	skeleton.rightKnee.saveToXml(xml,"rightKnee");
	skeleton.rightLowerTorso.saveToXml(xml,"rightLowerTorso");
	xml.popTag();
}

void ofxSkeletonRecorder::loadFrameFromXml(){
	if(!bUpdate){
		return;
	}else{
		bUpdate = false;
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

void ofxSkeletonRecorder::updateFrameToXml(){
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

void ofxSkeletonRecorder::saveXmlToFile(string filename){
	if(bUsedAsPlayer){
		if(!bPlay)
			updateFrameToXml();
		xml.setValue("frameOffset",frameOffset);
	}
	xml.saveFile(filename);
}

void ofxSkeletonRecorder::loadXmlFile(string filename){
	xml.loadFile(filename);
	frameOffset = xml.getValue("frameOffset",0);
	startFrame = xml.getValue("startFrame",0);
}

void ofxSkeletonRecorder::play(bool newFrame){
	if(bPlay){
		if(player != NULL){
			if(player->isFrameNew()){
				frameCount = player->getCurrentFrame();
				bUpdate = true;
			}
		}else if(newFrame){
			frameCount++;
			bUpdate = true;
		}
	}

	loadFrameFromXml();
}

void ofxSkeletonRecorder::update(){
	if(player != NULL){
		player->idleMovie();
	}
}

void ofxSkeletonRecorder::nextFrame(){
	if(!bPlay){
		updateFrameToXml();
	}
	bPlay = false;

	frameCount++;
	bUpdate = true;

	loadFrameFromXml();

	if(player != NULL){
		player->setPaused(true);
		player->nextFrame();
	}
}

void ofxSkeletonRecorder::prevFrame(){
	if(!bPlay){
		updateFrameToXml();
	}
	bPlay = false;

	frameCount--;
	bUpdate = true;

	loadFrameFromXml();

	if(player != NULL){
		player->setPaused(true);
		player->previousFrame();
	}
}

void ofxSkeletonRecorder::firstFrame(){
	frameCount = startFrame;
	if(player!=NULL){
		player->setFrame(startFrame);
	}
}

void ofxSkeletonRecorder::setPaused(bool pause){
	bPlay = !pause;
	if(player!=NULL){
		player->setPaused(pause);
	}
}

