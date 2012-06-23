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
	}
	comparisons = 0;
	panel.setup("comparator");
	panel.add(maxErrorDistance.setup("max error",50,10,100));
	panel.add(notFoundEQError.setup("not found eq error",false));
}

ofxSkeletonComparator::~ofxSkeletonComparator() {
	// TODO Auto-generated destructor stub
}

