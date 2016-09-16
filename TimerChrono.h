#ifndef TIMERCHRONO_H
#define TIMERCHRONO_H

#include <chrono>

class TimerChrono
{
public:
    void start();

    void end();

    double getElapsedTime();

private:

    std::chrono::time_point<std::chrono::system_clock> t1;
    std::chrono::time_point<std::chrono::system_clock> t2;
};

#endif // TIMERCHRONO_H
