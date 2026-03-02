#include "Matrix.h"

Matrix::Matrix()
{
    m = M;
    n = N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
             A[i][j] = 0;
        }
    }
}

Matrix::Matrix(int _m, int _n) : m(_m), n(_n)
{
    for (int i = 0; i < _m; i++)
    {
        for (int j = 0; j < _n; j++)
        {
            A[i][j] = 0;
        }
    }
}

void Matrix::read()
{
    std::cout << "Write the entries one by one:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> A[i][j];
        }
    }
}

void Matrix::print()
{
    std::cout << "Matrix Output:" << std::endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::multiply(Matrix other)
{
    if (n != other.m) {
        std::cout << "Error: Cannot multiply, different sizes" << std::endl;
        return Matrix();
    }

    Matrix result(m, other.n);

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < other.n; j++) {

            result.A[i][j] = 0;

            for (int k = 0; k < n; k++) {

                result.A[i][j] += A[i][k] * other.A[k][j];
            }
        }

    }
    return result;
}

Matrix Matrix::transpose()
{
    Matrix result(n, m); // invert dimensions

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            result.A[j][i] = A[i][j];
        }
    }
    return result;
}

double Matrix::determinant()
{

    // Verify that it is a 3x3 sized matrix

    if (m != 3 || n != 3) {
        std::cout << "The matrix is not 3x3" << std::endl;
        return 0.0;
    }

    /*
    Our matrix 3x3 is:

    |a b c|
    |d e f|
    |g h i|
       
    */

    double a = A[0][0]; double b = A[0][1]; double c = A[0][2];
    double d = A[1][0]; double e = A[1][1]; double f = A[1][2];
    double g = A[2][0]; double h = A[2][1]; double i = A[2][2];

    double det = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);

    return det;
}

Matrix Matrix::inverse()
{
    // Verify that it is a 3x3 sized matrix

    if (m != 3 || n != 3) {
        std::cout << "The matrix is not 3x3" << std::endl;
        return Matrix();

    }

    //Verify determinant is not zero
    double det = determinant();
    if (det == 0) {
        std::cout << "The matrix has no inverse" << std::endl;
        return Matrix();
    }

    /*
    Our matrix 3x3 is:

    |a b c|
    |d e f|
    |g h i|

    */

    double a = A[0][0]; double b = A[0][1]; double c = A[0][2];
    double d = A[1][0]; double e = A[1][1]; double f = A[1][2];
    double g = A[2][0]; double h = A[2][1]; double i = A[2][2];

    //cofactor matrix
    Matrix cofactor(3, 3);

    cofactor.A[0][0] = (e * i - f * h);
    cofactor.A[0][1] = -(d * i - f * g);
    cofactor.A[0][2] = (d * h - e * g);

    cofactor.A[1][0] = -(b * i - c * h);
    cofactor.A[1][1] = (a * i - c * g);
    cofactor.A[1][2] = -(a * h - b * g);

    cofactor.A[2][0] = (b * f - c * e);
    cofactor.A[2][1] = -(a * f - c * d);
    cofactor.A[2][2] = (a * e - b * d);

    // find the adjoint = transpose of the cofactor matrix
    Matrix adjoint(3, 3);
    adjoint = cofactor.transpose();

    Matrix result(3, 3);

    result = adjoint;

    // divide all the adjoint entries by the determinant of the original matrix
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            result.A[i][j] /= det ;
        }
    }

    return result;
}

Vector3D Matrix::multiply(Vector3D v)
{
    // Verify that it is a 3x3 sized matrix
    if (m != 3 || n != 3) {
        std::cout << "The matrix is not 3x3" << std::endl;
        return Vector3D();
    }
    
    
    double x = A[0][0] * v.x + A[0][1] * v.y + A[0][2] * v.z;
    double y = A[1][0] * v.x + A[1][1] * v.y + A[1][2] * v.z;
    double z = A[2][0] * v.x + A[2][1] * v.y + A[2][2] * v.z;

        return Vector3D(x, y, z);

}