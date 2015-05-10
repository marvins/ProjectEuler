/**
 * @file    euler064.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
 */

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <deque>
#include <iostream>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;


/**
 * @brief Compute Period N
*/
int64_t Compute_Period_N( const int64_t&   S,
                          const int64_t&   m_n, 
                          const int64_t&   d_n,
                          const int64_t&   a_n,
                          const int64_t&   a_0,
                          const int64_t&   count,
                          const int64_t&   max_count )
{

    // Exit Condition
    if( count >= max_count ){
        std::cout << "At Max: " << S << std::endl;
        return 0;
    }


    // Compute M_n+1
    int64_t m_n1 = d_n * a_n - m_n;

    // Compute D_n+1
    int64_t d_n1 = (S - (m_n1*m_n1)) / d_n;
    if( d_n1 == 0 ){ 
        return 0; 
    }

    // Compute A_n+1
    int64_t a_n1 = (a_0 + m_n1)/(d_n1);
    if( a_n1 == (2*a_0)){ 
        return count+1;
    }

    // Enter recursively
    return Compute_Period_N( S, m_n1, d_n1, a_n1, a_0, count+1, max_count );
}


/**
 * @brief Compute Periodic Fraction
*/
int64_t Estimate_Period( const int64_t& value,
                         const int64_t& max_period )
{
    // Determine m0, d0, a0
    int64_t m0 = 0;
    int64_t d0 = 1;
    int64_t a0 = std::sqrt(value);
    if( a0*a0 == value ){ return 0; }

    // Compute Period N
    return Compute_Period_N( value, m0, d0, a0, a0, 0, max_period );
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Variables
    int odd_period_count = 0;

    // Max Period
    int max_period = 1000;
    int64_t period;
    
    // Iterate from 2-1000
    for( int n=2; n<=10000; n++ )
    {
        // Compute the periodicity
        period = Estimate_Period( n, max_period );
        if( period % 2 != 0 ){
            odd_period_count++;
        }
    }

    // Print results
    std::cout << odd_period_count << std::endl;

    // Exit Program
    return 0;
}

