#pragma once

#ifndef LEVEL_H
#define LEVEL_H
#include "globalne_var.h"
#include <string>
#include "graphics.h"


class Graphics;
struct SDL_Texture;

class Level {

public: 
	Level();

	Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);

	~Level();

	void update(int elapsedTime);
	void draw(Graphics &graphics);




private:

	std::string _mapName;
	Vector2 _spawnPoint;

	Vector2 _size;
	
	SDL_Texture* _backgroundTexture;

	void loadMap(std::string mapName, Graphics &graphics); // ovo ce se zvat samo iz klase, pa ne mora bit public. Mozda je i bolje. Pitaj Radosevica xd.


};

#endif // ! LEVEL_H
