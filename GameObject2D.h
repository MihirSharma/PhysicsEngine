#pragma once

#include "VectorOps.h"


class GameObject2D
{
private:
	Vector2 Pos;
	float Mass;
	float Drag;
	std::string Tag;

public:
	GameObject2D(Vector2 position, float Mass, float Drag, std::string Tag);
	GameObject2D(Vector2 position, float Mass, float Drag);
	GameObject2D(Vector2 position, float Mass);
	GameObject2D(Vector2 position);
	GameObject2D();
	void SetPos(Vector2 pos);
	Vector2 GetPos();
	void SetMass(float mass);
	float GetMass();
	void SetDrag(float drag);
	float GetDrag();
	void SetTag(std::string Tag);
	std::string GetTag();

	friend std::ostream& operator << (std::ostream& out, GameObject2D& go);
	friend class Physics;

};

