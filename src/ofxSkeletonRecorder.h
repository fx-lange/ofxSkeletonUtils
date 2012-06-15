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

class LimbData : public ofPoint{
public:
	LimbData(){
		bFound = false;
	}
	bool bFound;

	void draw(){
		if(bFound)
			ofCircle(*this,20);
	}

	void saveToXml(ofxXmlSettings & xml,string type){
		xml.addTag(type);
		xml.pushTag(type);
		xml.setValue("posX",x);
		xml.setValue("posY",y);
		xml.setValue("found",bFound);
		xml.popTag();
	}

	void loadFromXml(ofxXmlSettings & xml,string type){
		xml.pushTag(type);
		x = xml.getValue("posX",-1);
		y = xml.getValue("posY",-1);
		bFound = xml.getValue("found",false);
		xml.popTag();
	}
};

struct SkeletonData{
	LimbData head;
	LimbData leftUpperTorso, leftElbow, leftHand;
	LimbData rightUpperTorso, rightElbow, rightHand;
	LimbData leftLowerTorso, leftKnee, leftFoot;
	LimbData rightLowerTorso, rightKnee, rightFoot;
};

class ofxSkeletonRecorder {
public:
	ofxSkeletonRecorder();
	virtual ~ofxSkeletonRecorder();

	SkeletonData & getSkeleton(){
		return skeleton;
	}

	void drawSkeleton(float x = 0, float y = 0);

	void saveFrameToXml(int frame, int timeMS);
	void loadFrameFromXml(int frame);
	void updateFrameToXml(int frame);

	void saveXmlToFile(string filename);
	void loadXmlFile(string filename);

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;
};

#endif /* OFXSKELETONRECORDER_H_ */
