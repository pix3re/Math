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
};

inline Vector3D operator +(const Vector3D& v1, const Vector3D& v2)
{
	return (Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3D operator -(const Vector3D& v)
{
	return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator *(const Vector3D& v, float s)
{
	return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float S)
{
	float s = 1.0f / S;
	return (Vector3D(v.x / s, v.y / s, v.z / s));
}

inline float Magnitude(const Vector3D& v)
{
	return (std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
	return (v / Magnitude(v));
}

inline float Dot(const Vector3D& a, const Vector3D& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.y * b.z -a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

inline Vector3D Project(const Vector3D& a, const Vector3D& b)
{
	return (b * Dot(a, b) / Dot(b, b));
}

inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
{
	return (a - b * (Dot(a, b) / Dot(b, b)));
}