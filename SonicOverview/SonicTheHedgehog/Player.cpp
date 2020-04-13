#include "Player.h"
#include "GameManager.h"
//do not move this around
Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(Vector2f(100.0f, 150.0f));
	body.setPosition(50.0f, 600.0f); //where player is initially! (sonic in this case)
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}


Player::~Player()
{
}


void Player::Update(float deltaTime)
{
	velocity.x  *= 0.00f; //slowly stop moving higher is slower time to stop (aka sonics physics engine kinda)
	if (Keyboard::isKeyPressed(Keyboard::A)) //if a is pressed go left
		velocity.x -= speed; // moves according to time
	if (Keyboard::isKeyPressed(Keyboard::D)) //if d is pressed go right
		velocity.x += speed; // moves according to time
	if (Keyboard::isKeyPressed(Keyboard::Space) && canJump)
	{
		if (gameOver == 1)
		{
			PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		canJump = false; //cant jump cuz jumping
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight); //9.81 grav *** -> set 100 sfml units = a meter here
		// the - infront of sqrtrf makes it so you jump up not down
	}

	velocity.y += 981.0f *deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0; //doing idle animation
	}
	else
	{
		row = 1; //movement animation

		if (velocity.x > 0.0f)
		{
			faceRight = true; // if he is facing right, face right
		}
		else {
			faceRight = false; //if he is NOT facing right, face left
		}
	}


	if (canJump == false)
	{
		row = 2;
	}

	//updates animation to whatever is set
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime); //not frame specific 
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(Vector2f direction)
{

	if (direction.x < 0.0f)
	{
		//collision of left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//collision of right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//collision of ground (bottom)
		velocity.y = 0.0f;
		canJump = true; //if colliding with ground you can jump
	}
	else if (direction.y > 0.0f)
	{
		//colliding on the top of sonics head
		velocity.y = 0.0f;
	}
}
