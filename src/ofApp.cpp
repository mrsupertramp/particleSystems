#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofBackgroundHex(0x000000);

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofDisableArbTex();

	int camDist  = 100;
	camera.setDistance(camDist);


	ofLoadImage(texture, "dot.png");

	int total = (int)swarm.positions.size();
	vbo.setVertexData(&swarm.positions[0], total, GL_STATIC_DRAW);
	vbo.setNormalData(&swarm.sizes[0], total, GL_STATIC_DRAW);


		// load the shader
	#ifdef TARGET_OPENGLES
		cout << "shader" << endl;
        shader.load("shaders_gles/shader");
	#else
   		cout << "shader2" << endl;
        shader.load("shaders/shader");
    #endif
}

//--------------------------------------------------------------
void ofApp::update(){
	swarm.update();
	vbo.setVertexData(&swarm.positions[0], swarm.positions.size(), GL_STATIC_DRAW);
	vbo.setNormalData(&swarm.sizes[0], swarm.positions.size(), GL_STATIC_DRAW);

}

//--------------------------------------------------------------
void ofApp::draw(){

	glDepthMask(GL_FALSE);
	
	ofColor c;
	c.setHsb(18,160,80);
	ofSetColor(c);
	
	// this makes everything look glowy :)
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnablePointSprites();
	
	// bind the shader and camera
	// everything inside this function
	// will be effected by the shader/camera
	shader.begin();
	camera.begin();

	// bind the texture so that when all the swarm.positions 
	// are drawn they are replace with our dot image
	texture.bind();
	vbo.draw(GL_POINTS, 0, (int)swarm.positions.size());
	texture.unbind();

	camera.end();
	shader.end();
	
	ofDisablePointSprites();
	ofDisableBlendMode();

	ofDrawBitmapString("framerate: " + ofToString(ofGetFrameRate()),ofGetWidth() - 160, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		for (int i=0 ; i<swarm.positions.size() ; ++i) {
			swarm.attributes[i].Collision = false;
		}
	}
	if (key == 'v') {
		for (int i=0 ; i<swarm.positions.size() ; ++i) {
			swarm.attributes[i].Collision = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
