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

#define MAXVALUE 1000000007
typedef unsigned long long int ull;


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
 * @brief Reads data from input file to vector.
 *
 * @param infile   input file stream by reference.
 * @param compInfo compInfo object by value.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, ull &n, ull &a, ull &b, ull &d);

/**
 * @brief Prints
 *
 * @param outfile  output file stream by reference.
 * @param compInfo compInfo object by value.
 *
 * @return Nothing.
 */
void print(ofstream &outfile, ull n, ull a, ull b, ull d);

unsigned long long int exp(unsigned long long int a, int n);

/**
 * @brief Calculates factorial
 *
 * @param n An integer.
 *
 * @return unsigned long long int
 */
unsigned long long int factorial(int n);

unsigned long long int C(int n, int r);

unsigned long long int calcCombo(ull n, ull a, ull b, ull d);

int main()
{
    ifstream infile;
    ofstream outfile;

    unsigned long long int n{0};
    unsigned long long int a{0};
    unsigned long long int b{0};
    unsigned long long int d{0};
    
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
unsigned long long int factorial(int n)
{
    unsigned long long int product = 1; // 0! is 1, so we start here

    // If n > 0, calculate factorial
    for (int i = 1; i <= n; i++)
    {
        product *= i % MAXVALUE;
    }

    return product % MAXVALUE;
}

unsigned long long int C(int n, int r)
{
    return (factorial(n) / ((factorial(r) * factorial(n - r)))) % MAXVALUE;
}

// For our purposes, this will work, no error checking necessary.
// C(0,0) and 0! are 1, and we are working with positive integers.
unsigned long long int exp(unsigned long long int a, int n)
{
    unsigned long long int product = 1;

    for (int i = 0; i < n; i++)
        product *= a % MAXVALUE;

    return product % MAXVALUE;
}

unsigned long long int calcCombo(ull n, ull a, ull b, ull d)
{
    return C(n, a) * exp(C(b, d), a) % MAXVALUE;
}