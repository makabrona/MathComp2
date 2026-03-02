#include <iostream>
#include "Matrix.h"

int main()
{

    std::cout << "Test Matrix Program" << std::endl;

    // FIRST MATRIX

    Matrix matA(3, 3);

    std::cout << "Insert the values of the Matrix A" << std::endl;

    matA.read();
    matA.print();

    // SECOND MATRIX

    Matrix matB(3, 3);
    std::cout << "Insert the values of the Matrix B" << std::endl;
    matB.read();
    matB.print();
    
    // MULTIPLY

    std::cout << "If we multiply the matrices AB we get:" << std::endl;
    
    Matrix multipliedMat = matA.multiply(matB);

    multipliedMat.print();

    // TRANSPOSE

    std::cout << "Let's transpose matrix A: " << std::endl;
    
    Matrix transposedA = matA.transpose();

    transposedA.print();

    std::cout << "Let's transpose matrix B: " << std::endl;

    Matrix transposedB = matB.transpose();

    transposedB.print();

    // FIND THE DETERMINANTS

    std::cout << "Let's find the determinant of matrix A: " << std::endl;

    double determinantA = matA.determinant();

    std::cout << "Determinant: " << determinantA << std::endl;

    std::cout << "Let's find the determinant of matrix B: " << std::endl;

    double determinantB = matB.determinant();

    std::cout << "Determinant: " << determinantB << std::endl;

    // FIND THE INVERSE

    std::cout << "Let's find the inverse of matrix A: " << std::endl;

    Matrix inverseA = matA.inverse();
    inverseA.print();

    std::cout << "Let's find the inverse of matrix B: " << std::endl;

    Matrix inverseB = matB.inverse();
    inverseB.print();

    // MULTIPLICAR POR VECTOR v(1, 2, 3)

    Vector3D vector(1, 2, 3);

    std::cout << "Let's multiply with vector v(1, 2, 3)" << std::endl;
    std::cout << "Matrix A * v: " << std::endl;

    Vector3D resultA = matA.multiply(vector);

    resultA.print();

    std::cout << "Matrix B * v: " << std::endl;

    Vector3D resultB = matB.multiply(vector);

    resultB.print();

    
    return 0;
}