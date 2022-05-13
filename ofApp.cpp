#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 60 == 0) {

		this->random_seed = ofRandom(1000);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum());

	ofColor color;

	ofSeedRandom(this->random_seed);

	ofFill();
	for (int z = -150; z <= 150; z += 150) {

		color.setHsb(ofRandom(255), 180, 255);
		ofSetColor(color);

		ofPushMatrix();
		ofTranslate(0, 0, z);

		vector<glm::vec2> location_list;
		vector<float> radius_list;

		while (location_list.size() < 120) {

			int x = ofRandom(-320, 320);
			int y = ofRandom(-320, 320);

			glm::vec2 location = glm::vec2(x, y);
			float radius = ofRandom(10, 120);

			if (location.x + radius > 320 || location.x - radius < -320 || location.y + radius > 320 || location.y - radius < -320) {

				continue;
			}

			bool flag = true;
			for (int i = 0; i < location_list.size(); i++) {

				if (glm::distance(location, location_list[i]) < radius_list[i] + radius) {

					flag = false;
					break;
				}
			}

			if (flag) {

				location_list.push_back(location);
				radius_list.push_back(radius);
			}
		}

		ofBeginShape();

		ofVertex(glm::vec2(-360, -360));
		ofVertex(glm::vec2(-360, 360));
		ofVertex(glm::vec2(360, 360));
		ofVertex(glm::vec2(360, -360));

		for (int i = 0; i < location_list.size(); i++) {

			ofNextContour(true);

			for (int deg = 0; deg < 360; deg += 10) {

				ofVertex(location_list[i] + glm::vec2(radius_list[i] * cos(deg * DEG_TO_RAD), radius_list[i] * sin(deg * DEG_TO_RAD)));
			}
		}

		ofEndShape(true);

		ofPopMatrix();
	}
	
	ofSeedRandom(this->random_seed);

	ofNoFill();
	ofSetColor(0);
	for (int z = -150; z <= 150; z += 150) {

		color.setHsb(ofRandom(255), 180, 255); // Random‚Ì‚½‚ßA‰‰ŽZ‚¾‚¯

		ofPushMatrix();
		ofTranslate(0, 0, z);

		vector<glm::vec2> location_list;
		vector<float> radius_list;

		while (location_list.size() < 120) {

			int x = ofRandom(-320, 320);
			int y = ofRandom(-320, 320);

			glm::vec2 location = glm::vec2(x, y);
			float radius = ofRandom(10, 120);

			if (location.x + radius > 320 || location.x - radius < -320 || location.y + radius > 320 || location.y - radius < -320) {

				continue;
			}

			bool flag = true;
			for (int i = 0; i < location_list.size(); i++) {

				if (glm::distance(location, location_list[i]) < radius_list[i] + radius) {

					flag = false;
					break;
				}
			}

			if (flag) {

				location_list.push_back(location);
				radius_list.push_back(radius);
			}
		}

		ofBeginShape();

		ofVertex(glm::vec2(-360, -360));
		ofVertex(glm::vec2(-360, 360));
		ofVertex(glm::vec2(360, 360));
		ofVertex(glm::vec2(360, -360));

		for (int i = 0; i < location_list.size(); i++) {

			ofNextContour(true);

			for (int deg = 0; deg < 360; deg += 10) {

				ofVertex(location_list[i] + glm::vec2(radius_list[i] * cos(deg * DEG_TO_RAD), radius_list[i] * sin(deg * DEG_TO_RAD)));
			}
		}

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}