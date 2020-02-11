#pragma once
class Vec2
{
public:
	float x;
	float y;
	Vec2();
	Vec2(float x, float y);
	bool operator<(const Vec2 other);
	bool operator>(const Vec2 other);
	Vec2 operator+(const Vec2 other);
	Vec2 operator*(float n);
	float operator*(Vec2 n);
	void operator=(const Vec2 other);
	Vec2 operator-(const Vec2 other);
	Vec2 operator/(float n);
	bool operator==(const Vec2 other);
	Vec2 normalize();
	float size();
	void SetSize(float newSize);
	void SetSize(float newSize, float currentSize);
	void Limit(float maxSize);
	float GetAngle();
	float GetRadianAngle();
	float GetAngle(Vec2 other);
	float GetRadianAngle(Vec2 other);
	Vec2 Rotate(float angle);
	~Vec2();
private:
	float radianToDegree(float radian);
};

