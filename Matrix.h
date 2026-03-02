#pragma once
#include "Vector3d.h"
#include <iostream>

class Matrix
{
public:
    Matrix(); // default constructor
    Matrix(int _m, int _n); // sized constructor
    void read();
    void print();
    Matrix multiply(Matrix other);
    Matrix transpose();
    double determinant();
    Matrix inverse();
    Vector3D multiply(Vector3D v);


    static const int M = 10;
    static const int N = 10;
    double A[M][N];
    int m; // actual number of rows
    int n; // actual number of columns
};

