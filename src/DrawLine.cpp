//
//  DrawLine.cpp
//  testPhysics
//
//  Created by yang02 on 11/19/13.
//
//

#include "DrawLine.h"

DrawLine::DrawLine(){
    polyline.clear();
}

DrawLine::~DrawLine(){
    
}

void DrawLine::setup(ofColor _color){
    color = _color;
}
void DrawLine::update(ofPoint _point){
    
    polyline.addVertex(_point);
}
void DrawLine::draw(){
    ofNoFill();
    ofSetColor(color);
    for (int i=0; i<polyline.size(); i++) {
        if(i != 0){
            ofLine(polyline[i].x, polyline[i].y, polyline[i-1].x, polyline[i-1].y);
        }
    }
}
