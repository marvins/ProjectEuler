/**
 * @file    euler025.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <string>

// Common Libraries
#include "../common/BigIntegerLibrary.hh"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Fibonacci placeholders
    BigInteger Fn0 = 0;
    BigInteger Fn1 = 1;
    BigInteger Fn2 = 1;
    int64_t counter = 2;
    
    // Iterate until we hit a Fibonacci number with 1000 values
    while( true ){

        // Run the Fibonacci sequence
        Fn1 = Fn0;
        Fn0 = Fn2;
        Fn2 = Fn1 + Fn0;
        
        // Convert to a string and check
        if( bigIntegerToString( Fn2 ).size() >= 1000 )
        {
            std::cout << counter << std::endl;
            break;
        }

        // Increment Counter
        counter++;
    }  

    // Exit Program
    return 0;
}

