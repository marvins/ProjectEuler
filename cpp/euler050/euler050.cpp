/**
 * @file    euler050.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <sstream>
#include <string>

// Common Libraries
#include "../common/Primesieve.hpp"


using namespace std;


/**
 * @brief Main Function
*/
int main(int argc, char* argv[])
{
    
    // Define the max prime to compute
    int64_t max_prime = 1000000;

    // Construct prime list
    Primes<int64_t> primes(max_prime);

    // Misc Variables
    int64_t sum, count, J, SUM, result;
    int64_t max = 0;

    // iterate over prime range
    for( int64_t i=2; i<std::sqrt(max_prime); i++ )
    {
        // make sure the number is prime
        if( primes.is_prime( i ) == true )
        {
            
            // Start constructing sum
            sum = i;

            // Set count
            count = 1;
            
            // iterate over range
            for(int64_t j=i+1; j<max_prime/2; j++)
            {
                J = j;

                // Check if the value is prime
                if( primes.is_prime(J) )
                {
                    // Add to the value
                    if(((int64_t)sum + (int64_t)j)<max_prime){
                        sum += j;
                        SUM = sum;
                        count++;
                        if(primes.is_prime(SUM)){
                            if(count > max){
                                max = count;
                                result = sum;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}

