//
//  recordingButton.hpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/10.
//

#pragma once

#include "ofMain.h"
#include "wavWriter.hpp"
#include "metronome.hpp"

class recordingButton {
    public:
        int buttonUpperLeftX;
        int buttonUpperLeftY;
        int butonRadius;
        int buttonWidth;
        int buttonHeight;
        wavWriter* myWavWriter;
        metronome* myMetronome;
        bool microphoneMute;
        recordingButton(wavWriter* myWavWriter, metronome* myMetronome);
        ~recordingButton();
        void loadImg();
        void drawButton(int x, int y);
        void drawRecordngButton();
        void drawMicrophoneButton();
        void drawMetronomeButton();
        void buttonMousePressed(int x, int y, int button);
    private:
        ofImage microphoneIcon;
        ofImage muteIcon;
        ofImage metronomeIcon;
};
