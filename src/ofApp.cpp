#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    this->fontSize = 120;
    this->font.loadFont("FreeSans.ttf", this->fontSize,true,true,true);
    this->letter1 = "L i v e";
    this->letter2 = "L o v e";
    this->letter3 = "L a u g h";
    makeLetterPoints(this->letter1, 0.5,0.25);
    makeLetterPoints(this->letter2, 0.5,0.5);
    makeLetterPoints(this->letter3, 0.5,0.75);
    for(int i = 0; i < 500; i++){
        this->agents.push_back(new Agent(ofRandom(ofGetWidth()),ofRandom(ofGetWidth())));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < this->agents.size(); i++){
        this->agents[i]->update();
        this->agents[i]->boundary();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < this->agents.size(); i++){
        this->agents[i]->display();
        this->agents[i]->connect(this->letterPoints);
    }
}

//--------------------------------------------------------------
void ofApp::makeLetterPoints(string letter,float positionPercentage1,float positionPercentage2){
    ofPoint word_size(this->font.stringWidth(letter), this->font.stringHeight(letter));
    int sample_count = 40;
    
    this->word_path = this->font.getStringAsPoints(letter, true, false);
    for (int word_index = 0; word_index < letter.size(); word_index++) {
        
        this->outline = word_path[word_index].getOutline();
        for (int outline_index = 0; outline_index < outline.size(); outline_index++) {
            
            outline[outline_index] = outline[outline_index].getResampledByCount(sample_count);
            vector<glm::vec3> vertices = outline[outline_index].getVertices();
            for (int vertices_index = 0; vertices_index < vertices.size(); vertices_index++) {
                
                ofPoint point(vertices[vertices_index].x, vertices[vertices_index].y, vertices[vertices_index].z);
                point += ofPoint(word_size.x * -positionPercentage1, word_size.y * positionPercentage2);
                point += ofPoint(ofGetWidth() * positionPercentage1, ofGetHeight() * positionPercentage2);
                
                this->letterPoints.push_back(point);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
