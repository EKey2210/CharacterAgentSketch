//
//  Agent.hpp
//  CharacterAgentSketch
//
//  Created by EKey2210 on 2018/07/16.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <stdio.h>
#include "ofMain.h"

using namespace glm;

class Agent{
private:
    vec2 position;
    vec2 velocity;
    vec2 acceleration;
    
    ofColor color;
    
    float maxForce;
    float maxSpeed;
    float angle;
    float radius;
public:
    Agent(float x,float y);
    ~Agent();
    void update();
    void display();
    void connect(vector<ofPoint> points);
    void boundary();
    void applyForce(vec2 f);
    void arrive(vec2 target);
    void seek(vec2 target);
};

#endif /* Agent_hpp */
