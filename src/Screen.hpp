#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SDL2/SDL.h>

namespace fl {

class Screen {
	public:
		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;
	public:
		Screen();
		bool init();
		bool process_events();
		void close();
};

}


#endif /* SCREEN_HPP_ */
