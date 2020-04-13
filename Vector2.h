#pragma once


	class Vector2 {
	private:
		float x, y;
	public:
		Vector2();
		Vector2(float a, float b);
		friend std::ostream& operator<<(std::ostream& out, Vector2 other);
		Vector2 operator+(Vector2& other);
		Vector2 operator-(Vector2& other);
		Vector2 operator*(float f);
		Vector2 operator/(float f);
		static float dot(Vector2& a, Vector2& b);
		static float cross(Vector2& a, Vector2& b);
		static Vector2 normalize(Vector2& a);
	};
