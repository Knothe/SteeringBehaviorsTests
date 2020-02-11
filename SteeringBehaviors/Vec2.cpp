#include "Vec2.h"
#include <math.h> 

/*
Starts the vector with 0 values
*/
Vec2::Vec2() {
	x = 0;
	y = 0;
}
/*
Starts the vector with set values
@param x: value in x
@param y: value in y
*/
Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}
/*
Compares 2 vectors
@param other: vector to compare
@return bool if the comparation is correct
*/
bool Vec2::operator<(const Vec2 other) {
	if (x < other.x && y < other.y)
		return true;
	return false;
}
/*
Compares 2 vectors
@param other: vector to compare
@return bool if the comparation is correct
*/
bool Vec2::operator>(const Vec2 other) {
	if (x > other.x && y > other.y)
		return true;
	return false;
}
/*
Adds 2 vectors
@param other: vector to add
@return resulting vector
*/
Vec2 Vec2::operator+(const Vec2 other) {
	Vec2 v;
	v.x = x + other.x;
	v.y = y + other.y;
	return v;
}
/*
Subtracts 2 vectors
@param other: vector to substract
@return resulting vector
*/
Vec2 Vec2::operator-(const Vec2 other) {
	Vec2 v;
	v.x = x - other.x;
	v.y = y - other.y;
	return v;
}
/*
Multiplies a vector with an int
@param n: int to multiply
@return resulting vector
*/
Vec2 Vec2::operator*(float n) {
	Vec2 v;
	v.x = x * n;
	v.y = y * n;
	return v;
}

float Vec2::operator*(Vec2 n) {
	float v;
	v = (x * n.x) + (y * n.y);
	return v;
}


/*
Equals this vector to other
@param other: vector to equal
*/
void Vec2::operator=(const Vec2 other) {
	x = other.x;
	y = other.y;
}
/*
Divides vector parameters with a number
@param n: divisor
@return resulting vector
*/
Vec2 Vec2::operator/(float n) {
	Vec2 v;
	v.x = x / n;
	v.y = y / n;
	return v;
}
/*
Compares 2 vectors
*/
bool Vec2::operator==(const Vec2 other) {
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}

/*
Unit vector in the direction of the vector
*/
Vec2 Vec2::normalize() {
	Vec2 v(x, y);
	float s = v.size();
	if (s == 0)
		return v;
	v = v / s;
	if (v.x == 1 || v.x == -1)
		v.y = 0;
	if (v.y == 1 || v.y == -1)
		v.x = 0;

	return v / v.size();
}
/*
Calculates size of the vector
*/
float Vec2::size() {
	float v;
	v = x * x;
	v += y * y;
	v = sqrt(v);
	return v;
}
/*
Set the size of this vector
*/
void Vec2::SetSize(float newSize) {
	Vec2 v = normalize();
	v = v * newSize;
	x = v.x;
	y = v.y;
}
/*
Set the size of this vector
*/
void Vec2::SetSize(float newSize, float currentSize) {
	x = (x / currentSize) * newSize;
	y = (y / currentSize) * newSize;
}
/*
Limits the vector size
*/
void Vec2::Limit(float maxSize) {
	float s = size();
	if (s > maxSize)
		SetSize(maxSize);
}
/*
Calculates angle in degrees of this vector
*/
float Vec2::GetAngle() {
	if (x == 0 && y == 0)
		return 0;
	else if (x < 0)
		return -GetAngle(Vec2(0, -1));
	else
		return GetAngle(Vec2(0, -1));
}

float Vec2::GetRadianAngle() {
	if (x == 0 && y == 0)
		return 0;
	else if (x < 0)
		return -GetRadianAngle(Vec2(0, -1));
	else
		return GetRadianAngle(Vec2(0, -1));
}
/*
Calculates angle in degrees of this vector with another
*/
float Vec2::GetAngle(Vec2 other) {
	float size1, size2;
	size1 = size();
	size2 = other.size();
	float result = (x * other.x) + (y * other.y);
	result = result / (size1 * size2);
	return radianToDegree(acos(result));
}

float Vec2::GetRadianAngle(Vec2 other) {
	float size1, size2;
	size1 = size();
	size2 = other.size();
	float result = (x * other.x) + (y * other.y);
	result = result / (size1 * size2);
	return acos(result);
}

/*
Convert radian to degree
*/
float Vec2::radianToDegree(float radian) {
	return radian * 180 / 3.1415f;
}

Vec2 Vec2::Rotate(float angle) {
	float xTemp, yTemp;
	xTemp = (x * cos(angle)) - (y * sin(angle));
	yTemp = (x * sin(angle)) + (y * cos(angle));
	return Vec2(xTemp, yTemp);
}

Vec2::~Vec2() {

}