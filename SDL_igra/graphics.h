#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <map>
#include <string>
#include "SDL_image.h"
#include "SDL.h"
struct SDL_Window;
struct SDL_Renderer;


//ovo je zasluzno za sve s grafikom
class Graphics {

public:
	Graphics();
	~Graphics();

	SDL_Surface* loadImage(const std::string &filePath); //ucitava sliku unutar _spriteSheets mapu ako ona vec nije ucitana. 

	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destitnationRectangle); //ovo crta na ekran arg: 1: fajl iz kojeg dolazi, 2: dio slike koji se crta, 3: gdje se crta.

	void flip();   //ovo renderira sve na ekran


	void clear();  //ovaj brise sve s ekrana

	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif