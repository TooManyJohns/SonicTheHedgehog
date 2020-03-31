#pragma once
#include "GameManager.h"
using namespace sf;
class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);

	//variables
	IntRect uvRect;





private:
	Vector2u imageCount; //how many images are there?
	Vector2u currentImage;


	//priv variables
	float totalTime;
	float switchTime; //amount of time til next image

};
