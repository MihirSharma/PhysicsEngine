#include<iostream>
#include "VectorOps.h"

int main() {
	Vector2 a(1,0), b(1,8),c ;
	c = a * static_cast<float>(10);
	

	Vector3 e(1.0, 20.5, 5), d(2.8, 5, 6);
	Vector3 f = Vector3::normalize(d);

	Vector4 x(1, 2, 3, 4), y(5, 2, 7, -2), z(-1,-6,4,7);
	Vector4 r = Vector4::cross(x, y, z); 
	std::cout << Vector2::normalize(b) * (float)10 << std::endl << f << std::endl << r;
}