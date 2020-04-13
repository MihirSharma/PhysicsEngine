#include<iostream>
#include<cmath>
#include "Vector4.h"


		
		Vector4::Vector4()
			:x(0), y(0), z(0), w(0) {}
		Vector4::Vector4(float x, float y, float z, float w)
			: x(x), y(y), z(z), w(w) {}

		Vector4 Vector4::operator+(Vector4& other) {
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		Vector4 Vector4::operator-(Vector4& other) {
			return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}
		Vector4 Vector4::operator*(float f) {
			return Vector4(f * x, f * y, f * z, f * w);
		}
		Vector4 Vector4::operator/(float f) {
			return Vector4(x / f, y / f, z / f, w / f);
		}

		float Vector4::dot(Vector4& a, Vector4& b) {
			return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
		}

		Vector4 Vector4::cross(Vector4& a, Vector4& b, Vector4& c) {
			float rx, ry, rz, rw;
			rx = (a.y * (b.z * c.w - c.z * b.w) - a.z * (b.y * c.w - c.y * b.w) + a.w * (b.y * c.z - c.y * b.z));
			ry = -1 * (a.x * (b.z * c.w - c.z * b.w) - a.z * (b.x * c.w - c.x * b.w) + a.w * (b.x * c.z - c.x * b.z));
			rz = (a.x * (b.y * c.w - c.y * b.w) - a.y * (b.x * c.w - c.x * b.w) + a.w * (b.x * c.y - c.x * b.y));
			rw = -1 * (a.x * (b.y * c.z - c.y * b.z) - a.y * (b.x * c.z - c.x * b.z) + a.z * (b.x * c.y - c.x * b.y));
			return Vector4(rx, ry, rz, rw);

		}
		Vector4 Vector4::normalize(Vector4& a) {
			return Vector4(a.x / sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w), a.y / sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w), a.z / sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w), a.w / sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
		}

	std::ostream& operator <<(std::ostream& out, Vector4 other) {
		out << "(" << other.x << ", " << other.y << ", " << other.z << ", " << other.w << ")";
		return out;
	}

