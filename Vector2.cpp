#include<iostream>

class Vector2 {

private:
	float x, y;
public:
	friend std::ostream& operator <<(std::ostream& out, Vector2 other);
	Vector2()
		:x(0), y(0) {}
	Vector2(float x, float y)
		: x(x), y(y){}

	Vector2 operator+(Vector2& other){
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(Vector2& other){
		return Vector2(x - other.x, y - other.y);		
	}
	Vector2 operator*(float& f) {
		return Vector2(f*x, f*y);
	}
	Vector2 operator/(float& f) {
		return Vector2(f / x, f / y);
	}
	
	float dot(Vector2& a, Vector2& b) {
		return (a.x * b.x + a.y * b.y);
	}

	float cross(Vector2& a, Vector2& b) {
		return (a.x * b.y - a.y * b.x);
	}

	

};
std::ostream& operator <<(std::ostream& out, Vector2 other) {
	out << "(" << other.x << "," << other.y << ")";
	return out;
}

int main() {
	return 0;
}
