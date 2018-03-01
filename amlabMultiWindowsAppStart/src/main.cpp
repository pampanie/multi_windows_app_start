#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	//
	//	// this kicks off the running of my app
	//	// can be OF_WINDOW or OF_FULLSCREEN
	//	// pass in width and height too:
	//	ofRunApp(new ofApp());
	
	//	main window ================
	ofGLFWWindowSettings settings;
//	main window size
	settings.width = 600;
	settings.height = 600;
//	main window position
	settings.setPosition(ofVec2f(300,0));
	//	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

//	gui window size
	settings.width = 300;
	settings.height = 300;
//	gui window position
	settings.setPosition(ofVec2f(0,0));
	settings.resizable = false;
	// uncomment next line to share main's OpenGL resources with gui
	//settings.shareContextWith = mainWindow;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	guiWindow->setVerticalSync(false);
	
	shared_ptr<ofApp> mainApp(new ofApp);
//	self custome function setupGui
	mainApp->setupGui();
//	self make function drawGui
	ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawGui);
	
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	
	
}
