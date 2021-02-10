#include "ofApp.h"

#define BUFFERSIZE 256; // バッファサイズ(256推奨．大きくすると処理に余裕はでるが遅延が長くなる)
#define SAMPLERATE 44100; // サンプルレート(Hz)
#define BPM 160;

//--------------------------------------------------------------
void ofApp::setup(){
    // audio setup
    bufferSize = BUFFERSIZE;
    sampleRate = SAMPLERATE;
    bpm = BPM;
    inputBuffer.resize(bufferSize);
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.setInListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels=2;
    settings.numInputChannels=1;
    settings.bufferSize = bufferSize;
    sound_stream.setup(settings);
    
    myWavWriter = new wavWriter(sampleRate, 16);
    myMetronome = new metronome(bpm, sampleRate);
    myButton = new recordingButton(myWavWriter, myMetronome);
    myMetronome->loadSound();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(168, 168, 168);
    myButton->drawButton(ofGetWidth()-3*myButton->buttonWidth, 0);
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &buffer){
    const int frames = buffer.getNumFrames();
    if (myButton->microphoneMute) {
        // ミュートのときはマイクから音を拾わない
        for(int i = 0; i < frames; i++){
            inputBuffer[i] = 0.;
        }
    } else {
        for(int i = 0; i < frames; i++){
            inputBuffer[i] = buffer[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &buffer){
    const int frames = buffer.getNumFrames();
    for(int i = 0; i < frames; i++){
        const int channels = buffer.getNumChannels();
        float currentSample = inputBuffer[i];
        myWavWriter->recording(currentSample);
        buffer[i*channels+0] = currentSample;
        buffer[i*channels+1] = currentSample;
        
        myMetronome->play();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    myButton->buttonMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::exit(){
    myWavWriter->wave_write("recording.wav");
}
