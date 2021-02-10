//
//  wavWriter.hpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/09.
//

#pragma once

#include "ofMain.h"

class wavWriter {
    public:
        int sampleRate;
        int bits;
        vector<float> recordingBuffer;
        wavWriter(int sampleRate, int bits);
        ~wavWriter();
        void wave_write(string filenameStr);
        void recording(float sample);
};
