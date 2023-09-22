#include "Matrix3D.h"

float& Matrix3D::operator()(int i, int j)
{
	return (n[i][j]);
}

const float& Matrix3D::operator()(int i, int j) const
{
	return (n[i][j]);
}

Vector3D& Matrix3D::operator[](int j)
{
	return (*reinterpret_cast<Vector3D *>(n[j]));
}

const Vector3D& Matrix3D::operator[](int j) const
{
	return (*reinterpret_cast<const Vector3D*>(n[j]));
}