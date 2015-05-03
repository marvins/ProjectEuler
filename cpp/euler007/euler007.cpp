/**
 * @file    euler007.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <iostream>

#include "../common/Primesieve.hpp"

using namespace std;

/** 
 * Main Function
 */
int main( int argc, char* argv[] )
{
    // Max Value
    uint64_t max_value = 500000;
    int64_t prime = 0;
    bool last_prime;

    // Create a primesieve
    Primes<int64_t> sieve(max_value, true); 
    
    // Iterate over each prime
    for( int i=0; i<10001; i++ ){
        
        // Get the next prime
        prime = sieve.prime_next(last_prime);
        
        // if last prime, exit
        if( last_prime == true ){
            std::cerr << "error: Reached last prime." << std::endl;
            return 1;
        }
    }
    
    // Print the result
    std::cout << prime << std::endl;    

    // Exit
    return 0;
}

