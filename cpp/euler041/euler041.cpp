/**
 * @file    euler041.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Math_Utilities.hpp"
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Define our max number to build our prime sieve from
    int64_t max_prime = 987654321;

    // Construct the prime sieve
    Primes<int64_t> primes( max_prime);
    primes.prime_start();
    std::vector<int> prime_table(9,0);

    // Start iterating over prime values
    bool last_prime;
    std::string prime_str;
    int current_prime = primes.prime_next(last_prime);
    while( last_prime != true ){

        // Check if pandigital
        prime_str = num2str(current_prime);
        if( Is_Pandigital( prime_str ) == true ){
            
            // Check the table
            std::cout << current_prime << " is pandigital" << std::endl;
            if( prime_table[prime_str.size()] < current_prime ){
                prime_table[prime_str.size()] = current_prime;
            }
        }

        // Fetch the next prime
        current_prime = primes.prime_next(last_prime);
    }

    // Print the result
    for( int i=prime_table.size()-1; i>=0; i-- ){
        if( prime_table[i] > 0 ){
            std::cout << prime_table[i] << std::endl;
            break;
        }
    }

    // Exit Program
    return 0;
}

