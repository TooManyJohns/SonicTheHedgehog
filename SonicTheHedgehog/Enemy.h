#pragma once
#include "GameManager.h"
#include "Collision.h"
#include <SFML\Graphics.hpp>
#include "Animation.h"
using namespace sf;



class Enemy
{
public:
	Enemy(Texture* texture, Vector2f size, Vector2u imageCount, float switchTime, float speed);
	~Enemy();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	Collision GetCollider() { return Collision(body); }


	void OnCollision(Vector2f direction);
	FloatRect getGlobalBounds() {
		return body.getGlobalBounds(); //gets bounds for detection inside Player.h
	}
	void setPos(sf::Vector2f newPos) {
		body.setPosition(newPos);
	}
	Vector2f GetterPos() { return body.getPosition(); }
private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	Vector2f velocity;

};

