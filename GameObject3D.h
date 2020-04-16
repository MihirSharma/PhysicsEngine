#pragma once

#include "VectorOps.h"

class GameObject3D
{
private:
	Vector3 Pos;
	float Mass;
	float Drag;
	std::string Tag;

public:
	GameObject3D(Vector3 position, float Mass, float Drag, std::string Tag);
	GameObject3D(Vector3 position, float Mass, float Drag);
	GameObject3D(Vector3 position, float Mass);
	GameObject3D(Vector3 position);
	GameObject3D();
	void SetPos(Vector3 pos);
	Vector3 GetPos();
	void SetMass(float mass);
	float GetMass();
	void SetDrag(float drag);
	float GetDrag();
	void SetTag(std::string Tag);
	std::string GetTag();

	friend std::ostream& operator << (std::ostream& out, GameObject3D& go);
	friend class Physics;
};

