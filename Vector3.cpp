#include<iostream>
#include<cmath>
#include "Vector3.h"


		
		Vector3::Vector3()
			:x(0), y(0), z(0) {}
		Vector3::Vector3(float x, float y, float z)
			: x(x), y(y), z(z) {}

		Vector3 Vector3::operator+(Vector3& other) {
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3 Vector3::operator-(Vector3& other) {
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		Vector3 Vector3::operator*(float f) {
			return Vector3(f * x, f * y, f * z);
		}
		Vector3 Vector3::operator/(float f) {
			return Vector3(x / f, y / f, z / f);
		}

		float Vector3::dot(Vector3& a, Vector3& b) {
			return (a.x * b.x + a.y * b.y + a.z * b.z);
		}

		Vector3 Vector3::cross(Vector3& a, Vector3& b) {
			return Vector3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));

		}
		Vector3 Vector3::normalize(Vector3& a) {
			return Vector3(a.x / sqrt(a.x * a.x + a.y * a.y + a.z * a.z), a.y / sqrt(a.x * a.x + a.y * a.y + a.z * a.z), a.z / sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
		}



	std::ostream& operator <<(std::ostream& out, Vector3 other) {
		out << "(" << other.x << ", " << other.y << ", " << other.z << ")";
		return out;
	}
