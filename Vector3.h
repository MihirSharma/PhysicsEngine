#pragma once

class Vector3 {
private:
	float x, y,z;
public:
	Vector3();
	Vector3(float a, float b, float c);
	friend std::ostream& operator<<(std::ostream& out, Vector3 other);
	Vector3 operator+(Vector3& other);
	Vector3 operator-(Vector3& other);
	Vector3 operator*(float f);
	Vector3 operator/(float f);
	static float dot(Vector3& a, Vector3& b);
	static Vector3 cross(Vector3& a, Vector3& b);
	static Vector3 normalize(Vector3& a);
};