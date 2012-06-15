/*
 * ofxSkeletonRecorder.h
 *
 *  Created on: Jun 14, 2012
 *      Author: fx-lange
 */

#ifndef OFXSKELETONRECORDER_H_
#define OFXSKELETONRECORDER_H_

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxTangibleHandle.h"

class LimbData : public ofxTangibleHandle{
public:
	LimbData(){
		bFound = false;
		setup(0,0,10,10);
		drawType = TANGIBLE_DRAW_AS_CIRCLE;
		unregisterMouse();
	}
	bool bFound;

	virtual void draw(){
		fillMe = bFound;
		ofxTangibleHandle::draw();
	}

	void saveToXml(ofxXmlSettings & xml,string type){
		xml.addTag(type);
		xml.pushTag(type);
		setValues(xml);
		xml.popTag();
	}

	void updateToXml(ofxXmlSettings & xml,string type){
		xml.pushTag(type);
		setValues(xml);
		xml.popTag();
	}


	void loadFromXml(ofxXmlSettings & xml,string type){
		xml.pushTag(type);
		x = xml.getValue("posX",-1);
		y = xml.getValue("posY",-1);
		bFound = xml.getValue("found",false);
		xml.popTag();
	}

protected:
	void setValues(ofxXmlSettings & xml){
		xml.setValue("posX",x);
		xml.setValue("posY",y);
		xml.setValue("found",bFound);
	}
};

struct SkeletonData{

	SkeletonData(){
		limbs.push_back(&head);
		head.color.set(255,0,0);

		limbs.push_back(&leftUpperTorso);
		leftUpperTorso.color.set(0,255,255);
		limbs.push_back(&leftElbow);
		leftElbow.color.set(0,255,0);
		limbs.push_back(&leftHand);
		leftHand.color.set(255,0,0);

		limbs.push_back(&rightUpperTorso);
		rightUpperTorso.color.set(0,255,255);
		limbs.push_back(&rightElbow);
		rightElbow.color.set(0,255,0);
		limbs.push_back(&rightHand);
		rightHand.color.set(255,0,0);

		limbs.push_back(&leftLowerTorso);
		leftLowerTorso.color.set(0,255,255);
		limbs.push_back(&leftKnee);
		leftKnee.color.set(0,255,0);
		limbs.push_back(&leftFoot);
		leftFoot.color.set(255,0,0);

		limbs.push_back(&rightLowerTorso);
		rightLowerTorso.color.set(0,255,255);
		limbs.push_back(&rightKnee);
		rightKnee.color.set(0,255,0);
		limbs.push_back(&rightFoot);
		rightFoot.color.set(255,0,0);
	}

	LimbData head;
	LimbData leftUpperTorso, leftElbow, leftHand;
	LimbData rightUpperTorso, rightElbow, rightHand;
	LimbData leftLowerTorso, leftKnee, leftFoot;
	LimbData rightLowerTorso, rightKnee, rightFoot;

	vector<LimbData*> limbs;
};

class ofxSkeletonRecorder {
public:
	ofxSkeletonRecorder();
	virtual ~ofxSkeletonRecorder();

	SkeletonData & getSkeleton(){
		return skeleton;
	}

	void enableGrabbing(){
		for(int i=0;i<skeleton.limbs.size();++i){
			skeleton.limbs[i]->registerMouse();
		}
	}

	void disableGrabbing(){
		for(int i=0;i<skeleton.limbs.size();++i){
			skeleton.limbs[i]->unregisterMouse();
		}
	}

	void setGrabbing(bool bGrabbing){
		if(bGrabbing){
			enableGrabbing();
		}else{
			disableGrabbing();
		}
	}

	void drawSkeleton(float x = 0, float y = 0);

	void saveFrameToXml(int frame, int timeMS);
	void loadFrameFromXml(int frame);
	void updateFrameToXml(int frame);

	void saveXmlToFile(string filename);
	void loadXmlFile(string filename);

	ofxXmlSettings & getXml(){
		return xml;
	}

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;
};

#endif /* OFXSKELETONRECORDER_H_ */
