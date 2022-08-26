/**
 * @file matmult_cache.hpp
 * @author kyungpyo-kim (kyungpyo94@gmail.com)
 * @brief improving matmul performance by caching intermediate results
 * @version 0.1
 * @date 2022-08-26
 *
 */
#ifndef __MATMUL_CACHE_HPP__
#define __MATMUL_CACHE_HPP__

#include <memory.h>

void matmult_cache(int m, int n, int k, const float *mat_a, const float *mat_b, float *mat_c)
{
    /*
        == input ==
        mat_a: m x k matrix
        mat_b: k x n matrix

        == output ==
        mat_c: m x n matrix (output)
    */

    memset(mat_c, 0, sizeof(float) * k * n);

    for (int i1 = 0; i1 < m; i1++)
    {
        for (int i3 = 0; i3 < k; i3++)
        {
            float tmp = mat_a[i1 * k + i3];

            for (int i2 = 0; i2 < n; i2++)
            {
                mat_c[i1 * n + i2] += tmp * mat_b[i3 * n + i2];
            }
        }
    }
}

#endif // __MATMUL_CACHE_HPP__