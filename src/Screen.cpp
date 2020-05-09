#include <iostream>
#include <iomanip>
#include "Screen.hpp"

namespace fl {

Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_main_buffer(NULL) {
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
	m_main_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// Create the temp buffer
	m_temp_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// Initialise the screen color to black
	clear();

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
	SDL_UpdateTexture(m_texture, NULL, m_main_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::clear() {
	// Set all the value in the buffer to 0
	memset(m_main_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::box_blur() {
	// Store the current main buffer into the temp buffer
	for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		m_temp_buffer[i] = m_main_buffer[i];
	}
	// Reset the main buffer
	clear();
	// NOTE: this loop could be written in parallel for better perfomances
	#pragma omp parallel
	#pragma omp for
	for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		// Reset the color sum
		int r_tot = 0;
		int g_tot = 0;
		int b_tot = 0;
		// Set position variables
		int x = i % SCREEN_WIDTH;
		int y = i / SCREEN_WIDTH;
		// If the pixel is on a boundary of the screen, continue to the next pixel
		if ( x <=  BLUR_BOX_HALF_SIZE || SCREEN_WIDTH - BLUR_BOX_HALF_SIZE <= x ) {
			continue;
		}
		if ( y <= BLUR_BOX_HALF_SIZE || SCREEN_HEIGHT - BLUR_BOX_HALF_SIZE <= y ) {
			continue;
		}
		// Average the color in the box
		for (int n_x=x-BLUR_BOX_HALF_SIZE+1; n_x<x+BLUR_BOX_HALF_SIZE; n_x++) {
			for (int n_y=y-BLUR_BOX_HALF_SIZE+1; n_y<y+BLUR_BOX_HALF_SIZE; n_y++) {
				// Increment the colors
				r_tot += (int)((m_temp_buffer[n_x + n_y*SCREEN_WIDTH] & 0xFF000000) >> 24);
				g_tot += (int)((m_temp_buffer[n_x + n_y*SCREEN_WIDTH] & 0x00FF0000) >> 16);
				b_tot += (int)((m_temp_buffer[n_x + n_y*SCREEN_WIDTH] & 0x0000FF00) >> 8);
			}
		}
		// Average the color
		Uint8 r = r_tot /((2*BLUR_BOX_HALF_SIZE - 1)*(2*BLUR_BOX_HALF_SIZE - 1));
		Uint8 g = g_tot /((2*BLUR_BOX_HALF_SIZE - 1)*(2*BLUR_BOX_HALF_SIZE - 1));
		Uint8 b = b_tot /((2*BLUR_BOX_HALF_SIZE - 1)*(2*BLUR_BOX_HALF_SIZE - 1));
		// Set the pixel color
		set_pixel(x, y, r, g, b);
	}
}

void Screen::set_pixel(int &x, int &y, Uint8 &r, Uint8 &g, Uint8 &b) {
	// Check if the x and y value are on the screen
	if ( x < 0 || SCREEN_WIDTH <= x ) {
		return;
        // throw std::invalid_argument( "Invalid x value in screen.set_pixel" );
    }
	if ( y < 0 || SCREEN_HEIGHT <= y ) {
		return;
        // throw std::invalid_argument( "Invalid y value in screen.set_pixel" );
	}
	// Set the color of the pixel
	m_main_buffer[x + y*SCREEN_WIDTH] = (r << 24) |  (g << 16) | (b << 8) | 0xFF;
}

void Screen::close() {
	// Free the buffer
	delete [] m_main_buffer;
	// Frree the temp buffer
	delete [] m_temp_buffer;
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
