/**
 * @file    euler030.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <string>

// Common Libraries
#include "../common/StringUtilities.hpp"


using namespace std;


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    
    // Range of values
    int64_t min_value = 20;
    int64_t max_value = 500000;
    std::string value_str;
    int64_t n;
    int64_t sum;
    int64_t total_sum = 0;

    // Iterate over the value domain
    for( int64_t value = min_value; value <= max_value; value++ )
    {

        // Convert value to string
        value_str = num2str<int64_t>( value );

        // Iterate over the number
        sum = 0;
        for( int d = 0; d < (int)value_str.size(); d++ ){
            
            // Convert the char to int64
            n = value_str[d] - '0';

            // Power
            sum += std::pow( n, 5 );

        }

        // Check if power matches
        if( sum == value ){
            total_sum += value;
        }

    }

    // print the result
    std::cout << total_sum << std::endl;

    // Exit
    return 0;
}


