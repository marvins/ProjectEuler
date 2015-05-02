/**
 * @file    euler020.cpp
 * @author  Marvin Smith
 * @date    May 2, 2015
*/

// C++ Standard Libraries
#include <iostream>
#include <string>

// Common Libraries
#include "../common/BigIntegerAlgorithms.hh"
#include "../common/BigIntegerUtils.hh"
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Define the max value
    int max_value = 100;

    // Compute the factorial
    BigInteger factorial_number = factorial( max_value );

    // Convert to string
    std::string result = bigIntegerToString( factorial_number );

    // Compute sum
    int sum = 0;
    for( int i=0; i<result.size(); i++ ){
        sum += (result[i] - '0');
    }

    // Print Result
    std::cout << sum << std::endl;

    // Return value
    return 0;
}

