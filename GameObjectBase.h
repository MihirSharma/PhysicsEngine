#pragma once

#include<vector>
#include<string>

class GameObjectBase
{
protected:
	float radius;
	std::vector<std::string> collisionException;
public:
	GameObjectBase(float radius) :
		radius(radius) {};
	GameObjectBase() :
		radius(1.0) {};

	float GetRad();
	void SetRad(float rad);
	void AddToCollisionException(std::string x);
};


