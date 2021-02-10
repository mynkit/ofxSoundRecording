//
//  recordingButton.cpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/10.
//

#include "recordingButton.hpp"

recordingButton::recordingButton(wavWriter* myWavWriter) {
    buttonUpperLeftX = 0;
    buttonUpperLeftY = 0;
    butonRadius = 5;
    buttonWidth = 70;
    buttonHeight = 50;
    this->myWavWriter = myWavWriter;
    microphoneMute = true;
    microphoneIcon.load("icons/microphone.png");
    muteIcon.load("icons/mute.png");
}

void recordingButton::drawButton(int x, int y) {
    buttonUpperLeftX = x;
    buttonUpperLeftY = y;
    drawRecordngButton();
    drawMicrophoneButton();
    drawMetronomeButton();
    // 影(下の線)
    ofSetColor(91, 91, 91);
    ofDrawRectangle(buttonUpperLeftX+butonRadius, buttonUpperLeftY+buttonHeight, buttonWidth*3-butonRadius*2, 1);

}

void recordingButton::drawRecordngButton() {
    ofRectangle recordingButton;
    recordingButton.x = buttonUpperLeftX;
    recordingButton.y = buttonUpperLeftY;
    recordingButton.width = buttonWidth;
    recordingButton.height = buttonHeight;
    ofSetColor(119, 118, 118);
    ofDrawRectangle(buttonUpperLeftX+buttonWidth-butonRadius, buttonUpperLeftY, butonRadius, buttonHeight);
    if (myWavWriter->recordingOn) {
        ofSetColor(184, 43, 37);
    } else {
        ofSetColor(119, 118, 118);
    }
    ofDrawRectRounded(recordingButton, butonRadius);
    if (myWavWriter->recordingOn) {
        ofSetColor(255, 255, 255);
    } else {
        ofSetColor(184, 43, 37);
    }
    ofDrawCircle(buttonUpperLeftX+buttonWidth/2, buttonUpperLeftY+buttonHeight/2, buttonHeight/4);
    // 右隣のボタンとの境界線
    if (myWavWriter->recordingOn) {
        ofSetColor(184, 43, 37);
    } else {
        ofSetColor(91, 91, 91);
    }
    ofDrawRectangle(buttonUpperLeftX+buttonWidth-1, buttonUpperLeftY, 2, buttonHeight);
}

void recordingButton::drawMicrophoneButton() {
    ofRectangle MicrophoneButton;
    MicrophoneButton.x = buttonUpperLeftX + buttonWidth;
    MicrophoneButton.y = buttonUpperLeftY;
    MicrophoneButton.width = buttonWidth;
    MicrophoneButton.height = buttonHeight;
    ofSetColor(119, 118, 118);
    ofDrawRectangle(buttonUpperLeftX+buttonWidth, buttonUpperLeftY, 5, buttonHeight);
    ofDrawRectangle(buttonUpperLeftX+buttonWidth*2-5, buttonUpperLeftY, 5, buttonHeight);
    // マイク・ミュートボタン
    if (microphoneMute) {
        ofSetColor(119, 118, 118);
        ofDrawRectRounded(MicrophoneButton, butonRadius);
        ofSetColor(0, 0, 0);
        muteIcon.draw(MicrophoneButton.x + buttonWidth/2 - buttonHeight/4, MicrophoneButton.y + buttonHeight/4, buttonHeight/2, buttonHeight/2);
    } else {
        ofSetColor(57, 198, 93);
        ofDrawRectRounded(MicrophoneButton, butonRadius);
        ofSetColor(0, 0, 0);
        microphoneIcon.draw(MicrophoneButton.x + buttonWidth/2 - buttonHeight/4, MicrophoneButton.y + buttonHeight/4, buttonHeight/2, buttonHeight/2);
    }
    // 右隣のボタンとの境界線
    ofSetColor(91, 91, 91);
    ofDrawRectangle(buttonUpperLeftX+buttonWidth*2-1, buttonUpperLeftY, 2, buttonHeight);
}


void recordingButton::drawMetronomeButton() {
    ofRectangle MetronomeButton;
    MetronomeButton.x = buttonUpperLeftX + buttonWidth*2 + 1;
    MetronomeButton.y = buttonUpperLeftY + 1;
    MetronomeButton.width = buttonWidth;
    MetronomeButton.height = buttonHeight;
    // bottonの影
    ofSetColor(91, 91, 91);
    ofDrawRectRounded(MetronomeButton, butonRadius);
    // botton本体
    MetronomeButton.x -= 1;
    MetronomeButton.y -= 1;
    ofSetColor(119, 118, 118);
    ofDrawRectangle(buttonUpperLeftX+buttonWidth*2, buttonUpperLeftY, 5, buttonHeight);
    ofSetColor(119, 118, 118);
    ofDrawRectRounded(MetronomeButton, butonRadius);
}

void recordingButton::buttonMousePressed(int x, int y, int button) {
    // 左クリックされた場合
    if (button==0) {
        // 録音ボタン
        if (x>=buttonUpperLeftX && x<buttonUpperLeftX+buttonWidth && y>=buttonUpperLeftY && y<=buttonUpperLeftY+buttonHeight ) {
            myWavWriter->setRecordingOn();
        }
        if (x>=buttonUpperLeftX+buttonWidth && x<buttonUpperLeftX+buttonWidth*2 && y>=buttonUpperLeftY && y<=buttonUpperLeftY+buttonHeight ) {
            if (microphoneMute) {
                microphoneMute = false;
            } else {
                microphoneMute = true;
            }
        }
    }
}
