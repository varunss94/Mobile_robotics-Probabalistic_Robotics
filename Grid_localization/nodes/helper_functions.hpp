#include <cmath>
#include <iostream>
#include <list>
#include <vector>

namespace hmm
{
    // definition of normal curve
    float gauss(float x, float mu, float sigma);

    // this experimentally approximates door sensor performance
    float door(float mu, float x);

    // gives probability that you are in front of a door
    // doors are centered at 11m, 18.5m, and 41m
    float p_door(float x);
    
    // gives probability that you are in front of a wall
    float p_wall(float x);

    // displays everything nicely
    template<typename Histogram>
    void display_basic(Histogram hist, const size_t SIZE);
}
