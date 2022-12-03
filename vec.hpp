#ifndef VEC_HPP
#define VEC_HPP

#include <math.h>

class Vec3 {
	public:
		Vec3() = default;
		Vec3(double, double, double);
		double x=0, y=0, z=0, w=1;
		double length();
		void normalize();
		void operator+=(Vec3);
		void operator-=(Vec3);
		void operator*=(double);
		void operator/=(double);
};

Vec3 operator+(Vec3, Vec3);
Vec3 operator-(Vec3, Vec3);
Vec3 operator*(Vec3, double);
Vec3 operator/(Vec3, double);

double dot();
double cross();


#endif
