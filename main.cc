/**
 * @file main.cc
 * @author kyungpyo-kim (kyungpyo94@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-26
 *
 *
 */

#include <iostream>
#include <vector>
#include <time.h>

#include <opencv2/opencv.hpp>
#include <Eigen/Core>

#include "matmult.hpp"
#include "matmult_cache.hpp"
#include "timer.hpp"
#include "util.hpp"

std::vector<float> mat_a;
std::vector<float> mat_b;
std::vector<float> mat_c;
Timer t;

void benchmark_matmult()
{
    std::cout << "<< benchmark: matmult >>\n";

    for (int i = 0; i < 8; i++)
    {
        int dim = 2 << i;
        int iteration = 1000000 / dim;
        genmat(dim, dim, mat_a);
        genmat(dim, dim, mat_b);
        genmat(dim, dim, mat_c);

        double elapsed = 0;
        for (int i = 0; i < iteration; i++)
        {
            t.tic();
            matmult(dim, dim, dim, mat_a.data(), mat_b.data(), mat_c.data());
            elapsed += t.toc();
        }

        std::cout << "dim: " << dim << " elapsed time: " << std::fixed << 1000.0 * elapsed / iteration << " [ms]\n";
    }
}

void benchmark_matmult_cache()
{
    std::cout << "<< benchmark: matmult cache >>\n";

    for (int i = 0; i < 8; i++)
    {
        int dim = 2 << i;
        int iteration = 1000000 / dim;
        genmat(dim, dim, mat_a);
        genmat(dim, dim, mat_b);
        genmat(dim, dim, mat_c);

        double elapsed = 0;
        for (int i = 0; i < iteration; i++)
        {
            t.tic();
            matmult_cache(dim, dim, dim, mat_a.data(), mat_b.data(), mat_c.data());
            elapsed += t.toc();
        }

        std::cout << "dim: " << dim << " elapsed time: " << std::fixed << 1000.0 * elapsed / iteration << " [ms]\n";
    }
}

void benchmark_opencv()
{
    std::cout << "<< benchmark: opencv >>\n";

    for (int i = 0; i < 8; i++)
    {
        int dim = 2 << i;
        int iteration = 1000000 / dim;
        genmat(dim, dim, mat_a);
        genmat(dim, dim, mat_b);
        genmat(dim, dim, mat_c);

        cv::Mat cv_mat_a(dim, dim, CV_32F, mat_a.data());
        cv::Mat cv_mat_b(dim, dim, CV_32F, mat_b.data());
        cv::Mat cv_mat_c(dim, dim, CV_32F, mat_c.data());

        double elapsed = 0;
        for (int i = 0; i < iteration; i++)
        {
            t.tic();
            cv_mat_c = cv_mat_a * cv_mat_b;
            elapsed += t.toc();
        }

        std::cout << "dim: " << dim << " elapsed time: " << std::fixed << 1000.0 * elapsed / iteration << " [ms]\n";
    }
}

void benchmark_eigen()
{
    std::cout << "<< benchmark: eigen >>\n";

    for (int i = 0; i < 8; i++)
    {
        int dim = 2 << i;
        int iteration = 1000000 / dim;
        genmat(dim, dim, mat_a);
        genmat(dim, dim, mat_b);
        genmat(dim, dim, mat_c);

        Eigen::Map<Eigen::MatrixXf> eigen_mat_a(mat_a.data(), dim, dim);
        Eigen::Map<Eigen::MatrixXf> eigen_mat_b(mat_b.data(), dim, dim);
        Eigen::Map<Eigen::MatrixXf> eigen_mat_c(mat_c.data(), dim, dim);

        double elapsed = 0;
        for (int i = 0; i < iteration; i++)
        {
            t.tic();
            eigen_mat_c = eigen_mat_a * eigen_mat_b;
            elapsed += t.toc();
        }

        std::cout << "dim: " << dim << " elapsed time: " << std::fixed << 1000.0 * elapsed / iteration << " [ms]\n";
    }
}


int main(int argc, char **argv)
{
    benchmark_matmult();

    benchmark_matmult_cache();

    benchmark_opencv();

    benchmark_eigen();
    
    return 0;
}