#pragma once

#include <cmath>

class Vector3D
{
public:
	float x, y, z;
	
	Vector3D() = default;

	Vector3D(float a, float b, float c);

	float& operator [](int i);

	const float& operator [](int i) const;

	Vector3D& operator +=(const Vector3D v);

	Vector3D& operator -=(const Vector3D v);

	friend Vector3D operator +(const Vector3D& v1, const Vector3D& v2);

	friend Vector3D operator -(const Vector3D& v);

	friend Vector3D operator *(const Vector3D& v, float s);

	friend Vector3D operator /(const Vector3D& v, float s);

	float Magnitude(const Vector3D& v);

	Vector3D Normalize(const Vector3D& v);
};