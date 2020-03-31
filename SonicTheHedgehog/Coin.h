#pragma once
#include "GameManager.h"
#include "Collision.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Coin
{
public:
	Coin(Texture* texture, Vector2f size);
	~Coin();
	void Draw(RenderWindow& window);
	Collision GetCollider() { return Collision(body); }
	FloatRect getGlobalBounds() {
		return body.getGlobalBounds(); //gets bounds for detection inside Player.h
	}
	void setPos(sf::Vector2f newPos) {
		body.setPosition(newPos);
	}



private:
	RectangleShape body;

};

