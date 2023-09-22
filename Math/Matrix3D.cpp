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

inline Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
	return (Matrix3D(A(0 ,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
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