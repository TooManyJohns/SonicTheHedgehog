#pragma once
#include "Animation.h"
#include <SFML\Graphics.hpp>
#include "GameManager.h"
#include "Collision.h"
#include "Coin.h"
using namespace sf;
class Player
{
public:
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();
	
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void OnCollision(Vector2f direction);

	bool isIdle = true; //he initially isn't moving and can run the animation of an idle position 
	bool canJump; //removed from private, if jump glitches may wanna return it..?
	int gameOver = 0;

	//getter for player position for camera positioning!
	Vector2f GetterPos() { return body.getPosition(); }
	Collision GetCollider() { return Collision(body); }

	bool isCollidingWithCoin(Coin *body) {
		if (Player::body.getGlobalBounds().intersects(body->getGlobalBounds())) {
			return true;
		}
		return false;
	}

	void setPos(sf::Vector2f newPos) {
		body.setPosition(newPos);
	}


private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	Vector2f velocity;

	float jumpHeight;



};

