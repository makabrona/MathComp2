#pragma once
#include <cmath>
#include <iostream>

class Vector3D {
public:
    double x;
    double y;
    double z;

    Vector3D();
    Vector3D(double x, double y, double z); // sized constructor

    void print();
};