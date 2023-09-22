#include <iostream>

#include "Vector3D.h"
#include "Matrix3D.h"

int main() 
{
	Vector3D vm;
	Vector3D v = Vector3D(0.4f, 0.5f, 0.2f);
	
	Matrix3D m = Matrix3D(Vector3D(1.2f, 2.4f, 1.3f), Vector3D(1.3f, 1.4f, 1.2f), Vector3D(1.5f, 1.5f, 1.5f));

	for (auto i = 0; i < 3; ++i)
	{
		v = v * 0.3f;
		vm = m * v;

		std::cout << vm.x << " " << vm.y << " " << vm.z << "\n";
	}
	

	return 0;
}