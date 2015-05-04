/**
 * @file    euler040.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <string>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Build the Fraction
*/
std::vector<int8_t> Build_Fraction( const int64_t& max_length )
{
    // Create output buffer
    std::vector<int8_t> output;

    // Start iterating until the length maxes out
    int64_t counter = 1;
    std::string temp_val;
    while( output.size() < max_length )
    {
        // Get the string value of the counter
        temp_val = num2str( counter );

        // Add to the output
        for( int i=0; i<temp_val.size(); i++ ){
            output.push_back( temp_val[i] - '0');
        }

        // Increment the counter
        counter++;
    }

    // Return output
    return output;
}

/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Define our max length for the fraction
    int64_t max_length = 1000001;

    // Create a huge list of values for the fraction
    std::vector<int8_t> fraction = Build_Fraction( max_length );


    // Compute the product
    int64_t product = fraction[1-1];
    product *= fraction[10-1];
    product *= fraction[100-1];
    product *= fraction[1000-1];
    product *= fraction[10000-1];
    product *= fraction[100000-1];
    product *= fraction[1000000-1];

    // Print result
    std::cout << product << std::endl;

    // Exit Program
    return 0;
}

