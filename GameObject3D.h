#pragma once

#include "VectorOps.h"
#include <vector>

class GameObject3D
{
private:
	static std::vector<GameObject3D*> ObjectList;
	std::string Name;
	Vector3 Pos;
	float Mass;
	float Drag;
	std::string Tag;

public:
	static void ListIt();
	static void SearchAndList(std::string Tag);
	GameObject3D(std::string name, Vector3 position, float Mass, float Drag, std::string Tag);
	GameObject3D(std::string name, Vector3 position, float Mass, float Drag);
	GameObject3D(std::string name, Vector3 position, float Mass);
	GameObject3D(std::string name, Vector3 position);
	GameObject3D(std::string name);
	GameObject3D();
	void SetPos(Vector3 pos);
	Vector3 GetPos();
	void SetMass(float mass);
	float GetMass();
	void SetDrag(float drag);
	float GetDrag();
	void SetTag(std::string Tag);
	std::string GetTag();
	void SetName(std::string Name);
	std::string GetName();

	friend std::ostream& operator << (std::ostream& out, GameObject3D& go);
	friend class Physics;
};

