/**
 * @file    Math_Utilities.hpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#ifndef __MATH_UTILITIES_HPP__
#define __MATH_UTILITIES_HPP__

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
#include <deque>
#include <iterator>
#include <sstream>
#include <vector>

// Common Libraries
#include "StringUtilities.hpp"

/**
 * @brief Compute Factorial
 * 
 * @param[in] value Value to compute.
 *
 * @return Factorial result.
*/
int64_t Factorial( int64_t const& value ){

    // Check if 0
    if( value == 0 ){ return 1; }

    // Otherwise iterate over value
    int64_t sum = value;

    for( int64_t s = value - 1; s>1; s-- ){
        sum *= s;
    }

    // return sum
    return sum;
}


/**
 * @brief Split Digits
*/
template < typename TP, 
           typename LIST_TYPE = std::vector<int8_t>>
LIST_TYPE Split_Digits( const TP& number )
{
    // Create output
    LIST_TYPE output;

    // Parse input
    std::stringstream sin;
    sin << number;
    std::string numstr;
    sin >> numstr;

    for( int i=0; i<numstr.size(); i++ ){
        output.push_back(numstr[i] - '0');
    }

    return output;
}


/**
 * @brief Merge Digits into Value
*/
template< typename TP,
          typename LIST_TYPE = std::vector<int8_t>>
TP Merge_Digits( LIST_TYPE const& digits )
{
    // Create string
    std::string data;
    typename LIST_TYPE::const_iterator it = digits.begin();
    for( ; it != digits.end(); it++ ){
        data.push_back( (char)((*it) + '0') );
    }

    // Convert to value
    return str2num<TP>(data);
}


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


/**
 * @brief Create Bit Array
 *
 * @return Binary Bit Array
*/
template < typename DATATYPE,
           typename LIST_TYPE = std::deque<bool>>
LIST_TYPE  To_Bit_Array( DATATYPE const& value )
{
    // Create output
    LIST_TYPE output;

    // Iterate while our value is greater than zero
    DATATYPE temp_val = value;
    DATATYPE remainder;
    while( temp_val > 0 ){
        
        // Add to output
        output.push_back( (temp_val & 1) );

        // Decrement
        temp_val >>= 1;

    }

    // Check size
    if( output.size() <= 0 ){
        output.push_back(false);
    }

    // Otherwise, reverse
    else{
        std::reverse( output.begin(), output.end() );
    }

    // return output
    return output;
}


/**
 * @brief Check if value is palindrome
 *
 * @param[in] value Value to test.
 *
 * @return True if palindrome, false otherwise.
*/
template <typename DATATYPE>
bool Is_Palindrome( const DATATYPE& value )
{
    
    // Iterate over string
    for( int i=0; i<(value.size()/2); i++ )
    {
        if( value[i] != value[value.size()-i-1]){
            return false;
        }
    }
    return true;
}


/**
 * @brief Check if Pandigital
 *
 * @param[in] value Value to test.
 *
 * @return True if pandigital
*/
bool Is_Pandigital( const std::string& value )
{
    // Create histogram
    std::vector<bool> histogram(9,false);

    // Error check
    if( value.size() > 9 ){
        return false;
    }

    // Iterate over string
    for( int i=0; i<value.size(); i++ ){
        if( value[i] < '1' || value[i] > '9' ){ return false;}
        histogram[value[i] - '1'] = true;
    }

    // Check if any false
    for( int i=0; i<histogram.size(); i++ ){
        if( histogram[i] == false ){ return false; }
    }
    return true;
}

#endif
