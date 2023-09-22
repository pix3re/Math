#pragma once
#include "Vector3D.h"

class Matrix3D
{
	float n[3][3];

public:

	Matrix3D() = default;

	Matrix3D(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22)
	{
		n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
		n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
		n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
	}

	Matrix3D(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3)
	{
		n[0][0] = v1.x; n[0][1] = v1.y; n[0][2] = v1.z;
		n[1][0] = v2.x; n[1][1] = v2.y; n[1][2] = v2.z;
		n[2][0] = v3.x; n[2][1] = v3.y; n[2][2] = v3.z;
	}

	float& operator()(int i, int j);

	const float& operator()(int i, int j) const;

	Vector3D& operator[](int j);

	const Vector3D& operator[](int j) const;

	friend Matrix3D operator *(const Matrix3D& a, const Matrix3D& b);

	friend Vector3D operator *(const Matrix3D& M, const Vector3D& v);
};

