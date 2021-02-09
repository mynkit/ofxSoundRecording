//
//  datParser.cpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/09.
//

#include "datParser.hpp"

datParser::datParser(string datPath) {
    ofBuffer fileBuffer = ofBufferFromFile(datPath);
    string text = fileBuffer.getText();
    soundData = splitString(text, ',');
}

//文字列delimiterでspitしてvector配列を返すメソッド(文字列を全てfloatに変換する)
vector<float> datParser::splitString(string& input, char delimiter) {
    istringstream stream(input);
    string field;
    vector<float> result;
    int length = 0;
    while (getline(stream, field, delimiter)) {
        if (field != "") {
            result.push_back(stof(field));
            length++;
        }
    }
    result.resize(length);
    return result;
}
