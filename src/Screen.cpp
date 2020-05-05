#include <iostream>
#include "Screen.hpp"

namespace fl {

Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
}

bool Screen::init() {
	// Check if SDL2 is working
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create a window
	m_window = SDL_CreateWindow(
		"Particule Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
	
	// Check if the window is created
	if (m_window == NULL) {
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// Create renderer
	m_renderer = SDL_CreateRenderer(
			m_window,
			-1,
			SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);

	// Create texture
	m_texture = SDL_CreateTexture(
			m_renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);

	// Create the buffer
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// Initialise the screen color to black
	memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	/* Change pixels colors
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
	*/

	// Init the texture
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}

bool Screen::process_events(){
	// Create SDL_Event
	SDL_Event event;
	// Process each events
	while (SDL_PollEvent(&event)) {
		// Check if the event is a quit event
		if (event.type == SDL_QUIT) {
			std::cout << "Catch quit event" << std::endl;
			return false;
		}
	}
	return true;
}

void Screen::close() {
	// Free the buffer
	delete [] m_buffer;
	// Destroy the texture
	SDL_DestroyTexture(m_texture);
	// Destroy the renderer
	SDL_DestroyRenderer(m_renderer);
	// Destroy the windown
	SDL_DestroyWindow(m_window);
	// Quit SDL
	SDL_Quit();
}


};

