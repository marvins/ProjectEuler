/**
 * @file    euler027.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Primesieve.hpp"

using namespace std;

/**
 * @brief Compute the Quadratic Formula given coefficients
 */
int64_t quadratic( const int64_t& a, 
                   const int64_t& b, 
                   const int64_t& n )
{
   return (n*n + a*n + b);
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ){

    // Determine our max prime to consider
    int64_t max_prime = 100000;

    // Create the Prime Sieve
    Primes primes( max_prime, true );

    // Skip over the first few prime numbers
    bool last_prime;
    for(int i=0; i<10; i++){
        primes.prime_next(last_prime);
    }

    // Set our max/min values
    int64_t min_a = -999;
    int64_t min_b = -999;
    int64_t max_a =  999;
    int64_t max_b =  999;
    int64_t n;
    int64_t best_n = 0;
    int64_t best_a = min_a;
    int64_t best_b = min_b;

    // Start Looping
    for( int a = min_a; a<= max_a; a++ ){
    for( int b = min_b; b<= max_b; b++ ){

        // Iterate through n values, checking the number of prime values
        n = 0;
        while( primes.is_prime( quadratic( a, b, n )) == true ){
            n++;
        }

        // Check against best results
        if( n > best_n ){
            best_n = n;
            best_a = a;
            best_b = b;
        }
    }}

    // Print result
    std::cout << (best_a * best_b) << std::endl;

    // Exit Program
    return 0;
}

