#include "Physics.h"

/*void Physics::AddVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v/60;
}*/

void Physics::SetVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v /300000;
}

	Vector2 v2(1,1);
void Physics::AddForce2D(GameObject2D& go, Vector2& f) {
	if (v2.magnitude() > 0) {
		v2 = (f / go.Mass);
		f = f - Vector2(go.Drag, go.Drag);
		//std::cout << std::endl << f << "\t"<<v;
		Physics::SetVelocity2D(go, v2);
	}
}

void Physics::SetVelocity3D(GameObject3D& go, Vector3 v) {
	go.Pos = go.Pos + v / 300000;
}

Vector3 v3(1, 1, 1);
void Physics::AddForce3D(GameObject3D& go, Vector3& f) {
	if (v3.magnitude() > 0) {
		v3 = (f / go.Mass);
		f = f - Vector3(go.Drag, go.Drag, go.Drag);
		//std::cout << std::endl << f << "\t"<<v;
		Physics::SetVelocity3D(go, v3);
	}
}
