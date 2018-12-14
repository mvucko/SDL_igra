#pragma once
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include "sprite.h"
#include <map>
#include <string>
#include "globalne_var.h"
#include <vector>

class Graphics;

//za animirane slicice, logika za animacije


class AnimatedSprite : public Sprite {
public: 

		AnimatedSprite();
		AnimatedSprite(Graphics &graphics, const std::string &filepath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

		void playAnimation(std::string animation, bool once = false); // ovo igra animaciju ako vec nije vanka

		

		void update(int elapsedTime); //osvjezava animaciju sa tajmerom


		//ovo ce crtat animacije na ekran:
		void draw(Graphics &graphics, int x, int y);

	

protected:

	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	//dodaje animaciju u mapu animacija:
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	//resetira sve animacije vezane uz taj sprite
	void resetAnimations();

	
	//zaustavlja anim
	void stopAnimation();

	//bira jel vidljiva il nije
	void setVisible(bool visible);


	virtual void animationDone(std::string currentAnimation) = 0;

	virtual void setupAnimations() = 0;

private:

	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;



};

#endif // !ANIMATED_SPRITE_H
