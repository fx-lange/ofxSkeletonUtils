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
};

struct SkeletonData{
	LimbData head;
	LimbData leftShoulder, leftElbow, leftHand;
	LimbData rightShoulder, rightElbow, rightHand;
//	ofPoint * leftShoulder, * leftElbow, * leftHand;
//	ofPoint * leftShoulder, * leftElbow, * leftHand;
};

class ofxSkeletonRecorder {
public:
	ofxSkeletonRecorder();
	virtual ~ofxSkeletonRecorder();

	SkeletonData & getSkeleton(){
		return skeleton;
	}

	void drawSkeleton(float x = 0, float y = 0);

	void saveFrameToXml(int frame);
	void saveXmlToFile(string filename);

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;
};

#endif /* OFXSKELETONRECORDER_H_ */
