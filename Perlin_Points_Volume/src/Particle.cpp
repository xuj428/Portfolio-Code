//
//  Particle.cpp
//  Perlin_Points
//
//  Created by xjjulia on 21/10/13.
//
//

#include "Particle.h"

Particle::Particle(){
    
}

void Particle::setup(ofVec2f Pos, float Vel,float hue){
    pos = Pos;
    vel.x=ofRandom(-Vel, Vel);
    vel.y=ofRandom(-Vel,Vel);
    lifeTime = ofRandom(200,300);
    age = 0;
    isDead = false;
    float rand=ofRandom(0,1);
   // cout<<rand<<endl;
    if (0.7<rand<1) {
        c.setHsb(10+ofRandom(-20.0,20.0), 255, 255);
    }
    if (0.3<=rand<=0.7) {
        c.setHsb(80+ofRandom(-20.0,20.0), 255,255);
    }
    else{
        c.setHsb(150+ofRandom(-20.0,20.0), 255, 255 );
    }
    
    
}

void Particle::passValues(float *_xNoiseValue, float *_yNoiseValue, float *_zNoiseValue, float *_xNoiseScale, float *_yNoiseScale, float *_xAngleOffset,float *_yAngleOffset, float *_pr) {
    
    xNoiseValue = _xNoiseValue;
    yNoiseValue = _yNoiseValue;
    zNoiseValue = _zNoiseValue;

    xNoiseScale = _xNoiseScale;
    yNoiseScale = _yNoiseScale;
    
    xAngleOffset = _xAngleOffset;
    yAngleOffset = _yAngleOffset;
    pr = _pr;
//    color1 = _color1;
//    color2 = _color2;
//    color3 = _color3;
//    
}

void Particle::update(float vecScale){
//    noiseFloat = ofNoise(pos.x * 0.0025, pos.y * 0.0025, ofGetElapsedTimef() * 0.001);
//    noiseVec.x = cos(((noiseFloat -0.3) * TWO_PI) * 10);
//    noiseVec.y = sin(((noiseFloat - 0.3) * TWO_PI) * 10);
//    cout<<noiseVec<<endl;
    
    
    noiseFloat = ofNoise(pos.x * *xNoiseValue, pos.y * *yNoiseValue, ofGetElapsedTimef() * *zNoiseValue);
    noiseVec.x = vecScale * cos(((noiseFloat -0.3) * (TWO_PI + *xAngleOffset)) * *xNoiseScale);
    noiseVec.y = vecScale * sin(((noiseFloat - 0.3) * (TWO_PI + *yAngleOffset)) * *yNoiseScale);
    
    
    vel += noiseVec;
    vel *=0.8;
    pos += vel;
    if(1.0-(age/lifeTime) <= 0){
        isDead = true;
    }
    
    if(pos.x < 0 || pos.x > ofGetWindowWidth() || pos.y < 0 || pos.y > ofGetWindowHeight()){
        isDead = true;
    }
    
    age+=0.9;
    
}

void Particle::draw(){
    ofSetColor(c,100);
    ofCircle(pos.x, pos.y, *pr * (1-(age/lifeTime)));
    
}
