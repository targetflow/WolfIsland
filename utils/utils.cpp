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

// according to: https://stackoverflow.com/a/32697209/8219611
std::wstring stringToWstring(const std::string& t_str) {
    //setup converter
    typedef std::codecvt_utf8<wchar_t> convert_type;
    std::wstring_convert<convert_type, wchar_t> converter;

    //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
    return converter.from_bytes(t_str);
}