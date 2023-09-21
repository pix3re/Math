#include <iostream>

#include "Vector3D.h"

int main() 
{
	Vector3D v1 = Vector3D(0.4f, 0.5f, 0.2f);
	Vector3D v2 = Vector3D(0.5f, 0.3f, 0.3f);

	v1 += v2;

	std::cout << v1[0] << ", " << v1[1] << ", " << v1[2] << std::endl;
	std::cout << v2[0] << ", " << v2[1] << ", " << v2[2] << std::endl;


	return 0;
}