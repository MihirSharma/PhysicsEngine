#pragma once

#include "VectorOps.h"
#include <vector>
#include "GameObjectBase.h"

///<summary>
///Class for creating 2-D Game Objects
///<para>.................................................................................................</para>
///<para> Member Variables: </para>
///<para>	string Name, Vector2 Position, float Mass, float Drag, string Tag, float Radius</para>
///<para>.................................................................................................</para>
///<para>Member Functions: </para>
///<para>		void SetName(), void SetPos(), void SetMass(), void SetDrag(), void SetTag(), string GetName(), Vector2 GetPos(), float GetMass(), float GetDrag(), string GetTag(), GameObject2D* CollisionDetection2D()</para>
///</summary>
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

