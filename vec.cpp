#include "vec.hpp"

Vec3::Vec3(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

double Vec3::length() {
	return sqrt(x*x + y*y + z*z);
}

void Vec3::normalize() {
	double len = this->length();
	x/=len;
	y/=len;
	z/=len;
}

void Vec3::raw(int i, double v) {
	if(i == 0) { x = v; }
	if(i == 1) { y = v; }
	if(i == 2) { z = v; }
}

void Vec3::operator+=(Vec3 v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vec3::operator-=(Vec3 v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vec3::operator*=(double v) {
	x *= v;
	y *= v;
	z *= v;
}

void Vec3::operator/=(double v) {
	x /= v;
	y /= v;
	z /= v;
}

Vec3 operator+(Vec3 a, Vec3 b) {
	a += b;
	return a;
}

Vec3 operator-(Vec3 a, Vec3 b) {
	a -= b;
	return a;
}

Vec3 operator*(Vec3 a, double v) {
	a *= v;
	return a;
}

Vec3 operator/(Vec3 a, double v) {
	a /= v;
	return a;
}

double dot(Vec3 a, Vec3 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vec3 cross(Vec3 a, Vec3 b) {
	// TODO
}


