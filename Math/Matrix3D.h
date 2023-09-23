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

	float Determinant(const Matrix3D& m);

	Matrix3D Inverse(const Matrix3D& m);

};

inline Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
	return (Matrix3D(A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
		A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(1, 2) * B(2, 1),
		A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(2, 2) * B(2, 2),
		A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(0, 2) * B(2, 0),
		A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
		A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(2, 2) * B(2, 2),
		A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(0, 2) * B(2, 0),
		A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(1, 2) * B(2, 1),
		A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)));
}

inline Vector3D operator *(const Matrix3D& M, const Vector3D& v)
{
	return (Vector3D(M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
		M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
		M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z));
}