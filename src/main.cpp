#include "ofMain.h"
#include "testApp.h"

int main() {
    ofSetupOpenGL(1048, 1048, OF_WINDOW);
	ofRunApp(new testApp());
}
