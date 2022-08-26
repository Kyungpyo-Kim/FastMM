#pragma once
#ifndef __TIMER_HPP__
#define __TIMER_HPP__


#include <time.h>

class Timer
{
    struct timespec s_;

public:
    Timer() { tic(); }
    void tic()
    {
        clock_gettime(CLOCK_REALTIME, &s_);
    }

    double toc()
    {
        struct timespec e;
        clock_gettime(CLOCK_REALTIME, &e);
        return (double)(e.tv_sec - s_.tv_sec) + 1e-9 * (double)(e.tv_nsec - s_.tv_nsec);
    }
};

#endif // __TIMER_HPP__