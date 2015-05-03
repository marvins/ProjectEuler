/**
 * @file    euler036.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <deque>
#include <iostream>

// Common Libraries
#include "../common/Math_Utilities.hpp"


using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Define our max number
    const int64_t max_number = 1000000;

    // Misc Variables
    std::deque<bool> bit_array;
    int64_t sum = 0;

    // Iterate over numbers
    for( int i=1; i<max_number; i++ ){
        
        // Convert to bit array
        bit_array = To_Bit_Array( i );

        // Check if we have two palindromes
        if( Is_Palindrome( num2str(i) ) == true && 
            Is_Palindrome( bit_array ) == true )
        {
            sum += i;
        }

    }

    // Print result
    std::cout << sum << std::endl;

    // Exit Program
    return 0;
}


