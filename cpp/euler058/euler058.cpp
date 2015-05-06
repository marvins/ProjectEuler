/**
 * @file euler58.cpp
 * @author Marvin Smith
 * @date   9/25/2013
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
int main( int argc, char* argv[] )
{

    // Max prime
    int64_t max_prime = 999999999;

    // create prime sieve
    Primes<int64_t>  primes( max_prime );

    // iterate for n sides until you get less than 10% primes
    int64_t maxIterations = 10000000;
    int64_t side_length   = 2;
    int64_t corner_point  = 9;
    int64_t prime_counter  = 3;
    int64_t corner_counter = 4;
    bool exit_loop = false;
    for( int i=1; i<maxIterations && 
         exit_loop != true; i++ )
    {

        // Increment the side length
        side_length += 2;

        // Crunch each corner
        for( int i=0; i<4; i++ ){
            corner_point += side_length;
            
            // Check if prime
            if( primes.is_prime( corner_point ) == true )
            {
                prime_counter++;
            }
            corner_counter++;


        }

        // Check the ratio
        if(( (double)prime_counter / corner_counter) < 0.1){
            std::cout << side_length-1 << std::endl;
            exit_loop = true;
            break;
        }

    }

    return 0;
}

