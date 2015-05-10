/**
 * @file    euler080.cpp
 * @author  Marvin Smith
 * @date    5/9/2015
*/

// C++ Standard Libraries
#include <cmath>
#include <iomanip>
#include <iostream>

// Boost Libraries
#include <boost/multiprecision/cpp_dec_float.hpp>

// Common Libraries
#include "../common/StringUtilities.hpp"


using namespace std;
using namespace boost::multiprecision;
typedef number<cpp_dec_float<200>> cpp_dec_float_200;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Misc Values
    int root;
    int max_value = 100;
    int64_t sum = 0;
    int64_t counter;

    // Iterate from 2 - 100
    for( int n=2; n<=max_value; n++ )
    {
        // Check if rational or irrational
        root = std::sqrt(n);
        if( n != root*root )
        {
            // Compute the square root
            cpp_dec_float_200 value = boost::multiprecision::sqrt( cpp_dec_float_200(n) );
            
            // Convert to a string
            std::string value_str = num2str(value, 200);
            
            // Sum the digits
            counter = 0;
            for( int j=0; j<value_str.size() && counter < 100; j++ )
            {
                if( value_str[j] != '.' ){
                    sum += (value_str[j] - '0');
                    counter++;
                }
            }
        }
    }

    // Print Result
    std::cout << sum << std::endl;

    // Exit
    return 0;
}

