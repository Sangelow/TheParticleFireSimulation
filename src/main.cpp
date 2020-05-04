#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}

	cout << "Successfull initialisation !" << endl;

	SDL_Window* window = SDL_CreateWindow(
			"Hello world",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_OPENGL);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
