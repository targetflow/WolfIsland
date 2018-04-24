//
// Created by katya on 24/04/18.
//
#include "utils.h"

unsigned long random_number(unsigned long begin, unsigned long end){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<unsigned long> uni(begin, end);
    return uni(rng);
}