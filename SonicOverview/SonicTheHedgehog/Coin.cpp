#include "Coin.h"

#include "GameManager.h"

#include <SFML\Graphics.hpp>

Coin::Coin(Texture * texture, Vector2f size) {
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
}

Coin::~Coin() {}

void Coin::Draw(RenderWindow & window) {
	window.draw(body);
}