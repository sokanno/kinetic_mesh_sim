#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
    ofDisableAntiAliasing();
    
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
    box2d.createGround();
    
    column = 8;
    row = 7;
    intervalX = ofGetWidth() / (column + 1);
    intervalY = intervalX / 2 * 1.732;
    radius = 4.0;
    cout << intervalX << endl;
    increment = 1;
    
    //  anchor:row-0
    for (int i=0; i<column+1; i++) {
        ofxBox2dRect* anchor = new ofxBox2dRect();
        anchor->setup(box2d.getWorld(), intervalX*(i+0.5), 0, radius, radius);
        anchors.push_back(anchor);
    }
    
    for (int j=0; j<row; j++) {
        for (int i=0; i<column-j; i++) {
            ofxBox2dCircle* circle = new ofxBox2dCircle();;
            circle->setPhysics(3.0, 0.53, 0.1);
            circle->setup(box2d.getWorld(), intervalX*(i+1) + intervalX*j*0.5, intervalY*(j+1), radius*2);
            circles.push_back(circle);
            DrawLine* line = new DrawLine();
            line->setup(ofColor(0, 0, 255, 70));
            lines.push_back(line);
        }
    }
    
    for (int j=0; j<row; j++) {
        int k = 0;
        for (int l=0; l<j; l++) {
            k += l;
        }
        for (int i=0; i<column-j; i++) {
            ofxBox2dJoint* joint = new ofxBox2dJoint();
            float jointLength = intervalX;
            if (j==0) {
                joint->setup(box2d.getWorld(), circles[i]->body, anchors[i]->body);
            }else{
                joint->setup(box2d.getWorld(), circles[i+j*column-k]->body,
                             circles[i+j*column-k-row+j-2]->body);
            }
            joint->setLength(jointLength);
            joints.push_back(joint);
            jointLengthCol.push_back(jointLength);
        }
    }
    for (int j=0; j<row; j++) {
        int k = 0;
        for (int l=0; l<j; l++) {
            k += l;
        }
        for (int i=0; i<column-j; i++) {
            ofxBox2dJoint* joint = new ofxBox2dJoint();
            float jointLength = intervalX;
            if (j==0) {
                joint->setup(box2d.getWorld(), circles[i]->body, anchors[i+1]->body);
            }else{
                joint->setup(box2d.getWorld(), circles[i+j*column-k]->body,
                             circles[i+j*column-k-row+j-1]->body);
            }
            joint->setLength(jointLength);
            joints.push_back(joint);
            jointLengthCol.push_back(jointLength);
        }
    }
}

//--------------------------------------------------------------
void testApp::update() {
	box2d.update();
    
    for (int i=0; i<jointLengthCol.size(); i++) {
        float f = ofRandom(-0.5, 0.5);
        jointLengthCol[i] += f;
        if (jointLengthCol[i] > intervalX*1.5) {
            jointLengthCol[i] = intervalX*1.4;
        }else if(jointLengthCol[i] < intervalX*0.5){
            jointLengthCol[i] = intervalX*0.6;
        }
        joints[i]->setLength(jointLengthCol[i]);
    }
    
    for (int i=0; i<lines.size(); i++) {
        lines[i]->update(circles[i]->getPosition());
    }
}


//--------------------------------------------------------------
void testApp::draw() {
    ofBackgroundGradient( ofColor(240), ofColor(180), OF_GRADIENT_CIRCULAR);
    for(int i=0; i<anchors.size(); i++) {
        ofSetHexColor(0x344342);
        anchors[i]->draw();
    }
    for(int i=0; i<circles.size(); i++) {
        ofFill();
		ofSetHexColor(0x344342);
		circles[i]->draw();
	}
    for (int i=0; i<joints.size(); i++) {
		ofSetHexColor(0x344342);
		joints[i]->draw();
	}

    
//    for (int i=0; i<lines.size(); i++) {
//        lines[i]->draw();
//    }
	
//        ofSetHexColor(0xf2ab01);
//        anchor.draw();
//
//        ofFill();
//		ofSetHexColor(0x01b1f2);
//		circle.draw();
//
//		ofSetHexColor(0x444342);
//		joint.draw();
    
    
//	string info = "";
//	info += "Press [n] to add a new joint\n";
//	info += "click and pull the chain around\n";
//	info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
//	ofSetHexColor(0x444342);
//	ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
//	if(key == 't') ofToggleFullscreen();
//    
//    if (key == OF_KEY_UP) {
////        cout << jointLength << endl;
//        for (int i=0; i<jointLengthCol.size(); i+=increment) {
//            jointLengthCol[i] -= 0.1;
//            joints[i]->setLength(jointLengthCol[i]);
//        }
//    }
//    if (key == OF_KEY_DOWN) {
////        jointLength += 1.0;
////        cout << jointLength << endl;
//        for (int i=0; i<jointLengthCol.size(); i+=increment) {
//            jointLengthCol[i] += 0.1;
//            joints[i]->setLength(jointLengthCol[i]);
//        }
//    }
//    
//    if (key == '1' || key == '2'|| key == '3'|| key == '4'|| key == '5') {
//        increment = int(key) -48;
//        cout << increment <<endl;
//    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}

