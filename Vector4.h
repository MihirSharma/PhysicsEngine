#pragma once


class Vector4 {
private:
	float x, y, z, w;
public:
	Vector4();
	Vector4(float a, float b, float c, float d);
	friend std::ostream& operator<<(std::ostream& out, Vector4 other);
	Vector4 operator+(Vector4& other);
	Vector4 operator-(Vector4& other);
	Vector4 operator*(float f);
	Vector4 operator/(float f);
	static float dot(Vector4& a, Vector4& b);
	static Vector4 cross(Vector4& a, Vector4& b, Vector4& c);
	static Vector4 normalize(Vector4& a);
};