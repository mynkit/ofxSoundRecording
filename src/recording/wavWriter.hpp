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
        int fs;
        int bits;
        wavWriter(int fs, int bits);
        ~wavWriter();
        void wave_write(vector<float> data, char *filename);
};
