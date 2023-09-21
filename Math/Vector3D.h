#pragma once
class Vector3D
{
	float x, y, z;

public:
	Vector3D() = default;

	Vector3D(float a, float b, float c);

	float& operator [](int i);

	const float& operator [](int i) const;

	Vector3D& operator +=(const Vector3D v);

	Vector3D& operator -=(const Vector3D v);
};