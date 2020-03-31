#include "Ground.h"
#include <SFML\Graphics.hpp>


Ground::Ground(Texture * texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}



Ground::~Ground()
{
}

void Ground::Draw(RenderWindow & window)
{
	window.draw(body);
}
