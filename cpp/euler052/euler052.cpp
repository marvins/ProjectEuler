/**
 * @file    euler052.cpp
 * @author  Marvin Smith
 * @date    5/4/2015
*/

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
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
    // Set our max digit
    const int64_t max_digit = 999999999;

    // Misc Variables
    std::string value_str, temp_str;
    int64_t temp_value;
    bool is_valid;

    // Start iterating
    for( int64_t i=10; i<max_digit; i++ )
    {

        // Convert to string
        value_str = num2str(i);
        std::sort( value_str.begin(),
                   value_str.end() );

        is_valid = true;

        // Iterate from 2 to 6
        for( int j=2; j<= 6; j++ )
        {
            // Multiply
            temp_value = j * i;

            // Convert to string
            temp_str = num2str(temp_value);
            std::sort( temp_str.begin(),
                       temp_str.end() );

            // Check histograms
            if( temp_str != value_str ){
                is_valid = false;
                break;
            }
        }

        // Check if string is still valid
        if( is_valid == true ){
            std::cout << i << std::endl;
            break;
        }

    }

    // Exit Program
    return 0;
}

