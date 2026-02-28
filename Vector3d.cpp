#include "Vector3d.h"


Vector3D::Vector3D() : x(0), y(0), z(0) {
}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {
}

void Vector3D::print() {
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

double Vector3D::Magnitude()
{
	return std::sqrt(x*x + y*y + z*z);
}
