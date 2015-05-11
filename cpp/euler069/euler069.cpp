/**
 * @file    euler069.cpp
 * @author  Marvin Smith
 * @date    5/10/2015
 *
 * This method seeks to minimize Euler's Totient Function.
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
int main( int argc, char* argv[] )
{
    // define our max number
    int64_t max_number = 1000000;
    int64_t max_prime  = 10000000;

    // Create the prime sieve
    Primes<int64_t> sieve(max_prime);
    sieve.prime_start();

    // Misc Variables
    int result = 1;
    bool last_prime = false;

    // Iterate over values
    while( result * sieve.prime_next( last_prime, false ) < max_number 
            && last_prime != true )
    {

        // Get the next prime
        result *= sieve.prime_next( last_prime );
    }

    // Print solution
    std::cout << result << std::endl;

    // Exit Program
    return 0;
}

