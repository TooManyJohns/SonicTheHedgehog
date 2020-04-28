#include "GameManager.h"

#include "Animation.h"
// do not move around
Animation::Animation(Texture * texture, Vector2u imageCount, float switchTime) {
	this -> imageCount = imageCount;
	//left is private var, right is pass var

	this -> switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0; //what frame it starts at
	uvRect.width = texture -> getSize().x / float(imageCount.x);
	uvRect.height = texture -> getSize().y / float(imageCount.y);
}

Animation::~Animation() {

}

void Animation::Update(int row, float deltaTime, bool faceRight) {
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++; //switch current image with increments

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0; //resets frame to 0 
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
		// abs 
	}

}