/*
 * ofxSkeletonComparator.h
 *
 *  Created on: Jun 21, 2012
 *      Author: spta32
 */

#ifndef OFXSKELETONCOMPARATOR_H_
#define OFXSKELETONCOMPARATOR_H_

#include "SkeletonData.h"
#include "ofxGui.h"

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
	vector<float> avgErrorDistancePerJoint;
	vector<int> compareCountsPerJoint;
	vector<int> errorCountsPerJoint;
	vector<string> labels;

	SkeletonData * skeleton;
	int comparisons;
	int countErrors;

	int errorsPerRun, comparisonsPerRun, errorDistancePerRun;

	ofxPanel panel;
	ofxFloatSlider maxErrorDistance;
	ofxToggle notFoundEQError;

	ofxSkeletonComparator();
	virtual ~ofxSkeletonComparator();

	void setup(){
		reset();
	}

	void reset(){
		errorsPerRun = comparisonsPerRun = errorDistancePerRun = 0;
		for(int i=0;i<14;++i){
			errorDistance[i] = 0.f;
			avgErrorDistancePerJoint[i] =  0.f;
			compareCountsPerJoint[i] = 0;
			errorCountsPerJoint[i] = 0;
		}
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
		stream << "Errors            : " << countErrors << endl;
		stream << "Comparisons       : " << comparisons << endl;
		stream << "AVG Error         : " << error / float(comparisons) << endl;
		stream << "Errors Run        : " << errorsPerRun << endl;
		stream << "Comparisons Run   : " << comparisonsPerRun << endl;
		stream << "Hit Ratio         : " << (1-(float)errorsPerRun/(float)comparisonsPerRun)*100 << "%" << endl;
		stream << "AVG Error Run     : " << errorDistancePerRun / float(comparisonsPerRun) << endl;


		comparisons = 0;
		countErrors = 0;

		return stream.str();
	}

	string printPerJointResults(){
		stringstream stream;
		for(unsigned int i=0;i<errorDistance.size();++i){
			stream << labels[i] << " ; " << ofToString(avgErrorDistancePerJoint[i]/(float)compareCountsPerJoint[i]) << " ; "<< errorCountsPerJoint[i] << endl;
		}
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
		float errorDist = 0.f;
		if(p == NULL && notFoundEQError){
			errorDist = maxErrorDistance + 1.f;
		}else if(p == NULL || skeleton == NULL || !skeleton->skeletonPoints[index]->bFound){
			//0 or max?
			errorDistance[index] = 0.f;
			ofLog(OF_LOG_WARNING,bez+": not found!");
			return false;
		}else{
			errorDist = p->distance(*skeleton->skeletonPoints[index]);
		}

		errorDistance[index] = errorDist;
		avgErrorDistancePerJoint[index] += errorDist;
		compareCountsPerJoint[index]++;

		comparisons++;

		if(errorDist > maxErrorDistance){
			ofLog(OF_LOG_WARNING,bez+": "+ofToString(errorDist));
			countErrors++;
			errorCountsPerJoint[index]++;
			return true;
		}else{
			return false;
		}

	}


};

#endif /* OFXSKELETONCOMPARATOR_H_ */
