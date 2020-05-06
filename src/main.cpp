#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include "Screen.hpp"

using namespace std;
using namespace fl;

int main(){

	// Instanciate the screen object
	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing Screen" << endl;
		return 1;
	}
	
	float t;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	float x;
	float y;

	// Main loop
	while (true) {
		// Update particles
		// Draw particles
		t = 1e-3*SDL_GetTicks();
		for (int i=0; i<screen.SCREEN_WIDTH; i++) {
			x = (float)i/screen.SCREEN_WIDTH;
			for (int j=0; j<screen.SCREEN_HEIGHT; j++) {
				y = (float)j/screen.SCREEN_HEIGHT;
				r = 127.5*(1+cos(t+M_PI*y*t));
				g = 127.5*(1+cos(t*t+M_PI*y*x*t));
				b = 127.5*(1+cos(t+M_PI*x*t));
				screen.set_pixel(i, j, r, g, b);
			}
		}

		// Update the screen
		screen.update();

		// Check for events
		if (screen.process_events() == false) {
			break;
		}
	}


	// Close the screen
	screen.close();

	return 0;
}
