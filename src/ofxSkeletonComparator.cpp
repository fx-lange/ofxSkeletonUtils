/*
 * ofxSkeletonComparator.cpp
 *
 *  Created on: Jun 21, 2012
 *      Author: spta32
 */

#include "ofxSkeletonComparator.h"

ofxSkeletonComparator::ofxSkeletonComparator() {
	for(int i=0;i<14;++i){
		errorDistance.push_back(0.f);
		avgErrorDistancePerJoint.push_back(0.f);
		compareCountsPerJoint.push_back(0);
		errorCountsPerJoint.push_back(0);
	}
	comparisons = 0;
	panel.setup("comparator");
	panel.add(maxErrorDistance.setup("max error",50,10,100));
	panel.add(notFoundEQError.setup("not found eq error",false));

	labels.push_back("head");
	labels.push_back("neck");
	labels.push_back("lut ");
	labels.push_back("le  ");
	labels.push_back("lh  ");
	labels.push_back("rut ");
	labels.push_back("re  ");
	labels.push_back("rh  ");
	labels.push_back("llt ");
	labels.push_back("lk  ");
	labels.push_back("lf  ");
	labels.push_back("rlt ");
	labels.push_back("rk  ");
	labels.push_back("rf  ");
}

ofxSkeletonComparator::~ofxSkeletonComparator() {
	// TODO Auto-generated destructor stub
}

