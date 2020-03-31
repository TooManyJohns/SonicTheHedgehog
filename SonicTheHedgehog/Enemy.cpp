#include "Enemy.h"
#include "GameManager.h"
#include <SFML\Graphics.hpp>
#include "Animation.h"

Enemy::Enemy(Texture* texture, Vector2f size, Vector2u imageCount, float switchTime, float speed) :
animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	this->speed = speed;
	row = 0;
	faceRight = true;
}


Enemy::~Enemy()
{
}

void Enemy::Draw(RenderWindow & window)
{
	window.draw(body);
}




void Enemy::Update(float deltaTime)
{

	velocity.y += 0;
	if (velocity.x == 0.0f)
	{
		row = 0; //doing idle animation
	}
	else
	{
		row = 0; //movement animation

		if (velocity.x > 0.0f)
		{
			faceRight = true; // if he is facing right, face right
		}
		else {
			faceRight = false; //if he is NOT facing right, face left
		}


		//updates animation to whatever is set
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		body.move(velocity * deltaTime); //not frame specific 
	}
}


void Enemy::OnCollision(Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision of left
		velocity.x = 0;
		velocity.x -= speed; // moves according to time
	}
	else if (direction.x > 0.0f)
	{
		//collision of right
		velocity.x = 0;
		velocity.x += speed;

	}
	if (direction.y < 0.0f)
	{
		//collision of ground (bottom)
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//colliding on the top of sonics head
		velocity.y = 0.0f;
	}
}
