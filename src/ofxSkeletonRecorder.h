/*
 * ofxSkeletonRecorder.h
 *	TODO refactor to recorder and player!
 */

#ifndef OFXSKELETONRECORDER_H_
#define OFXSKELETONRECORDER_H_

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxSkeletonPoint.h"
#include "SkeletonData.h"


class ofxSkeletonRecorder {
public:
	ofxSkeletonRecorder();
	virtual ~ofxSkeletonRecorder();

	SkeletonData & getSkeleton(){
		return skeleton;
	}

	void setupForPlayback(string xmlFilename, ofVideoPlayer * player = NULL);

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

	void incFrameOffset(){
		frameOffset++;
	}

	void decFrameOffset(){
		frameOffset--;
	}

	int getFrameOffset(){
		return frameOffset;
	}

	void setStartFrame(int _startFrame){
		startFrame = _startFrame;
		xml.setValue("startFrame",startFrame);
	}

	void setPaused(bool pause);
	void updateFrameToXml();
	int getFrameCountInUse(){
		return floor((double)frameCount*frameFactor) + frameOffset;
	}
	int getFrameCount(){
		return frameCount;
	}
	void firstFrame();

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;

	//player
	ofVideoPlayer * player;
	double frameFactor;
	bool bPlay, bUpdate, bUsedAsPlayer;
	int frameCount;
	int frameOffset;
	int startFrame;
};

#endif /* OFXSKELETONRECORDER_H_ */
