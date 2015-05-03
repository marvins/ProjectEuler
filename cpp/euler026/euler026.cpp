/**
 * @file    euler026.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <vector>

// Common Libraries
#include "../common/BigInteger.hh"
#include "../common/BigIntegerUtils.hh"
#include "../common/Primesieve.hpp"

using namespace std;

/**
 * @brief Compute Prime Denom Cycle using Fermat's Algorithm.
*/
void Fermat_Prime_Cycle_Compute( Primes& primes )
{
    
    // Start the prime iterator
    primes.prime_start();

    // Misc Flags
    bool exit_loop = false;
    int64_t period;
    int64_t max_period = 0;
    int64_t max_prime = 0;

    // Get the next prime
    BigInteger current_prime = (int)primes.prime_next( exit_loop );
    BigInteger temp_result;

    // Iterate through each prime
    while( exit_loop != true ){

        // Iterate until 10^period mod prime == 1
        period = 1;

        // Increment the value until we get congruence
        temp_result = 10;
        while( true ){
            
            // Skip if the value has no mode as it is already divisible and thus no repeating
            if( temp_result % current_prime == 0 ){ break; }
            
            // Increment the prime period 
            if( temp_result % current_prime != 1 ){
                temp_result *= 10;
                period++;
            }
            // If it is equal to one, then we have reached our bound
            else{
                break;
            }
        }

        // Check if our period is higher than the current max
        if( period > max_period ){
            max_period = period;
            max_prime  = current_prime.toLong();
        }
        
        // Get the next prime
        current_prime = (int)primes.prime_next( exit_loop );

    }

    // Print result
    std::cout << max_prime << std::endl;
    
} 


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
  
    // Define the max value
    const int64_t max_value = 1000;

    // Create Prime List
    Primes primes(max_value);
    
    // Compute Recurring Cycle Using Fermat's Algorithm
    Fermat_Prime_Cycle_Compute( primes );

    return 0;
}

