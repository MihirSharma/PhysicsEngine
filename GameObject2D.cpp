#include "GameObject2D.h"
#include<cmath>

std::vector<GameObject2D*> GameObject2D::ObjectList;
int GameObject2D::ctr = 1;

GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass, float Drag, std::string Tag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag) , Tag(Tag), uid(ctr){
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}

GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass, float Drag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag), Tag("Unassigned"), uid(ctr) {
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}


GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass)
	: Name(name), Pos(position), Mass(Mass), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}


GameObject2D::GameObject2D(std::string name, Vector2 position)
	: Name(name), Pos(position), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}


GameObject2D::GameObject2D(std::string name)
	: Name(name), Pos(Vector2(0,0)), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}

GameObject2D::GameObject2D()
	: Name("Unnamed GameObject"), Pos(Vector2(0,0)), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject2D::ObjectList.push_back(this);
	ctr++;
}

void GameObject2D::SetPos(Vector2 pos) {
	Pos = pos;
}
Vector2 GameObject2D::GetPos() {
	return Pos;
}

void GameObject2D::SetTag(std::string Tag) {
	GameObject2D::Tag = Tag;
}

void GameObject2D::SetMass(float mass) {
	Mass = mass;
}
float GameObject2D::GetMass() {
	return Mass;
}

void GameObject2D::SetDrag(float drag) {
	Drag = drag;
}
float GameObject2D::GetDrag() {
	return Drag;
}

std::string GameObject2D::GetTag() {
	return Tag;
}

void GameObject2D::SetName(std::string Name) {
	GameObject2D::Name = Name;
}

std::string GameObject2D::GetName() {
	return Name;
}

std::ostream& operator <<(std::ostream& out, GameObject2D& go) {
	out << "Name : " << go.Name << std::endl << "Position : " << go.Pos << std::endl << "Mass : " << go.Mass << std::endl << "Drag :" << go.Drag << std::endl << "Tag : " << go.Tag << std::endl;
	return out;
}

void GameObject2D::operator=(GameObject2D x) {
	radius = x.radius;
	Name = x.Name;
	Pos = x.Pos;
	Mass = x.Mass;
	Drag = x.Drag;
	Tag = x.Tag;
}

void GameObject2D::ListIt() {
	for (auto it : GameObject2D::ObjectList) {
		std::cout << *it << std::endl << std::endl;
	}
}

void GameObject2D::SearchAndList(std::string tag) {
	for (auto it : GameObject2D::ObjectList) {
		if (it->Tag == tag || it->Name == tag) {
			if (it->Name == tag)
				std::cout << "Found Object with Matching Name" << std::endl << std::endl << *it << std::endl << std::endl;
			else if (it->Tag == tag)
				std::cout << "Found Object with Matching Tag" << std::endl << std::endl << *it << std::endl << std::endl;
		}
	}
}

GameObject2D* GameObject2D::CollisionDetection2D() {
	bool colliding = false;
	for (auto it : GameObject2D::ObjectList) {
		bool exception = false;
		for (auto it2 : it->collisionException) {
			if(it2 == it->Tag)
				exception = true;
		}
		if (!((abs(it->Pos.x + it->radius) - abs(Pos.x - radius) <= 0 || abs(Pos.x + radius) - abs(it->Pos.x - it->radius) <= 0)) && !((abs(it->Pos.y + it->radius) - abs(Pos.y - radius) <= 0 || abs(Pos.y + radius) - abs(it->Pos.y - it->radius) <= 0)) && (uid != it->uid && !exception)) {
			colliding = true;
			return it;
		}
	}
	if(!colliding)
		return nullptr;
}
