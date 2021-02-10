#pragma once

#include "ofMain.h"
#include "datParser.hpp"
#include "wavWriter.hpp"

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
        vector<float> inputBuffer;
    
        wavWriter* myWavWriter;

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
