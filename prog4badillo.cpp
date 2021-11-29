/****************************************************************************
 * Name: Angel Badillo
 *
 * Course: CMPS-2433-101, Fall 2021, Springfellow
 *
 * Purpose:
 *
 ****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "combo.hpp"
#include <cstdint>
using namespace std;


int main()
{
    int x = 4;
    ull_int product = factorial(20);
    cout << product << '\n';

    ull_int val;

    val = C(20,2);
    cout << val << '\n';

    ull_int y;

    y = exponential(2,-1);
    cout << y << '\n';
}

