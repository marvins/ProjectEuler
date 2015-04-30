/**
 * @file    Math_Utilities.hpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#ifndef __MATH_UTILITIES_HPP__
#define __MATH_UTILITIES_HPP__

// C++ Standard Libraries
#include <cinttypes>
#include <vector>


/**
 * @brief Compute Divisors
*/
std::vector<int> Compute_Divisors( const int64_t& sum )
{
    // List of divisors
    std::vector<int> divisors;

    // Iterate over values
    for( int i=1; i<=sum; i++ ){
        if( (sum % i) == 0 ){
            divisors.push_back(i);
        }
    }

    // return divisor list
    return divisors;
}


#endif
