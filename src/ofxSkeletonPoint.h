/*
 * mySP.h
 *
 *  Created on: Jun 16, 2012
 *      Author: spta32
 */

#ifndef SKELETONPOINT_H_
#define SKELETONPOINT_H_

#include "ofxTangibleHandle.h"
#include "ofxXmlSettings.h"

class SkeletonPoint : public ofxTangibleHandle{
public:
	bool bFound;

	SkeletonPoint();

	virtual void draw();
	virtual void mouseReleased(ofMouseEventArgs & event);

	void saveToXml(ofxXmlSettings & xml,string type);

	void updateToXml(ofxXmlSettings & xml,string type);

	void loadFromXml(ofxXmlSettings & xml,string type);

protected:
	void setValues(ofxXmlSettings & xml);
};

#endif /* SKELETONPOINT_H_ */
