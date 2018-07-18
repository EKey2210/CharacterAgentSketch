//
//  Agent.cpp
//  CharacterAgentSketch
//
//  Created by EKey2210 on 2018/07/16.
//

#include "Agent.hpp"

Agent::Agent(float x,float y){
    this->position = vec2(x,y);
    this->velocity = vec2(ofRandom(-3,3),ofRandom(-3,3));
    this->acceleration = vec2(0,0);
    
    this->color.setHsb(ofRandom(255),255,255);
    
    this->maxForce = 0.2;
    this->maxSpeed = 5;
    this->radius = 3;
}

Agent::~Agent(){
    
}

void Agent::update(){
    this->velocity += this->acceleration;
    if(this->velocity.length() > maxSpeed){
        normalize(this->velocity);
        this->velocity *= maxSpeed;
    }
    this->position += this->velocity;
    
    this->acceleration *= 0;
}

void Agent::display(){
    this->angle = atan2f(this->velocity.y, this->velocity.x) + HALF_PI;
    ofSetColor(this->color,80);
    ofNoFill();
    ofDrawEllipse(this->position.x, this->position.y, this->radius, this->radius);
}

void Agent::connect(vector<ofPoint> points){
//    ofSetColor(this->color,80);
    for(int i = 0; i < points.size(); i++){
        float distance = ofDist(this->position.x,this->position.y,points[i].x,points[i].y);
        if(distance < 65){
            ofSetColor(this->color,ofMap(distance,0,65,255,0));
            ofDrawLine(this->position.x,this->position.y,points[i].x,points[i].y);
        }
    }
}

void Agent::boundary(){
    if(this->position.x > ofGetWidth() || this->position.x < 0){
        this->velocity.x *= -1;
    }
    if(this->position.y > ofGetHeight() || this->position.y < 0){
        this->velocity.y *= -1;
    }
}

void Agent::applyForce(vec2 f){
    this->acceleration += f;
}

void Agent::arrive(vec2 target){
    vec2 desired = target - this->position;
    if(desired.length() < 100){
        desired *= ofMap(desired.length(),0,100,0,maxSpeed);
    }else{
        normalize(desired);
        desired *= maxSpeed;
    }
    vec2 steer = desired - this->velocity;
    if(steer.length() > maxForce){
        normalize(steer);
        steer *= maxForce;
    }
    applyForce(steer);
}

void Agent::seek(vec2 target){
    vec2 desired = target - this->position;
    normalize(desired);
    desired *= maxSpeed;
    vec2 steer = desired - this->velocity;
    if(steer.length() > maxForce){
        normalize(steer);
        steer *= maxForce;
    }
    applyForce(steer);
}
