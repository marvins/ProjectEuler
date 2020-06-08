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

using namespace std;

// Result Value
std::atomic<double> min_ratio;
std::atomic<uint64_t> min_n;
Primes<uint64_t>::ptr_t primes;
std::mutex mtx;

std::mutex print_lck;

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
        // Convert I to a string
        value_str = std::to_string( i );
        
        // Compute the totient
        totient = Euler_Totient( i, *primes );

        // Convert the totient to a string
        totient_str = num2str( totient );
        
        {
            std::unique_lock<std::mutex> lck( print_lck );
            std::cout << "Value: " << i << ", Totient: " << totient_str << ", Not Permutation" << std::endl;
        }

        // Compare strings
        if( Is_Permutation( value_str, totient_str ) )
        {
            
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

    uint64_t tmp = 87109;
    std::cout << "TMP: " << tmp << std::endl;
    std::cout << "ET1: " << Euler_Totient( tmp ) << std::endl;
    std::cout << "ET2: " << Euler_Totient( tmp, *primes ) << std::endl;
    std::string t1("87109");
    std::string t2("79180");
    std::cout << "Test: " << std::boolalpha << std::is_permutation( t1.begin(), t1.end(), t2.begin() ) << std::endl;

    // Create threads
    std::vector<std::thread> threads;
    for( int i=1; i<(number_threads+1); i++ )
    {
        threads.emplace_back( Process_Euler_Totient_Range, 
                              i,
                              number_threads, 
                              max_search_value );
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
