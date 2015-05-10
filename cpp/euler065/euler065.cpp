/**
 * @file    euler065.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/BigIntegerLibrary.hh"

using namespace std;


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Max convergent value
    const int max_convergent = 100;

    BigInteger e, n2;
    BigInteger n0 = 1;
    BigInteger n1 = 2;

    // Given E, start computing convergents
    for( int i=2; i<=max_convergent; i++ ){
        
        // E's period is 1,1,2,1,1,4,1,1..2k..
        e = 1;
        if( i%3 == 0 ){
            e = 2*(i/3);
        }

        // Compute n1
        n2 = e * n1 + n0;
        n0 = n1;
        n1 = n2;
    }

    // Sum the digits
    std::string digits = bigIntegerToString(n2);
    int sum = 0;
    for( int i=0; i<digits.size(); i++ )
    {
        sum += (digits[i] - '0');
    }

    // Print result
    std::cout << sum << std::endl;

    // Exit Program
    return 0;
}

