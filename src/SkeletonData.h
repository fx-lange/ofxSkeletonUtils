/*
 * ofxSkeletonData.h
 *
 *  Created on: Jun 20, 2012
 *      Author: spta32
 */

#ifndef OFXSKELETONDATA_H_
#define OFXSKELETONDATA_H_

#include "ofxSkeletonPoint.h"

struct SkeletonData{

	SkeletonData(){
		skeletonPoints.push_back(&head);
		head.color.set(255,0,0);
		skeletonPoints.push_back(&neck);
		neck.color.set(180,0,0);

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

	SkeletonPoint head,neck;
	SkeletonPoint leftUpperTorso, leftElbow, leftHand;
	SkeletonPoint rightUpperTorso, rightElbow, rightHand;
	SkeletonPoint leftLowerTorso, leftKnee, leftFoot;
	SkeletonPoint rightLowerTorso, rightKnee, rightFoot;

	vector<SkeletonPoint*> skeletonPoints;
};


#endif /* OFXSKELETONDATA_H_ */
