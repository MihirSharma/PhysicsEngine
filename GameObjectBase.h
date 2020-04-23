#pragma once
class GameObjectBase
{
private:
public:
	float radius;
	GameObjectBase(float radius) :
		radius(radius) {};
	GameObjectBase() :
		radius(1.0) {};

	float GetRad();
	void SetRad(float rad);
};

