//
// Created by katya on 24/04/18.
//
#include "utils.h"

int random_number(int begin, int end){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(begin, end);
    return uni(rng);
}