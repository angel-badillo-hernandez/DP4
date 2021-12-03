/****************************************************************************
 * Name: Angel Badillo
 *
 * Course: CMPS-2433-101, Fall 2021, Springfellow
 *
 * Purpose: This program will read 4 integers from an input file.
 *          N, number of school from which A will participate.
 *          B, students per school where D students participate.
 *          After reading the input, the program will print the computation
 *          for each combination to the output file.
 *
 ****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

#define MAXVALUE 1000000007     // Used for printing large output with %
typedef unsigned long long ull; // 


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

/**
 * @brief Read data from input file to variables.
 * 
 * @param infile ifstream object by reference.
 * @param n      ull by reference.
 * @param a      ull by reference.
 * @param b      ull by reference.
 * @param d      ull by reference.
 */
void getData(ifstream &infile, ull &n, ull &a, ull &b, ull &d);

/**
 * @brief Prints computation of combination to output file.
 * 
 * @param outfile ofstream by reference.
 * @param n      ull by reference.
 * @param a      ull by reference.
 * @param b      ull by reference.
 * @param d      ull by reference.
 */
void print(ofstream &outfile, ull n, ull a, ull b, ull d);

/**
 * @brief Exponentiates an ull, a, to a power n, an integer.
 * 
 * @param a ull by value.
 * @param n int by value.
 * @return  ull, the result.
 */
ull exp(ull a, int n);

/**
 * @brief Calculates factorial of n!
 *
 * @param n int by value.
 *
 * @return ull, the result.
 */
ull factorial(int n);

/**
 * @brief Calculates a combination of C(n,r)
 * 
 * @param n ull by value.
 * @param r ull by value.
 * @return  ull, the result. 
 */
ull C(int n, int r);

/**
 * @brief Calculates the combination of N items
 *        where exactly are picked. And for every
 *        N item there are B items. And D out of B items
 *        picked.
 * 
 * @param n  ull by reference.
 * @param a  ull by reference.
 * @param b  ull by reference.
 * @param d  ull by reference.
 * @return   ull, the result. 
 */
ull calcCombo(ull n, ull a, ull b, ull d);

int main()
{
    ifstream infile;
    ofstream outfile;

    ull n{0}, a{0}, b{0}, d{0};
    
    openFiles(infile, outfile);

    infile >> n >> a >> b >> d;

    while(!infile.eof())
    {
        outfile << (C(n, a) * exp(C(b, d), a) % MAXVALUE) << '\n';
        infile >> n >> a >> b >> d;
    }
    
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

void getData(ifstream &infile, ull &n, ull &a, ull &b, ull &d)
{
    infile >> n >> a >> b >> d;
}

// works up to 20
ull factorial(int n)
{
    ull product = 1; // 0! is 1, so we start here

    // If n > 0, calculate factorial
    for (int i = 1; i <= n; i++)
    {
        product *= i % MAXVALUE;
    }

    return product % MAXVALUE;
}

ull C(int n, int r)
{
    return (factorial(n) / ((factorial(r) * factorial(n - r)))) % MAXVALUE;
}

// For our purposes, this will work, no error checking necessary.
// C(0,0) and 0! are 1, and we are working with positive integers.
ull exp(ull a, int n)
{
    ull product = 1;

    for (int i = 0; i < n; i++)
        product *= a % MAXVALUE;

    return product % MAXVALUE;
}

ull calcCombo(ull n, ull a, ull b, ull d)
{
    return C(n, a) * exp(C(b, d), a) % MAXVALUE;
}