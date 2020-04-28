#pragma once
#include "GameManager.h"

using namespace sf;
class Collision {
public:
	Collision(RectangleShape& body);
	~Collision();
	bool CheckCollision(Collision& other, Vector2f& direction, float push); //wall is 0, a light object would be 1

	void Move(float dx, float dy) {
		body.move(dx, dy);
	}

	Vector2f GetPositionColl() {
		return body.getPosition();
	} //get for pos with colliding into stuff!
	Vector2f GetHalfSize() {
		return body.getSize() / 2.0f;
	}
private:
	RectangleShape & body;
};