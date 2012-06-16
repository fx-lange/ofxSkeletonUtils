/*
 * ofxSkeletonRecorder.h
 *
 *  Created on: Jun 14, 2012
 *      Author: fx-lange
 *
 *	TODO refactor to recorder and player!
 */

#ifndef OFXSKELETONRECORDER_H_
#define OFXSKELETONRECORDER_H_

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxSkeletonPoint.h"


struct SkeletonData{

	SkeletonData();

	SkeletonPoint head;
	SkeletonPoint leftUpperTorso, leftElbow, leftHand;
	SkeletonPoint rightUpperTorso, rightElbow, rightHand;
	SkeletonPoint leftLowerTorso, leftKnee, leftFoot;
	SkeletonPoint rightLowerTorso, rightKnee, rightFoot;

	vector<SkeletonPoint*> skeletonPoints;
};

class ofxSkeletonRecorder {
public:
	ofxSkeletonRecorder();
	virtual ~ofxSkeletonRecorder();

	SkeletonData & getSkeleton(){
		return skeleton;
	}

	void setup(string xmlFilename, ofVideoPlayer * player = NULL);

	void enableGrabbing();
	void disableGrabbing();
	void setGrabbing(bool bGrabbing);

	void drawSkeleton(float x = 0, float y = 0);

	void saveFrameToXml(int frame, int timeMS);
	void loadFrameFromXml();

	void saveXmlToFile(string filename);
	void loadXmlFile(string filename);

	ofxXmlSettings & getXml(){
		return xml;
	}

	//player
	void play(bool newFrame = true);
	void update();
	void nextFrame();
	void prevFrame();
	void setPaused(bool pause);
	void updateFrameToXml();

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;

	//player
	ofVideoPlayer * player;
	double frameFactor;
	bool bPlay, bUpdate;
	int frameCount;
};

#endif /* OFXSKELETONRECORDER_H_ */
