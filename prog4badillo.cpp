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
#include <cstdint>
using namespace std;

// Short-hand for unsigned long long int
typedef unsigned long long int ull_int;

struct SchoolInfo
{
public:
    ull_int n;
    ull_int a;
    ull_int b;
    ull_int d;

    SchoolInfo() : n(0), a(0), b(0), d(0) {} // Intializer list
    SchoolInfo(ull_int n, ull_int a, ull_int b, ull_int d)
        : n(n), a(a), b(b), d(d) {} // Parameterized constructor

    friend ifstream &operator>>(ifstream &infile, SchoolInfo &T)
    {
        infile >> T.n >> T.a >> T.b >> T.d;
        return infile;
    }
};

/**
 * @brief Prompts the user for i/o file names. Opens the i/o files and
 *        "returns" them via the arguments passed by reference.
 *
 * @param infile  input file stream by reference.
 * @param outfile output file stream by reference.
 *
 * @return Nothing.
 */
void openFiles(ifstream &infile, ofstream &outfile);

void getData(ifstream &infile, vector<SchoolInfo> &vect);

void print(ofstream &outfile, vector<SchoolInfo> &vect);

int main()
{
    vector<SchoolInfo> pct; // participants
    ifstream infile;
    ofstream outfile;

    openFiles(infile, outfile);

    getData(infile, pct);

    print(outfile, pct);
}

/**
 * @brief Prompts the user for i/o file names. Opens the i/o files and
 *        "returns" them via the arguments passed by reference.
 *
 * @param infile  input file stream by reference.
 * @param outfile output file stream by reference.
 *
 * @return Nothing.
 */
void openFiles(ifstream &infile, ofstream &outfile)
{
    string inFileName;  // std::strings are better
    string outFileName; // in my opinion v. c-strings

    cout << "Enter the input file name: ";
    cin >> inFileName;

    infile.open(inFileName); // Open input file
    cout << "Enter the output file name: ";

    cin >> outFileName;
    outfile.open(outFileName); // Open output file
}

void getData(ifstream &infile, vector<SchoolInfo> &vect)
{
    SchoolInfo temp;

    infile >> temp.n >> temp.a >> temp.b >> temp.d;
    vect.push_back(temp);

    while (!infile.eof())
    {
        infile >> temp.n >> temp.a >> temp.b >> temp.d;
        vect.push_back(temp);
    }
}

void print(ofstream &outfile, vector<SchoolInfo> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        outfile << vect[i].n << ' ' << vect[i].a << ' ' << vect[i].b << ' ' << vect[i].d << '\n';
    }
}