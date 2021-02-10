//
//  recordingButton.hpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/10.
//

#pragma once

#include "ofMain.h"
#include "wavWriter.hpp"

class recordingButton {
    public:
        int buttonUpperLeftX;
        int buttonUpperLeftY;
        int butonRadius;
        int buttonWidth;
        int buttonHeight;
        wavWriter* myWavWriter;
        bool microphoneMute;
        recordingButton(wavWriter* myWavWriter);
        ~recordingButton();
        void drawButton(int x, int y);
        void drawRecordngButton();
        void drawMicrophoneButton();
        void drawMetronomeButton();
        void buttonMousePressed(int x, int y, int button);
    private:
        ofImage microphoneIcon;
        ofImage muteIcon;
};
