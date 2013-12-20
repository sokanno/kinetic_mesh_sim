#ifndef __testPhysics__DrawLine__
#define __testPhysics__DrawLine__

#include <iostream>
#include "ofMain.h"

class DrawLine
{
public:
    DrawLine();
    virtual ~DrawLine();
    void setup(ofColor color);
    void update(ofPoint point);
    void draw();
    
protected:
private:
    ofPolyline polyline;
    ofColor color;
    
};

#endif /* defined(__testPhysics__DrawLine__) */
