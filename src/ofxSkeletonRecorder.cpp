/*
 * ofxSkeletonRecorder.cpp
 *
 *  Created on: Jun 14, 2012
 *      Author: spta32
 */

#include "ofxSkeletonRecorder.h"

ofxSkeletonRecorder::ofxSkeletonRecorder() {
	// TODO Auto-generated constructor stub

}

ofxSkeletonRecorder::~ofxSkeletonRecorder() {
	// TODO Auto-generated destructor stub
}

void ofxSkeletonRecorder::drawSkeleton(float x, float y){
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x,y);

	ofSetColor(255,0,0);
	skeleton.head.draw();
	skeleton.leftHand.draw();
	skeleton.rightHand.draw();

	ofSetColor(0,255,0);
	skeleton.leftElbow.draw();
	skeleton.rightElbow.draw();

	ofSetColor(0,0,255);
	skeleton.leftShoulder.draw();
	skeleton.rightShoulder.draw();

	ofPopMatrix();
	ofPopStyle();
}

void ofxSkeletonRecorder::saveFrameToXml(int frame){
	xml.addTag("frame");
	xml.pushTag("frame",frame);
	skeleton.head.saveToXml(xml,"head");
	skeleton.leftHand.saveToXml(xml,"leftHand");
	skeleton.leftElbow.saveToXml(xml,"leftElbow");
	skeleton.leftShoulder.saveToXml(xml,"leftShoulder");
	skeleton.rightHand.saveToXml(xml,"rightHand");
	skeleton.rightElbow.saveToXml(xml,"rightElbow");
	skeleton.rightShoulder.saveToXml(xml,"rightShoulder");
	xml.popTag();
}

void ofxSkeletonRecorder::saveXmlToFile(string filename){
	xml.saveFile(filename);
}

