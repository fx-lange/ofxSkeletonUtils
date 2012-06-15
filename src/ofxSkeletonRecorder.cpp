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

void ofxSkeletonRecorder::loadFrameFromXml(int frame){
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

void ofxSkeletonRecorder::updateFrameToXml(int frame){
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
	xml.saveFile(filename);
}

void ofxSkeletonRecorder::loadXmlFile(string filename){
	xml.loadFile(filename);
}

