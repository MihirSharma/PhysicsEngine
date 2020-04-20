#include "GameObject2D.h"

std::vector<GameObject2D*> GameObject2D::ObjectList;

GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass, float Drag, std::string Tag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag) , Tag(Tag){
	GameObject2D::ObjectList.push_back(this);
}

GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass, float Drag)
	: Name(name), Pos(position), Mass(Mass), Drag(Drag), Tag("Unassigned") {
	GameObject2D::ObjectList.push_back(this);
}


GameObject2D::GameObject2D(std::string name, Vector2 position, float Mass)
	: Name(name), Pos(position), Mass(Mass), Drag(0.0), Tag("Unassigned") {
	GameObject2D::ObjectList.push_back(this);
}


GameObject2D::GameObject2D(std::string name, Vector2 position)
	: Name(name), Pos(position), Mass(1.0), Drag(0.0), Tag("Unassigned") {
	GameObject2D::ObjectList.push_back(this);
}


GameObject2D::GameObject2D(std::string name)
	: Name(name), Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned") {
	GameObject2D::ObjectList.push_back(this);
}

GameObject2D::GameObject2D()
	: Name("Unnamed GameObject"), Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned") {
	GameObject2D::ObjectList.push_back(this);
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