#include "Collision.h"
#include "GameManager.h"
using namespace sf;
using namespace std;

Collision::Collision(RectangleShape& body) : body(body)
{
}


Collision::~Collision()
{
}




bool Collision::CheckCollision(Collision & other,Vector2f& direction, float push)
{
	Vector2f otherPosition = other.GetPositionColl();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPositionColl();
	Vector2f thisHalfSize = GetHalfSize();



	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) //if they collide with this obj so let us know
	{
		//takes what it returns being between 0 and 1 being clamping between 0 and 1
		push = min(max(push, 0.0f), 1.0f);

		if ((intersectX) > (intersectY))
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f ,-intersectY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}

	return false;
}
