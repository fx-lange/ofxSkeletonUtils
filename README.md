ofxSkeletonUtils
================

ofxSkeletonUtils is a small openFrameworks addon to save, load and modify skeleton data per frame and was created as a byproduct to my bachelor thesis. it is used to verify results of my own skeleton tracker - for example to prelabel a video input or to compare the calculated skeleton points with results from OpenNI. 

dependencies
============
ofxTangibleUI - to change recorded skeleton points

ToDo
============
ofxSkeletonRecorder still contains input/player members and methods => clean up
perhaps include recorder into inputmanager and rename it - ofxCvInputManager to ofxCvInputControl...
