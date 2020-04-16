#include<iostream>
#include<cmath>
#include "Vector2.h"


		
		Vector2::Vector2()
			:x(0), y(0) {}
		Vector2::Vector2(long float x, long float y)
			: x(x), y(y) {}

		Vector2 Vector2::operator+(Vector2 other) {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 Vector2::operator-(Vector2 other) {
			return Vector2(x - other.x, y - other.y);
		}
		Vector2 Vector2::operator*(float f) {
			return Vector2(f * x, f * y);
		}
		Vector2 Vector2::operator/(float f) {
			return Vector2(x / f, y / f);
		}

		float Vector2::dot(Vector2& a, Vector2& b) {
			return (a.x * b.x + a.y * b.y);
		}

		float Vector2::cross(Vector2& a, Vector2& b) {
			return (a.x * b.y - a.y * b.x);
		}
		Vector2 Vector2::normalize(Vector2& a) {
			return Vector2(a.x / sqrt(a.x * a.x + a.y * a.y), a.y / sqrt(a.x * a.x + a.y * a.y));
		}

	std::ostream& operator <<(std::ostream& out, Vector2 other) {
		out << "(" << (int)other.x << "," << (int)other.y << ")";
		return out;
	}

