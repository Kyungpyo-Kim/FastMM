#pragma once
#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

void genmat(int n, int m, std::vector<float> &mat)
{
    srand(time(0));
    mat.resize(n * m);
    for (int i = 0; i < mat.size(); i++)
        mat[i] = rand() % 100;
}

void dumpmat(int n, int m, std::vector<float> &mat)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%f ", mat[i * m + j]);
        printf("\n");
    }
}

#endif // __UTIL_HPP__