#pragma once

#include "GameObject.h"

class Physics
{

public:
	//void AddVelocity2D(GameObject2D& go, Vector2 v);
	static void SetVelocity2D(GameObject2D& go, Vector2 v);

	static void AddForce2D(GameObject2D& go, Vector2& f);

};

