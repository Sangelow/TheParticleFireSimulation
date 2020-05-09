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
	int t = SDL_GetTicks();
	int tm1;
	int delta;
	int x;
	int y;
	Uint8 r;
	Uint8 g;
	Uint8 b;

	// Main loop
	while (true) {
		
		// Get time since the last iteration
		tm1 = t;
		t = SDL_GetTicks();
		delta = t-tm1;
		cout << "FPS: " << 1.e3/delta << endl;

		// Update particles
		swarm.update(delta);

		// Get particles
		const Particle *particles = swarm.get_particles();

		// Draw particles
		for (int i=0; i<Swarm::N_PARTICLES; i++) {

			// Get the particle
			Particle particle = particles[i];

			// Convert particle position to screen position
			x = (particle.m_x+1)*Screen::SCREEN_WIDTH/2;
			y = (particle.m_y*Screen::SCREEN_WIDTH/2)+Screen::SCREEN_HEIGHT/2;

			// Set the particle color
			r = 127.5*(1+cos(particle.m_x*t*1e-3));
			g = 127.5*(1+cos(particle.m_y*t*1e-3+2/3*M_PI));
			b = 127.5*(1+cos(particle.m_x*t*1e-3+4/3*M_PI));

			// Set the pixel
			screen.set_pixel(x, y, r, g, b);
		}

		// Blur particles
		screen.box_blur();

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
