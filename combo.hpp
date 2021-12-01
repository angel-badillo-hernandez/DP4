#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define INTMAX 2147483647

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

/**
 * @brief Reads data from input file to vector.
 *
 * @param infile  input file stream by reference.
 * @param vect    A vector of School info by reference.
 *
 * @return Nothing.
 */
void getData(ifstream &infile, vector<SchoolInfo> &vect);

/**
 * @brief Prints
 *
 * @param outfile output file stream by reference.
 * @param vect    A vector of School info by reference.
 *
 * @return Nothing.
 */
void print(ofstream &outfile, vector<SchoolInfo> &vect);

/**
 * @brief Calculates factorial
 *
 * @param n An integer.
 *
 * @return ull_int
 */
ull_int factorial(int n);

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

// works up to 20
ull_int factorial(int n)
{
    ull_int product = 1; // 0! is 1, so we start here

    // If n > 0, calculate factorial
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }

    return product;
}

ull_int C(int n, int r)
{
    return factorial(n) / ((factorial(r) * factorial(n - r)));
}

// For our purposes, this will work, no error checking necessary.
// C(0,0) and 0! are 1, and we are working with positive integers.
ull_int exponential(ull_int a, int n)
{
    ull_int product = 1;

    for (int i = 0; i < n; i++)
        product *= a;

    return product;
}

void print(ofstream &outfile, vector<SchoolInfo> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        outfile << vect[i].n << ' ' << vect[i].a << ' ' << vect[i].b << ' ' << vect[i].d << '\n';
    }
}
