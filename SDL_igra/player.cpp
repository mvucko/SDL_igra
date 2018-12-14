#include "player.h"
#include "graphics.h"


namespace player_constants {
	const float WALK = 0.2f;
};

Player::Player(){}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "sprites/lik.png", 0,0, 16,16,x,y,100){
	
	graphics.loadImage("sprites/lik.png");
	this->setupAnimations();
	this->playAnimation("TrciDesno");
}

void Player::setupAnimations() {
	this->addAnimation(1, 0, 0, "GledajLijevo", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "GledajDesno", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "TrciLijevo", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "TrciDesno", 16, 16, Vector2(0, 0));

}

void Player::animationDone(std::string currentAnimation){}


void Player::moveLeft() {
	this->_dx = -player_constants::WALK;
	this->playAnimation("TrciLijevo");
	this->_facing = LEFT;
}


void Player::moveRight() {
	this->_dx = player_constants::WALK;
	this->playAnimation("TrciDesno");
	this->_facing = RIGHT;
}

void Player::stopMoving() {
	this->_dx = 0;
	
	if (this->_facing == RIGHT) playAnimation("GledajDesno");
	else playAnimation("GledajLijevo");
	
}


void Player::update(float elapsedTime) {

	this->_x += this->_dx*elapsedTime;
	AnimatedSprite::update(elapsedTime);

}

void Player::draw(Graphics &graphics) {

	
	AnimatedSprite::draw(graphics, this->_x, this->_y);

}