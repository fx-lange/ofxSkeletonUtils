/*
 * ofxSkeletonComparator.h
 *
 *  Created on: Jun 21, 2012
 *      Author: spta32
 */

#ifndef OFXSKELETONCOMPARATOR_H_
#define OFXSKELETONCOMPARATOR_H_

#include "SkeletonData.h"

class ofxSkeletonComparator {
public:
	//0  head
	//1  neck
	//2  lut
	//3  le
	//4  lh
	//5  rut
	//6  re
	//7  rh
	//8  llt
	//9  lk
	//10 lf
	//11 rut
	//12 rk
	//13 rf

	vector<float> errorDistance;

	SkeletonData * skeleton;
	int comparisons;
	int countErrors;
	float errorThreshold;

	int errorsPerRun, comparisonsPerRun, errorDistancePerRun;

	ofxSkeletonComparator();
	virtual ~ofxSkeletonComparator();

	void setup(float _errorThreshold){
		errorThreshold = _errorThreshold;
		reset();
	}

	void reset(){
		errorsPerRun = comparisonsPerRun = errorDistancePerRun = 0;
	}

	string printResults(){
		float error = 0;
		for(int i=0;i<errorDistance.size();++i){
			error += errorDistance[i];
		}

		errorsPerRun += countErrors;
		comparisonsPerRun += comparisons;
		errorDistancePerRun += error;

		stringstream stream;
		stream << "    Comparisons   : " << comparisons << endl;
		stream << "       Errors     : " << countErrors << endl;
		stream << "AVG Error Distance: " << error / float(comparisons) << endl;
		stream << " Comparisons Run  : " << comparisonsPerRun << endl;
		stream << "   Errors Run     : " << errorsPerRun << endl;
		stream << "Error Distance Run: " << errorDistancePerRun << endl;
		stream << " AVG  Distance Run: " << errorDistancePerRun / float(comparisonsPerRun) << endl;


		comparisons = 0;
		countErrors = 0;

		return stream.str();
	}

	bool compareHead(ofPoint * p){
		return compare(p,0,"h");
	}

	bool compareNeck(ofPoint * p){
		return compare(p,1,"n");
	}

	bool compareLeftUpperTorso(ofPoint * p){
		return compare(p,2,"lut");
	}

	bool compareLeftElbow(ofPoint * p){
		return compare(p,3,"le");
	}

	bool compareLeftHand(ofPoint * p){
		int idx = 4;
		if(p != NULL){
			if(p->distance(*skeleton->skeletonPoints[idx])
				> p->distance(*skeleton->skeletonPoints[7])){
				idx = 7;
			}
		}

		return compare(p,idx,"lh");
	}

	bool compareRightUpperTorso(ofPoint * p){
		return compare(p,5,"rut");
	}

	bool compareRightElbow(ofPoint * p){
		return compare(p,6,"re");
	}

	bool compareRightHand(ofPoint * p){
		int idx = 7;
		if(p != NULL){
			if(p->distance(*skeleton->skeletonPoints[idx])
				> p->distance(*skeleton->skeletonPoints[4])){
				idx = 4;
			}
		}

		return compare(p,idx,"rh");
	}

	bool compareLeftLowerTorso(ofPoint * p){
		return compare(p,8,"llt");
	}

	bool compareLeftKnee(ofPoint * p){
		return compare(p,9,"lk");
	}

	bool compareLeftFoot(ofPoint * p){
		return compare(p,10,"lf");
	}

	bool compareRightLowerTorso(ofPoint * p){
		return compare(p,11,"rlt");
	}

	bool compareRightKnee(ofPoint * p){
		return compare(p,12,"rk");
	}

	bool compareRightFoot(ofPoint * p){
		return compare(p,13,"rf");
	}

protected:
	bool compare(ofPoint * p, int index, string bez){
		if(p == NULL || skeleton == NULL || !skeleton->skeletonPoints[index]->bFound){
			//0 or max?
			errorDistance[index] = 0.f;
			return false;
		}

		float errorDist = p->distance(*skeleton->skeletonPoints[index]);
		errorDistance[index] = errorDist;

		comparisons++;

		if(errorDist > errorThreshold){
			ofLog(OF_LOG_WARNING,bez+": "+ofToString(errorDist));
			countErrors++;
			return true;
		}else{
			return false;
		}

	}


};

#endif /* OFXSKELETONCOMPARATOR_H_ */
