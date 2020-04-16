#include "GameObject3D.h"

GameObject3D::GameObject3D(Vector3 position, float Mass, float Drag, std::string Tag)
	:Pos(position), Mass(Mass), Drag(Drag), Tag(Tag) {}

GameObject3D::GameObject3D(Vector3 position, float Mass, float Drag)
	: Pos(position), Mass(Mass), Drag(Drag), Tag("Unassigned") {}


GameObject3D::GameObject3D(Vector3 position, float Mass)
	: Pos(position), Mass(Mass), Drag(0.0), Tag("Unassigned") {}


GameObject3D::GameObject3D(Vector3 position)
	: Pos(position), Mass(1.0), Drag(0.0), Tag("Unassigned") {}


GameObject3D::GameObject3D()
	: Pos(), Mass(1.0), Drag(0.0), Tag("Unassigned") {}

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

std::ostream& operator <<(std::ostream& out, GameObject3D& go) {
	out << "Position : " << go.Pos << std::endl << "Mass : " << go.Mass << std::endl << "Drag :" << go.Drag << std::endl << "Tag : " << go.Tag << std::endl;
	return out;
}