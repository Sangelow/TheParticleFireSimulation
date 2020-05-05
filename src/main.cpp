#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

using namespace std;

int main(){
	// Declare constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Check if SDL2 is working
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}
	cout << "SDL initialized" << endl;


	// Create a window
	SDL_Window *window = SDL_CreateWindow(
		"Particule Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
	
	// Check if the window is created
	if (window == NULL) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}
	cout << "Window created" << endl;

	// Create renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);

	// Create texture
	SDL_Texture *texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);

	// Create the buffer
	Uint32 *buffer_1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	Uint32 *buffer_2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	// Set the value of each bytes in the block of memory
	memset(buffer_1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	// Set the value of
	unsigned char R = 0;
	unsigned char G = 0;
	unsigned char B = 0;
	unsigned char A = 0;
	Uint32 color;
	int x;
	int y;
	for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		x = i % SCREEN_WIDTH;
		y = i / SCREEN_WIDTH;
		//R = 255*sin(2*M_PI*x/SCREEN_WIDTH);
		//G = 255*sin(2*M_PI*x/SCREEN_WIDTH + M_PI/2);
		//B = 255*sin(2*M_PI*x/SCREEN_WIDTH + M_PI/4);
		buffer_1[i] = (R << 24) |  (G << 16) | (B << 8) | A ;
	}

	// Init the texture
	SDL_UpdateTexture(texture, NULL, buffer_1, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);


	bool quit = false;
	SDL_Event event;

	while (!quit) {
		// Update particles
		// Draw particles

		// Check for events
		while (SDL_PollEvent(&event)) {
			// Check if the event is a quit event
			if (event.type == SDL_QUIT) {
				cout << "Catch quit event" << endl;
				quit = true;
			}
		}
	}

	// Free the buffer
	delete [] buffer_1;
	delete [] buffer_2;
	// Destroy the texture
	SDL_DestroyTexture(texture);
	// Destroy the renderer
	SDL_DestroyRenderer(renderer);
	// Destroy the windown
	SDL_DestroyWindow(window);
	// Quit SDL
	SDL_Quit();

	return 0;
}
