/**
 * @file    euler063.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>


// Common Libraries
#include "../common/BigIntegerLibrary.hh"
#include "../common/StringUtilities.hpp"


using namespace std;


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Temp Values
    BigInteger product;
    std::string product_str;

    // Result
    int result = 9; // Accounting [1-9]^1
    const int max_n = 50; 
    const int max_x = 50;

    // Start iterating
    for( BigInteger n=2; n<=max_n; n++ )
    for( BigInteger x=1; x<=max_x;  x++ )
    {
        // Multiply
        product = power(x,n);
    
        // Check size
        product_str = bigIntegerToString(product);

        // Check the number of digits
        if( product_str.size() == n.toInt() ){
            result++;
        }

    }

    // Print result
    std::cout << result << std::endl;

    // Exit Program
    return 0;
}

