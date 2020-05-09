#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SDL2/SDL.h>

namespace fl {

class Screen {
	public:
		static const int SCREEN_WIDTH = 1900;
		static const int SCREEN_HEIGHT = 1060;
		static const int BLUR_BOX_HALF_SIZE = 2;
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_main_buffer;
		Uint32 *m_temp_buffer;
	public:
		Screen();
		bool init();
		bool process_events();
		void update();
		void clear();
		void box_blur();
		void set_pixel(int &x, int &y, Uint8 &r, Uint8 &g, Uint8 &b);
		void close();
};

}


#endif /* SCREEN_HPP_ */
