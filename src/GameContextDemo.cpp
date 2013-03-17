#include "../include/GameContext.hpp"
#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <math.h>
#include <curses.h>
#include "../include/TextureLoader.hpp"
#include "GameContextDemo.hpp"

void GameContextDemo::init() {
	glMatrixMode(GL_PROJECTION);
    glOrthox(-160<<16, 160<<16, -120<<16, 120<<16, -128<<16, 128<<16);
   	// reset model position
   	glMatrixMode(GL_MODELVIEW);
	TextureLoader loader;
	loader.loadFile("images/man.jpg");
	unsigned char * rawData = loader.getData();
    	glEnable(GL_TEXTURE_2D);
    	glEnable(GL_BLEND);
    	glBlendFunc(GL_ONE, GL_SRC_COLOR);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, rawData);

	texCoords = new GLfloat[8];
	texCoords[0] = 0.0;
	texCoords[1] = 1.0;
	texCoords[2] = 1.0;
	texCoords[3] = 1.0;
	texCoords[4] = 0.0;
	texCoords[5] = 0.0;
	texCoords[6] = 1.0;
	texCoords[7] = 0.0;

	mVertices = new signed short[12];
	mVertices[0] = -80;
	mVertices[1] = -80;
	mVertices[2] = 0;
    	mVertices[3] = 80;
	mVertices[4] = -80;
	mVertices[5] = 0;
	mVertices[6] = -80;
	mVertices[7] = 80;
	mVertices[8] = 0;
	mVertices[9] = 80;
	mVertices[10] = 80;
	mVertices[11] = 0;

    	glEnableClientState(GL_VERTEX_ARRAY);
    	glVertexPointer(3, GL_SHORT, 0, mVertices);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glPointSize(4);
}

void GameContextDemo::loop(){
	int k = getch();
		if (k != ERR) {
			if (k == 106) {
			} else if (k == 105) {
				this->game->stop();
			} else if (k == 107) {
			} else if (k == 108) {
			}
		}
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0,0,0,1);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glRotatef(1, 1.5 , 1 , 0.2 );
}

