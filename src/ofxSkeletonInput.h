/*
 * ofxSkeletonInput.h
 *
 *  Created on: Jun 20, 2012
 *      Author: spta32
 */

#ifndef OFXSKELETONINPUT_H_
#define OFXSKELETONINPUT_H_

#include "ofxCvVideoInput.h"
#include "ofxXmlSettings.h"
#include "SkeletonData.h"

class ofxSkeletonInput : public ofxCvVideoInput{
public:
	ofxSkeletonInput();
	virtual ~ofxSkeletonInput();

	virtual void setup(string videoFilename, string xmlFilename, bool useVideoPlayer = true);

	void loadXmlFile(string filename);
	void saveXmlToFile(string filename);
	void loadFrameFromXml();

	ofxXmlSettings & getXml(){
		return xml;
	}

	virtual bool useFrame();
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

	void updateFrameToXml();
	int getFrameCountInUse(){
		return floor((double)frameCount*frameFactor) + frameOffset;
	}
	int getFrameCount(){
		return frameCount;
	}
	int getFrames(){
		return endFrame;
	}
	void firstFrame();

	void drawDataLayer(float x = 0, float y = 0);
	SkeletonData * getSkeleton(){
		return &skeleton;
	}

	void enableGrabbing();
	void disableGrabbing();
	void setGrabbing(bool bGrabbing);

protected:
	SkeletonData skeleton;
	string filename;
	ofxXmlSettings xml;

	bool bUsePlayer;
	int frameCount;
	double frameFactor;
	bool bUpdate, bUsedAsPlayer;
	int frameOffset;
	int startFrame, endFrame;
};

#endif /* OFXSKELETONINPUT_H_ */
