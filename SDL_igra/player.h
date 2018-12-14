#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "globalne_var.h"
#include "animirani.h"


class Graphics;

class Player :public AnimatedSprite {

public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void moveLeft();			//pomakni ciku lijevo za _dx
	void moveRight();			//pomakni ciku desno za _dx
	void stopMoving();			//prestani mrdat ciku

private:

	float _dx, _dy; //delta x i y, kolko je pomaknut

	Direction _facing;

};
#endif // !PLAYER_H
