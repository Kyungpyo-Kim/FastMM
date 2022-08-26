#pragma once
#ifndef __MATMULT_HPP__
#define __MATMULT_HPP__

// Please optimize this function
void matmult(int m, int n, int k, const float* mat_a, const float* mat_b, float* mat_c)
{
    /*
        == input ==
        mat_a: m x k matrix
        mat_b: k x n matrix

        == output ==
        mat_c: m x n matrix (output)
    */

    for (int i1=0; i1<m; i1++) {
        for (int i2=0; i2<n; i2++) {
            mat_c [n*i1 + i2] = 0;
            for (int i3=0; i3<k; i3++) {
                mat_c[n*i1 + i2] += mat_a[i1 * k + i3] * mat_b[i3 * n + i2];
            }
        }
    }
}

#endif // __MATMULT_HPP__