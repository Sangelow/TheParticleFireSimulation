#include <iostream>
#include <iomanip>
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

	// Update the texture

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

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	// Check if the x and y value are on the screen
	if ( x < 0 || SCREEN_WIDTH <= x ) {
        throw std::invalid_argument( "Invalid x value in screen.set_pixel" );
    }
	if ( y < 0 || SCREEN_HEIGHT <= y ) {
        throw std::invalid_argument( "Invalid y value in screen.set_pixel" );
	}
	// Set the color
	Uint32 color = (r << 24) |  (g << 16) | (b << 8) | 0xFF ;
	// Set the color of the pixel
	m_buffer[x + y*SCREEN_WIDTH] = color;
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
