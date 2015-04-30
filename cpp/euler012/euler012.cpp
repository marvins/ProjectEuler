/**
 * @file    euler012.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <cmath>
#include <iostream>

#include "../common/Math_Utilities.hpp"

using namespace std;

/**
 * @brief Compute the number of divisors
*/
int Number_Of_Divisors( const int64_t& number )
{
    // Compute Square Root
    int64_t sq = std::sqrt( number );
    int64_t count = 0;

    // Iterate over value
    for( int i=1; i<sq; i++ ){
        if( number % i == 0 ){
            count += 2;
        }
    }

    // Handler if perfect square
    if( sq * sq == number ){
        count--;
    }

    // Count
    return count;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Iterate over values, creating triangle numbers
    int64_t sum = 0;
    int64_t counter = 1;
    int64_t number_divisors;
    while( true ){
        
        // Add to sum
        sum += counter;

        // Break into divisors
        number_divisors = Number_Of_Divisors( sum );

        // Check the number of divisors
        if( number_divisors > 500 ){
            std::cout << sum << std::endl;
            break;
        }

        // Increment Counter
        counter++;

    }

    // Return success
    return 0;
}

