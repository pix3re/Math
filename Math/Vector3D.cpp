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