//
//  metronome.hpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/10.
//

#pragma once

#include "ofMain.h"

class metronome {
    public:
        int bpm;
        bool metronomeOn;
        int bufferSize;
        int sampleRate;
        metronome(int bpm, int sampleRate);
        ~metronome();
        void setBpm(int bpm);
        void setMetronomeOn();
        void loadSound();
        void play();
        ofSoundPlayer click;

    private:
        float currentIndex;
        float targetSampleNum;
};

