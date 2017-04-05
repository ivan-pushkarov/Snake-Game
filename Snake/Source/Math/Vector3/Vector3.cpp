#include "Vector3.h"

const double Vector3::EPS = 0.000001;

Vector3::Vector3():x(0.0f), y(0.0f), z(0.0f)
{

}

Vector3::Vector3(const Vector3& other):x(other.x), y(other.y), z(other.z)
{

}

Vector3::Vector3(double _x, double _y, double _z):x(_x), y(_y), z(_z)
{

}

double Vector3::getNorm() const
{
	return sqrt(x*x + y*y + z*z);
}

const Vector3 Vector3::getReverse() const
{
	Vector3 temp = *this;
	temp.x = -x;
	temp.y = -y;
	temp.z = -z;
	return temp;

}

double Vector3::getX() const
{
	return x;
}

void Vector3::setX(double _x)
{
	x = _x;
}

double Vector3::getY() const
{
	return y;
}

void Vector3::setY(double _y)
{
	y = _y;
}

double Vector3::getZ() const
{
	return z;
}

void Vector3::setZ(double _z)
{
	z = _z;
}

void Vector3::setXYZ(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3 Vector3::operator*(double a)
{
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

const Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	temp.z -= other.z;
	return temp;
}

const Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	temp.z += other.z;
	return temp;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator*=(double a)
{
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
	if (abs(x - other.x) < EPS && 
		abs(y - other.y) < EPS && 
		abs(z - other.z) < EPS)
		return true;
	return false;
}

bool Vector3::operator!=(const Vector3& other) const
{
	return (!(*this == other));
}

double Vector3::dot(const Vector3& other) const
{
	return x*other.x + y*other.y + z*other.z;
}

Vector3 Vector3::cross(const Vector3& other)
{
	Vector3 temp;
	temp.x = y*other.z - z*other.y;
	temp.y = z*other.x - x*other.z;
	temp.z = x*other.y - y*other.x;
	return temp;
}

void Vector3::normalize()
{
	double norm = getNorm();

	if (!norm) return;

	x /= norm;
	y /= norm;
	z /= norm;
}