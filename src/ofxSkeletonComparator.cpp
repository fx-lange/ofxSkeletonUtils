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
}

ofxSkeletonComparator::~ofxSkeletonComparator() {
	// TODO Auto-generated destructor stub
}

