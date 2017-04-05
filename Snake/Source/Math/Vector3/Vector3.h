#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3
{
public:

	Vector3();
	Vector3(const Vector3&);
	Vector3(double, double, double);

	double getNorm() const;

	double getX() const;

	void setX(double);

	double getY() const;

	void setY(double);

	double getZ() const;

	void setZ(double);

	void setXYZ(double, double, double);

	//Scalar multiplication
	Vector3 operator*(double);

	//Vector subtraction
	const Vector3 operator-(const Vector3&);

	//Vector addition
	const Vector3 operator+(const Vector3&);

	//Assignment operators
	Vector3& operator=(const Vector3&);

	Vector3& operator+=(const Vector3&);

	Vector3& operator-=(const Vector3&);

	Vector3& operator*=(double);

	bool operator==(const Vector3&) const;

	bool operator!=(const Vector3&) const;

	double dot(const Vector3&) const;	// TBD

	Vector3 cross(const Vector3&);	// TBD

	const Vector3 getReverse() const;

	void normalize();

protected:

private:

	double x;
	double y;
	double z;

	const static double EPS;

};

#endif // !VECTOR3_H