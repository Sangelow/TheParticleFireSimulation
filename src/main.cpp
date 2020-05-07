#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.hpp"
#include "Swarm.hpp"

using namespace std;
using namespace fl;

int main(){

	// Instanciate the screen object
	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing Screen" << endl;
		return 1;
	}

	// Initialize the random seed
	srand(time(NULL));

	// Declare a swarm
	Swarm swarm;

	// Declare variables for the main loop
	float t;
	float tm1;
	int x;
	int y;
	Uint8 r;
	Uint8 g;
	Uint8 b;

	// Main loop
	while (true) {
		// Update particles
		swarm.update();

		// Reset the screen buffer
		screen.clear();
		
		// Draw particles
		tm1 = t;
		t = 1e-3*SDL_GetTicks();
		cout << "FPS: " << 1/(t-tm1) << endl;

		// Get the particles
		const Particle *particles = swarm.get_particles();

		for (int i=0; i<Swarm::N_PARTICLES; i++) {

			// Get the particle
			Particle particle = particles[i];

			// Convert particle position to screen position
			x = (particle.m_x+1)*Screen::SCREEN_WIDTH/2;
			y = (particle.m_y+1)*Screen::SCREEN_HEIGHT/2;

			// Set the particle color
			r = 255; //127.5*(1+cos(t));
			g = 255; //127.5*(1+cos(t));
			b = 255; //127.5*(1+cos(t));

			// Set the pixel
			screen.set_pixel(x, y, r, g, b);

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

		/*
		Uint8 r;
		Uint8 g;
		Uint8 b;
		float x;
		float y;
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
		*/
