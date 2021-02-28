#pragma once

#include "ofMain.h"
#include "wavWriter.hpp"
#include "recordingButton.hpp"
#include "metronome.hpp"
#include "ofxAudioFile.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        // audio setting
        void audioIn(ofSoundBuffer &buffer);
        void audioOut(ofSoundBuffer &buffer);
        ofSoundStream sound_stream;

        int bufferSize;
        int sampleRate;
        int bpm;
        vector<float> inputBuffer;
    
        wavWriter* myWavWriter;
        recordingButton* myButton;
        metronome* myMetronome;
        ofxAudioFile audiofile;
        float playhead;
        float step;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void exit();
		
};
