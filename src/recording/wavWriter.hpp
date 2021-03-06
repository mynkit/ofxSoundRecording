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
        int channel;
        vector<float> recordingBuffer;
        bool recordingOn;
        wavWriter(int sampleRate, int bits, int channel);
        ~wavWriter();
        void wave_write(string filenameStr);
        void recording(float sample);
        void setRecordingOn();
};
