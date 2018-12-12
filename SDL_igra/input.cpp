#include "input.h";

//klasa za input, prati sta je pritisnuto, pusteno, itd...

//Ova funkcija se pozove na pocetku svakog framea da makne tipke koje su vec bile pritisnute
void Input::beginNewFrame() {

	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
	
}

//ovo se zove kad se tipka pritisne

void Input::keyDownEvent(const SDL_Event& event) {

	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;

}

//ovo se zove kad se tipka pusti

void Input::keyUpEvent(const SDL_Event& event) {

	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;

}

//ovo provjera jel tipka pritisnuta tijekom trenutnog framea

bool Input::wasKeyPressed(SDL_Scancode key) {

	return this->_pressedKeys[key];

}

bool Input::wasKeyReleased(SDL_Scancode key) {

	return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {

	return this->_heldKeys[key];

}