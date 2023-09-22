#include "Vector3D.h"

Vector3D::Vector3D(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

float& Vector3D::operator [](int i)
{
	return ((&x)[i]);
}

const float& Vector3D::operator [](int i) const
{
	return ((&x)[i]);
}

Vector3D& Vector3D::operator +=(const Vector3D v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;

	return (*this);
}

Vector3D& Vector3D::operator -=(Vector3D v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;

	return *this;
}

inline Vector3D operator +(const Vector3D& v1, const Vector3D& v2) 
{
	return (Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3D operator -(const Vector3D& v) 
{
	return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D operator *(const Vector3D& v, float s)
{
	return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s)
{
	float s = 1.0f / s;
	return (Vector3D(v.x / s, v.y / s, v.z / s));
}

inline float Vector3D::Magnitude(const Vector3D& v)
{
	return (std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Vector3D::Normalize(const Vector3D& v)
{
	return (v / Magnitude(v));
}