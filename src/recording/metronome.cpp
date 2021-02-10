//
//  metronome.cpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/10.
//

#include "metronome.hpp"

metronome::metronome(int bpm, int sampleRate) {
    currentIndex = 0;
    this->bpm = bpm;
    metronomeOn = false;
    this->sampleRate = sampleRate;
    // 1分間に{bpm}回音なるので、1回の音の長さは{60./bpm}秒.
    // その間のサンプル数は{60./bpm * sampleRate}
    targetSampleNum = (sampleRate * 60.) / bpm;
}

// ofApp.cppのsetup内で用いてください
void metronome::loadSound() {
    tabla.load("sounds/tabla/011_hi_hit2.wav");
}

void metronome::setBpm(int bpm) {
    this->bpm = bpm;
}

void metronome::setMetronomeOn() {
    if (metronomeOn) {
        metronomeOn = false;
    } else {
        metronomeOn = true;
    }
}

// ofApp.cppのaudioOut内で用いてください
void metronome::play() {
    if (metronomeOn) {
        if (currentIndex >= targetSampleNum) {
            currentIndex -= targetSampleNum;
        }
        if (currentIndex < 1) {
            tabla.play();
        }
        currentIndex++;
    }
}
