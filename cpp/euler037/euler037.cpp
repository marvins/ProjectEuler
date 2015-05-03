/**
 * @file    euler037.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <iostream>

// Common Libraries
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"


using namespace std;

/**
 * @brief Check if we are truncatable prime
 */
bool Is_Truncatable_Prime( const int64_t&          current_prime,
                           const Primes<int64_t>&  primes )
{
    // Convert to string
    std::string prime_str = num2str(current_prime);
    
    // First start popping right
    std::string temp_str = prime_str;
    int64_t temp_val;
    while( temp_str.size() >= 2 ){
        
        // Pop off the right-most letter
        temp_str = temp_str.substr(0, temp_str.size()-1);

        // Convert string to int
        temp_val = str2num<int64_t>( temp_str );

        // Check if prime
        if( primes.is_prime( temp_val ) == false ){
            return false;
        }
    }
    
    // Next, start popping left
    temp_str = prime_str;
    while( temp_str.size() >= 2 ){
        
        // Pop off the left-most letter
        temp_str = temp_str.substr(1);

        // Convert string to int
        temp_val = str2num<int64_t>( temp_str );

        // Check if prime
        if( primes.is_prime( temp_val ) == false ){
            return false;
        }
    }

    // If we get here, we obviously have not failed.
    return true;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Output sum
    int64_t sum = 0;
    int64_t counter = 0;

    // Define our max prime value
    int64_t max_prime = 1000000;

    // Create the prime sieve
    Primes<int64_t>  primes(max_prime);
    primes.prime_start();

    // Start iterating over prime values
    bool last_prime;
    int64_t current_prime = primes.prime_next(last_prime);
    while( last_prime != true )
    {

        // Check if the value is less than 10
        if( current_prime < 10 ){
            current_prime = primes.prime_next(last_prime);
            continue;
        }

        // Otherwise, start truncating values
        if( Is_Truncatable_Prime( current_prime, primes ) == true ){
            counter++;
            sum += current_prime;
        }

        // Get the next prime
        current_prime = primes.prime_next(last_prime);
    }

    // Print result
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    // Exit Program
    return 0;
}

