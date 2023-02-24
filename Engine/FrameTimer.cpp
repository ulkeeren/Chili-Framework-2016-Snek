#include "FrameTimer.h"
#include <chrono>
using namespace std::chrono;
FrameTimer::FrameTimer()
{
    t = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
    auto old = t;
    auto n = std::chrono::steady_clock::now();
    duration<float> totalTime = n - old;
    return totalTime.count();
}

