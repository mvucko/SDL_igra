#include "graphics.h"
#include "SDL.h"

//Klasa za grafiku
//Sva sranja za grafiku su tamo

Graphics::Graphics() {

	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Igra");
	
}

Graphics::~Graphics() {

	SDL_DestroyWindow(this->_window);

}