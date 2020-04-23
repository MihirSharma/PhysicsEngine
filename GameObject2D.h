#pragma once

#include "VectorOps.h"
#include <vector>
#include "GameObjectBase.h"

class GameObject2D : public GameObjectBase
{
private:
	static std::vector<GameObject2D*> ObjectList;
	std::string Name;
	Vector2 Pos;
	float Mass;
	float Drag;
	std::string Tag;
	int uid;
	static int ctr;
	
public:
	static void ListIt();
	static void SearchAndList(std::string Tag);
	GameObject2D(std::string name, Vector2 position, float Mass, float Drag, std::string Tag);
	GameObject2D(std::string name, Vector2 position, float Mass, float Drag);
	GameObject2D(std::string name, Vector2 position, float Mass);
	GameObject2D(std::string name, Vector2 position);
	GameObject2D(std::string name);
	GameObject2D();
	void SetPos(Vector2 pos);
	Vector2 GetPos();
	void SetMass(float mass);
	float GetMass();
	void SetDrag(float drag);
	float GetDrag();
	void SetTag(std::string Tag);
	std::string GetTag();
	void SetName(std::string Name);
	std::string GetName();
	GameObject2D* CollisionDetection2D();
	void operator= (GameObject2D x);

	friend std::ostream& operator << (std::ostream& out, GameObject2D& go);
	friend class Physics;
};

