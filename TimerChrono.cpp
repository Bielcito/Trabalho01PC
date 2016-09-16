#include "TimerChrono.h"

void TimerChrono::start()
{
    t1 = std::chrono::high_resolution_clock::now();
}

void TimerChrono::end()
{
    t2 = std::chrono::high_resolution_clock::now();
}

double TimerChrono::getElapsedTime()
{
    std::chrono::duration<double> tempo = t2 - t1;

    return tempo.count();
}

auto t2 = std::chrono::high_resolution_clock::now();
