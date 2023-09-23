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

float Matrix3D::Determinant(const Matrix3D& m)
{
	return (m(0,0) * (m(1,1) * m(2,2) - m(1,2) * m (2,1)) 
		+ m(0,1) * (m(1,2) * m(2,0) - m(1,0) * m(2,2))
		+ m(0,2) * (m(1,0) * m(2,1) - m(1,1) * m(2,0)));
}

Matrix3D Matrix3D::Inverse(const Matrix3D& m)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];

	Vector3D r0 = Cross(b, c);
	Vector3D r1 = Cross(c, a);
	Vector3D r2 = Cross(a, b);

	float invDet = 1.0f / Dot(r2, c);

	return (Matrix3D(r0.x * invDet, r0.y * invDet, r0.z * invDet,
					r1.x * invDet, r1.y * invDet, r1.z * invDet,
					r2.x * invDet, r2.y * invDet, r2.z * invDet));
}

/*
//Matrix4D inverse -- todo: implement Matrix4D and Vector4D structures

Matrix4D Inverse(const Matrix4D& m)
{
	const Vector3D& a = reinterp_cast<const Vector3D&>(m[0]);
	const Vector3D& b = reinterp_cast<const Vector3D&>(m[1]);
	const Vector3D& c = reinterp_cast<const Vector3D&>(m[2]);
	const Vector3D& d = reinterp_cast<const Vector3D&>(m[3]);

	const float& x = m(3,0);
	const float& y = m(3,1);
	const float& z = m(3,2);
	const float& w = m(3,3);

	Vector3D s = Cross(a, b);
	Vector3D t = Cross(c, d);
	Vector3D u = a * y - b * x
	Vector3D v = c * w - d * z;

	float invDet = 1.0f / (Dot(s, v) + Dot(t, u));
	
	s *= invDet;
	t *= invDet;
	u *= invDet;
	v *= invDet;

	Vector3D r0 = Corss(b, v) + t * y;
	Vector3D r1 = Cross(v ,a) - t * x;
	Vector3D r2 = Cross(d, u) + s * w;
	Vector3D r3 = Cross(u, c) - s * z;

	return (Matrix3D(r0.x, r0.y, r0.z, -Dot(b, t),
					r1.x, r1.y, r1.z, Dot(a, t),
					r2.x, r2.y, r2.z, -Dot(d, s),
					r3.x, r3.y, r3.z, Dot(c, s))
			);
}

*/