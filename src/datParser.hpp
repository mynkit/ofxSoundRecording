//
//  datParser.hpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/09.
//

#pragma once

#include "ofMain.h"

class datParser {
    public:
        datParser(string datPath);
        ~datParser();
        vector<float> splitString(string& input, char delimiter);
        vector<float> soundData;
};
