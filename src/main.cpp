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

	// Main loop
	while (true) {
		// Update particles
		//
		// Draw particles

		// Check for events
		if (screen.process_events() == false) {
			break;
		}
	}


	// Close the screen
	screen.close();

	return 0;
}
