/**
 * @file    euler049.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Since 12/3 = 4, set the max prime to 9999
    const int64_t max_prime = 9999;

    // Build the prime sieve
    Primes<int64_t> primes(max_prime);
    primes.prime_start();

    // Iterate through primes above 1000
    bool last_prime;
    int64_t test_prime, first_prime;
    int64_t current_prime = primes.prime_next( last_prime );
    std::string prime_str, output;
    int64_t prime_counter, prime_diff;
    bool exit_loop = false;
    while( last_prime != true && exit_loop != true )
    {
        // Only do this step if the prime is over 1000
        if( current_prime > 1000 ){
            
            // Run through permutations
            prime_str = num2str( current_prime );

            // Compute the next permutation
            prime_counter = 0;
            while( std::next_permutation( prime_str.begin(),
                                          prime_str.end() ))
            {
                // Convert to int
                test_prime = str2num<int64_t>( prime_str );

                // Check if first prime we need
                if( primes.is_prime(test_prime) == true &&
                    prime_counter == 0 )
                {
                    // Prime Counter Increment
                    prime_counter++;

                    // Set our first prime
                    first_prime = test_prime;

                    // compute diff
                    prime_diff = std::abs( test_prime - current_prime );
                }

                // Check if the second prime we need
                else if( primes.is_prime(test_prime) == true &&
                         prime_counter == 1 )
                {
                    // Compute the diffs
                    if( std::abs( test_prime - current_prime ) == prime_diff ||
                        std::abs( test_prime - first_prime   ) == prime_diff )
                    {
                        // Add the current prime to output
                        output += num2str(current_prime);

                        // Append the min of the test and first prime
                        output += num2str(std::min( test_prime, first_prime ));
                        
                        // Append the max of the test and first prime
                        output += num2str(std::max( test_prime, first_prime ));

                        // Exit the loop
                        exit_loop = true;
                        break;
                    }
                }
            }

        }

        // Fetch the next prime
        current_prime = primes.prime_next( last_prime );
    }

    // Print result
    std::cout << output << std::endl;

    // Exit Program
    return 0;
}

