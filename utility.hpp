#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Utility {
public:
    void cinfail();
    void cls();
    void unget(int = 1);
    bool is_letter(char);
    bool is_number(char);
    bool is_operator(char);
};

#endif // UTILITY_HPP_INCLUDED
