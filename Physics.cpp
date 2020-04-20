#include "Physics.h"

/*void Physics::AddVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v/60;
}*/

void Physics::SetVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v /300000;
}

void Physics::AddForce2D(GameObject2D& go, Vector2& f) {
	Vector2 v(1,1);
	if (v.magnitude() > 0) {
		v = (f / go.Mass);
		f = f - Vector2(go.Drag, go.Drag);
		//std::cout << std::endl << f << "\t"<<v;
		Physics::SetVelocity2D(go, v);
	}
}