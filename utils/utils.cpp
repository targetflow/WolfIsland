//
// Created by katya on 24/04/18.
//
#include "utils.h"

// returns random number, according to [begin, end] interval
int random_number(int begin, int end){
    // creates generator that produces non-deterministic random numbers
    std::random_device rd;
    // Standard mersenne_twister_engine seeded with rd()
    std::mt19937 rng(rd());
    // Produces random integer values, uniformly distributed on the closed interval [a, b]
    std::uniform_int_distribution<int> uni(begin, end);
    // returns pseudo-random number from interval
    return uni(rng);
}

//  converts a const char* to a wstring
std::wstring stringToWstring(const std::string& t_str) {
    //setups converter
    typedef std::codecvt_utf8<wchar_t> convert_type;
    std::wstring_convert<convert_type, wchar_t> converter;
    return converter.from_bytes(t_str);
}