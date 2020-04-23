#include "GameObject3D.h"
#include<cmath>

std::vector<GameObject3D*> GameObject3D::ObjectList;
int GameObject3D::ctr = 1;

GameObject3D::GameObject3D(std::string name, Vector3 position, float Mass, float Drag, std::string Tag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag), Tag(Tag), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}

GameObject3D::GameObject3D(std::string name, Vector3 position, float Mass, float Drag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag), Tag("Unassigned"), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}


GameObject3D::GameObject3D(std::string name, Vector3 position, float Mass)
	: Name(name), Pos(position), Mass(Mass), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}


GameObject3D::GameObject3D(std::string name, Vector3 position)
	: Name(name), Pos(position), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}


GameObject3D::GameObject3D(std::string name)
	: Name(name), Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}

GameObject3D::GameObject3D()
	: Name("Unnamed GameObject"), Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned"), uid(ctr) {
	GameObject3D::ObjectList.push_back(this);
	ctr++;
}

void GameObject3D::SetPos(Vector3 pos) {
	Pos = pos;
}
Vector3 GameObject3D::GetPos() {
	return Pos;
}

void GameObject3D::SetTag(std::string Tag) {
	GameObject3D::Tag = Tag;
}

void GameObject3D::SetMass(float mass) {
	Mass = mass;
}
float GameObject3D::GetMass() {
	return Mass;
}

void GameObject3D::SetDrag(float drag) {
	Drag = drag;
}
float GameObject3D::GetDrag() {
	return Drag;
}

std::string GameObject3D::GetTag() {
	return Tag;
}

void GameObject3D::SetName(std::string Name) {
	GameObject3D::Name = Name;
}

std::string GameObject3D::GetName() {
	return Name;
}

std::ostream& operator <<(std::ostream& out, GameObject3D& go) {
	out << "Name : " << go.Name << std::endl << "Position : " << go.Pos << std::endl << "Mass : " << go.Mass << std::endl << "Drag :" << go.Drag << std::endl << "Tag : " << go.Tag << std::endl;
	return out;
}

void GameObject3D::operator=(GameObject3D x) {
	radius = x.radius;
	Name = x.Name;
	Pos = x.Pos;
	Mass = x.Mass;
	Drag = x.Drag;
	Tag = x.Tag;
}

void GameObject3D::ListIt() {
	for (auto it : GameObject3D::ObjectList) {
		std::cout << *it << std::endl << std::endl;
	}
}

void GameObject3D::SearchAndList(std::string tag) {
	for (auto it : GameObject3D::ObjectList) {
		if (it->Tag == tag || it->Name == tag) {
			if (it->Name == tag)
				std::cout << "Found Object with Matching Name" << std::endl << std::endl << *it << std::endl << std::endl;
			else if (it->Tag == tag)
				std::cout << "Found Object with Matching Tag" << std::endl << std::endl << *it << std::endl << std::endl;
		}
	}
}

GameObject3D* GameObject3D::CollisionDetection3D() {
	bool colliding = false;
	for (auto it : GameObject3D::ObjectList) {
		bool exception = false;
		for (auto it2 : collisionException) {
			if (it2 == it->Tag) {
				exception = true;
			}
		}
		if (!((abs(it->Pos.x + it->radius) - abs(Pos.x - radius) <= 0 || abs(Pos.x + radius) - abs(it->Pos.x - it->radius) <= 0)) && !((abs(it->Pos.y + it->radius) - abs(Pos.y - radius) <= 0 || abs(Pos.y + radius) - abs(it->Pos.y - it->radius) <= 0)) && !((abs(it->Pos.z + it->radius) - abs(Pos.z - radius) <= 0 || abs(Pos.z + radius) - abs(it->Pos.z - it->radius) <= 0)) && (uid != it->uid && !exception)) {
			colliding = true;
			return it;
		}
	}
	if (!colliding)
		return nullptr;
}
