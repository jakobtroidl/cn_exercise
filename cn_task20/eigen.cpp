#include <iostream>
#include "Eigen/Dense"

using namespace Eigen;

// vector vector multiplication
float vec_x_vec(int n)
{
    VectorXd vec1 = VectorXd::Random(n);
    VectorXd vec2 = VectorXd::Random(n);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    float m = vec1.dot(vec2);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

// matrix vector multiplication
float mat_x_vec(int n)
{
    MatrixXd mat1 = MatrixXd::Random(n, n);
    VectorXd vec2 = VectorXd::Random(n);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    MatrixXd m = mat1 * vec2;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

// matrix matrix multiplication
float mat_x_mat(int n)
{
    MatrixXd mat1 = MatrixXd::Random(n, n);
    MatrixXd mat2 = MatrixXd::Random(n, n);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    MatrixXd m = mat1 * mat2;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

int my_eigen() {

    int p = 11;

    std::cout << "------------------------" << std::endl;
    std::cout << "Eigen Matrix x Matrix" << std::endl;

    for (int i = 0; i < p; i++)
    {
        int n = pow(2,i);
        float sec = mat_x_mat(n) / pow(n, 3);
        std::cout << n << ": " << sec << std::endl;
    }

    std::cout << "------------------------" << std::endl;
    std::cout << "Eigen Matrix x Vector" << std::endl;

    for (int i = 0; i < p; i++)
    {
        int n = pow(2,i);
        float sec = mat_x_vec(n) / pow(n, 2);
        std::cout << n << ": " << sec << std::endl;
    }

    std::cout << "------------------------" << std::endl;
    std::cout << "Eigen Vector x Vector" << std::endl;

    for (int i = 0; i < p; i++)
    {
        int n = pow(2,i);
        float sec = vec_x_vec(n) / pow(n, 1);
        std::cout << n << ": " << sec << std::endl;
    }

    return 0;
}
