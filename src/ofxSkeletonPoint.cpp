#include "ofxSkeletonPoint.h"

//=================== SKELETON POINT ====================

SkeletonPoint::SkeletonPoint(){
	ofxTangibleHandle();
	bFound = false;
	drawType = TANGIBLE_DRAW_AS_CIRCLE;
}

void SkeletonPoint::setup(){
	ofxTangibleHandle::setup(0,0,10,10);
	disableGrabbing();
}

void SkeletonPoint::draw(){
	fillMe = bFound;
	ofxTangibleHandle::draw();
}

void SkeletonPoint::mouseReleased(ofMouseEventArgs & e){
	if (!bGrabbingEnabled || !bPressed)
		return;

	bPressed = false;
	bFound = true;
}

void SkeletonPoint::saveToXml(ofxXmlSettings & xml,string type){
	xml.addTag(type);
	xml.pushTag(type);
	setValues(xml);
	xml.popTag();
}

void SkeletonPoint::updateToXml(ofxXmlSettings & xml,string type){
	xml.pushTag(type);
	setValues(xml);
	xml.popTag();
}


void SkeletonPoint::loadFromXml(ofxXmlSettings & xml,string type){
	xml.pushTag(type);
	x = xml.getValue("posX",-1);
	y = xml.getValue("posY",-1);
	bFound = xml.getValue("found",false);
	xml.popTag();
}

void SkeletonPoint::setValues(ofxXmlSettings & xml){
	xml.setValue("posX",x);
	xml.setValue("posY",y);
	xml.setValue("found",bFound);
}
