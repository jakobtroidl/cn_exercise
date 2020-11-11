#include "iostream"
#include "blaze/Math.h"

using blaze::DynamicVector;
using blaze::CompressedVector;
using blaze::StaticVector;

float blaze_vec_x_vec(int n)
{
    blaze::DynamicVector<float, blaze::columnVector> v1(n, 2.0F);
    blaze::DynamicVector<float, blaze::columnVector> v2(n, 2.0F);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    blaze::DynamicVector<float, blaze::columnVector> res = v1 * v2;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

float blaze_mat_x_vec(const int n)
{
    blaze::DynamicMatrix<float> m1(n, n,2.0F);
    blaze::DynamicVector<float, blaze::columnVector> v1(n, 2.0F);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    blaze::DynamicVector<float, blaze::columnVector> res = m1 * v1;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

float blaze_mat_x_mat(int n)
{
    blaze::DynamicMatrix<float> m1(n, n,2.0F);
    blaze::DynamicMatrix<float> m2(n, n,2.0F);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    blaze::DynamicMatrix<float> res = m1 * m2;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::duration<float> elapsed_seconds = end - begin;
    return elapsed_seconds.count();
}

int my_blaze()
{
    int p = 11;
    blaze::StaticVector<int,3UL,blaze::columnVector> v1{  2, 5, -1 };
    blaze::StaticVector<int,3UL,blaze::rowVector>    v2{ -1, 3, -2 };

    std::cout << "-----------------------" << std::endl;
    std::cout << "Blaze Mat x Mat" << std::endl;

    for (int j = 0; j < p; j++)
    {
        int n = pow(2, j);
        float t = blaze_mat_x_mat(n) / pow(n, 3);
        std::cout << "n: " << n << ", " << t << std::endl;
    }

    std::cout << "-----------------------" << std::endl;
    std::cout << "Blaze Mat x Vec" << std::endl;

    for (int j = 0; j < p; j++)
    {
        int n = pow(2, j);
        float t = blaze_mat_x_vec(n) / pow(n, 2);
        std::cout << "n: " << n << ", " << t << std::endl;
    }

    std::cout << "-----------------------" << std::endl;
    std::cout << "Blaze Vec x Vec" << std::endl;

    for (int j = 0; j < p; j++)
    {
        int n = pow(2, j);
        float t = blaze_vec_x_vec(n) / pow(n, 1);
        std::cout << "n: " << n << ", " << t << std::endl;
    }
}

