/**
 * @file    euler046.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Primesieve.hpp"

using namespace std;


/**
 * @brief Main Function
*/
int main(int argc, char* argv[])
{
    // Misc vars
    bool temp_bool;

    // Set our max prime number
    const int64_t  max_prime = 100000;

    // Construct the prime sieve
    Primes<int64_t> primes( max_prime );
    bool last_prime;
    int current_prime;

    // Compute the max square value
    const int64_t max_square = 111;

    // Iterate over odd numbers
    for( int64_t value = 3; value < max_prime; value+=2 ){
        
        // Test for prime (skip if true)
        if( primes.is_prime(value) == true ){ continue; }

        // Iterate over primes that are lower
        primes.prime_start();
        current_prime = primes.prime_next( last_prime );
        temp_bool = true;
        while( last_prime != true ){
            
            // Iterate over powers
            for( int i=0; i<max_square; i++ ){
                if( (current_prime + (2*i*i)) == value ){
                    temp_bool = false;
                    break;
                }
            }
            if( temp_bool == false ){
                break;
            }

            // Fetch next prime
            current_prime = primes.prime_next( last_prime );
            
        }

        // Check if the exit condition is still valid
        if( temp_bool == true ){
            std::cout << value << std::endl;
            break;
        }


    }
    
    // Exit Program
    return 0;
}
