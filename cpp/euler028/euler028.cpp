/**
 * @file    euler028.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
 *
 * @note{ My solution to this problem is to create
 *        an equation to describe the repeating pattern.
 *
 *      see euler028-estimation.m for how I compute the equation using GNU octave.
 *
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief Main Function
*/
int main(int argc,char* argv[])
{
    // Define our max spiral width
    int64_t spiral_width = 1001;

    // Define our coeffiecients for the polynomial
    int64_t a =  4;
    int64_t b = -6;
    int64_t c =  6;

    // Iterate over the diameter
    int64_t sum = 1;

    // Iterate from 3 to 1001
    for( int n=3; n<=1001; n+=2 ){
        sum += ( a * n * n + b * n + c);
    }

    // Print output
    std::cout << sum << std::endl;

    // Return 
    return 0;
}
