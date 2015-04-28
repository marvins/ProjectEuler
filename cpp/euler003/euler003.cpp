/**
 * @file    euler003.cpp
 * @author  Marvin Smith
 * @date    4/27/2015
*/
#include <iostream>

#include "Primesieve.hpp"

using namespace std;

/** 
 * Main Function
 */
int main( int argc, char* argv[] )
{
    // Max Value
    uint64_t max_value = 600851475143;
    int64_t current_prime = 0;

    // Create a primesieve
    Primes sieve(std::sqrt(max_value), true); 
    
    // Iterate over each prime
    bool last_prime = false;
    int64_t prime;
    while( last_prime == false ){
        
        // Get the next prime
        prime = sieve.prime_next(last_prime);

        // Make sure it is not the last prime
        if( last_prime == true ){
            break;
        }

        // Check if divisible by max value
        if( max_value % prime == 0 ){
            current_prime = prime;
        }
    }
    
    // Output
    std::cout << current_prime << std::endl;

    // Exit
    return 0;
}

