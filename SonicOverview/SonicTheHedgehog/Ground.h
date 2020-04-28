#pragma once
#include "GameManager.h"

#include "Collision.h"

#include <SFML\Graphics.hpp>

using namespace sf;
class Ground {
public:
	Ground(Texture * texture, Vector2f size, Vector2f position);
	~Ground();

	void Draw(RenderWindow & window);
	Collision GetCollider() {
		return Collision(body);
	}

private:
	RectangleShape body;
};