#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    void setup(ofVec2f Pos, float Vel,float hue);
    //void passValues(vector <float *> values);
    void passValues(float *_xNoiseValue, float *_yNoiseValue, float *_zNoiseValue, float *_xNoiseScale, float *_yNoiseScale, float *_xAngleOffset,float *_yAngleOffset, float *_pr);
    void update(float vecScale);
    void draw();
    
    ofVec2f pos, vel, noiseVec;
    float noiseFloat, lifeTime, age;
    bool isDead;
    ofColor c;
    
    float *xNoiseValue,*yNoiseValue,*zNoiseValue;
    float *xNoiseScale,*yNoiseScale;
    float *xAngleOffset,*yAngleOffset;
    float *pr;
//    float *color1,*color2,*color3;
    
    
    
};
