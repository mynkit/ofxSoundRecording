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
    string filepath = ofToDataPath("owarinokisetsuguitar.wav");
    if( ofFile::doesFileExist( filepath ) ){
        audiofile.load( filepath );
        if (!audiofile.loaded()){
            ofLogError()<<"error loading file, double check the file path";
        }
    }else{
        ofLogError()<<"input file does not exists";
    }
    //playhead = numeric_limits<int>::max(); // because it is converted to int for check
    playhead = 0;
    step = audiofile.samplerate() / sampleRate;
    cout << filepath << "のサンプリングレート: " << audiofile.samplerate() << endl;
    cout << filepath << "の長さ: " << audiofile.length() << endl;
    cout << filepath << "のチャンネル数: " << audiofile.channels() << endl;
    
    inputBuffer.resize(bufferSize);
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.setInListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels=2;
    settings.numInputChannels=1;
    settings.bufferSize = bufferSize;
    sound_stream.setup(settings);
    
    myWavWriter = new wavWriter(sampleRate, 16, 2);
    myMetronome = new metronome(bpm, sampleRate);
    myButton = new recordingButton(myWavWriter, myMetronome);
    myMetronome->loadSound();
    myButton->loadImg();
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
        // ミュートのときはwavファイルを再生
        for (int i = 0; i < frames; i++){
            int n = playhead;
            if( n < audiofile.length()-1 ){
                for( size_t k=0; k<buffer.getNumChannels(); ++k){
                    float fract = playhead - (double) n;
                    float s0 = audiofile.sample( n, k );
                    float s1 = audiofile.sample( n+1, k );
                    float isample = s0*(1.0-fract) + s1*fract; // linear interpolation
                    inputBuffer[i] = isample;
                }
                playhead += step;
            }else{
                inputBuffer[i] = 0.;
                playhead = 0; // ループ
            }
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
        myWavWriter->recording(currentSample); // L
        myWavWriter->recording(currentSample); // R
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
