/**
 * @file    euler035.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <deque>
#include <iostream>

// Common Libraries
#include "../common/Math_Utilities.hpp"
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;

// Define our debugging level
typedef std::false_type  DEBUG_TYPE;


/**
 * @brief Rotate Digits 
*/
void Rotate_Digits( std::deque<int8_t>& digits )
{
    int8_t data = digits.front();
    digits.pop_front();
    digits.push_back(data);
}


/**
 * @brief Check if Circular
*/
bool Is_Circular( int32_t const&          value,
                  Primes<int32_t,DEBUG_TYPE> const&  primes )
{

    // Check if below 10
    if( value < 10 ){ return true; }

    // Convert to string
    std::deque<int8_t> digits = Split_Digits<int32_t,std::deque<int8_t>>( value );
    Rotate_Digits( digits );
    
    // Iterate over permutations
    while( Merge_Digits<int32_t,std::deque<int8_t>>( digits ) != value )
    {
        // Check if prime
        if(primes.is_prime( (int32_t)Merge_Digits<int32_t,std::deque<int8_t>>( digits ) ) != true ){
            return false;
        }

        // Rotate the number
        Rotate_Digits( digits );

    }

    return true;

}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ){

    // Define our max value
    const int32_t max_value = 1000000;
    int32_t counter = 0;

    // Create the prime sieve
    Primes<int32_t,DEBUG_TYPE> primes(max_value, true);
    primes.prime_start();

    // Iterate over primes
    bool last_prime;
    int32_t current_prime = primes.prime_next( last_prime );

    while( last_prime != true ){

        // Check if circular
        if( Is_Circular( current_prime, primes ) == true ){
            counter++;
        }

        // fetch the next prime
        current_prime = primes.prime_next( last_prime );
    }

    // Print result
    std::cout << counter << std::endl;

    // Exit Program
    return 0;
}

