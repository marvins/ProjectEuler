/**
 * @file    euler034.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Math_Utilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ){

    // Define the digits
    std::vector<int8_t> digits;

    // Iterate over value range
    int64_t value_min = 10;
    int64_t value_max = 10000000;
    int64_t sum;
    int64_t total_sum = 0;
    for( int64_t value = value_min; value <= value_max; value++ )
    {
        // Get the digits
        digits = Split_Digits( value );
        sum = 0;

        // Check the factorial of each digit and sum
        for( int digit=0; digit < digits.size(); digit++ ){

            // Add to Sum
            sum += Factorial( digits[digit] );
        }

        // Check if sum equals the value
        if( sum == value ){
            total_sum += value;
        }

    }

    // Print output
    std::cout << total_sum << std::endl;
    
    // Return 
    return 0;
}


