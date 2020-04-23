#pragma once

#include "GameObject.h"

class Physics
{

public:
	//void AddVelocity2D(GameObject2D& go, Vector2 v);
	static void SetVelocity2D(GameObject2D& go, Vector2 v);

	static void AddForce2D(GameObject2D& go, Vector2& f);

	static void SetVelocity3D(GameObject3D& go, Vector3 v);

	static void AddForce3D(GameObject3D& go, Vector3& f);

	



};

