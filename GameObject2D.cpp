#include "GameObject2D.h"

GameObject2D::GameObject2D(Vector2 position, float Mass, float Drag, std::string Tag)
	:Pos(position), Mass(Mass), Drag(Drag) , Tag(Tag){}

GameObject2D::GameObject2D(Vector2 position, float Mass, float Drag)
	:Pos(position), Mass(Mass), Drag(Drag), Tag("Unassigned") {}


GameObject2D::GameObject2D(Vector2 position, float Mass)
	: Pos(position), Mass(Mass), Drag(0.0), Tag("Unassigned") {}


GameObject2D::GameObject2D(Vector2 position)
	: Pos(position), Mass(1.0), Drag(0.0), Tag("Unassigned") {}


GameObject2D::GameObject2D()
	: Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned") {}

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

std::ostream& operator <<(std::ostream& out, GameObject2D& go) {
	out << "Position : " << go.Pos << std::endl << "Mass : " << go.Mass << std::endl << "Drag :" << go.Drag << std::endl << "Tag : " << go.Tag << std::endl;
	return out;
}