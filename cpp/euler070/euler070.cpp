/**
 * @file    euler070.cpp
 * @author  Marvin Smith
 * @date    5/14/2015
*/

// C++ Standard Libraries
#include <atomic>
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Common Libraries
#include "../common/Math_Utilities.hpp"
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;

// Result Value
std::atomic<double> min_ratio;
std::atomic<uint64_t> min_n;
Primes<uint64_t>::ptr_t primes;
std::mutex mtx;


/**
 * @brief Check if even digits exist.
*/
bool Check_Even_Digit( const std::string& str )
{
    for( int i=0; i<str.size(); i++ ){
        if( (str[i] - '0') % 2 == 0 ){
            return true;
        }
    }
    return false;
}

/**
 * Process the Euler Totient Function
*/
void  Process_Euler_Totient_Range( const int& start_idx,
                                   const int& skip_counter, 
                                   const uint64_t& max_value )
{
    
    // Misc
    std::string totient_str;
    std::string value_str;
    double ratio;
    uint64_t totient;

    // Iterate over values
    for( uint64_t i=start_idx; i<max_value; i += skip_counter )
    {
        // Skip Even Number
        if( i % 2 == 0 ){ continue; }

        // Convert I to a string
        value_str   = num2str( i );
        
        // Make sure there is at least one even number
        if( Check_Even_Digit( value_str ) == false ){ 
            continue;
        }

        // Compute the totient
        totient = Euler_Totient( i, *primes );

        // Convert the totient to a string
        totient_str = num2str( totient );
        
        // Compare strings
        if( Is_Permutation( value_str, totient_str ) == true ){
            
            // Compute ratio
            ratio = (double)i / totient;

            // Check ratio
            if( ratio < min_ratio ){
                mtx.lock();
                min_ratio = ratio;
                min_n = i;
                std::cout << "Permutation Found: " << i << ", phi: " << totient << ", ratio: " << ratio << std::endl;
                mtx.unlock();
            }
        }
    }

    std::cout << "End of Thread " << start_idx << std::endl;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Set initials
    min_ratio = 1000000;
    min_n = 0;

    // Number of threads
    int number_threads = 4;

    // Max Prime Value
    uint64_t max_prime_value = 100000000;
    
    // Max Search Value
    uint64_t max_search_value = std::pow(10,7);

    // Euler's Totient
    primes = std::make_shared<Primes<uint64_t>>( max_prime_value );

    uint64_t tmp = 8319823;
    std::cout << "Prime: " << primes->is_prime(tmp) << std::endl;
    std::cout << "ET1: " << Euler_Totient( tmp ) << std::endl;
    std::cout << "ET2: " << Euler_Totient( tmp, *primes ) << std::endl;
    std::cin.get();

    // Create threads
    std::vector<std::thread> threads;
    for( int i=0; i<number_threads; i++ ){
        threads.push_back(std::thread( Process_Euler_Totient_Range, 
                                       i + 10, 
                                       number_threads*2, 
                                       max_search_value ));
    }
    
    // Join Threads
    for( int i=0; i<number_threads; i++ ){
        threads[i].join();
    }

    // Print Result
    std::cout << min_n << std::endl;

    // Exit Program
    return 0;
}
