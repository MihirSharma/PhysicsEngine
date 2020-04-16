#include "Physics.h"

/*void Physics::AddVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v/60;
}*/

void Physics::SetVelocity2D(GameObject2D& go, Vector2 v) {
	go.Pos = go.Pos + v /300000;
}