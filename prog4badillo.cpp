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

ull_int calcCombo(SchoolInfo t);

int main()
{
    ifstream infile;
    infile.open("prog4.txt");
    vector<SchoolInfo> info;
    getData(infile, info);

    for (int i = 0; i < info.size()-2; i++)
    {
        cout << calcCombo(info[i]) << '\n';
    }

    cout << calcCombo(info[5]) << '\n';
    cout << calcCombo(info[6]) << '\n';
}

ull_int calcCombo(SchoolInfo t)
{
    return C(t.n, t.a) * exp(C(t.b, t.d), t.a) % MAXVALUE;
}