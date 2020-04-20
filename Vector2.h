#pragma once

#include<iostream>

	class Vector2 {
	private:
		long float x, y;
	public:
		Vector2();
		Vector2(long float a, long float b);
		friend std::ostream& operator<<(std::ostream& out, Vector2 other);
		float magnitude();
		void operator=(Vector2 other);
		Vector2 operator+(Vector2 other);
		Vector2 operator-(Vector2 other);
		Vector2 operator*(float f);
		Vector2 operator/(float f);
		static float dot(Vector2& a, Vector2& b);
		static float cross(Vector2& a, Vector2& b);
		static Vector2 normalize(Vector2& a);
	};
