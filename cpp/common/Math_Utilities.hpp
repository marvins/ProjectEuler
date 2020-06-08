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
#include <set>
#include <sstream>
#include <vector>

// Common Libraries
#include "Primesieve.hpp"
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

    for( int i=0; i<(int)numstr.size(); i++ ){
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
 * @brief Compute Prime Divisors
*/
void Compute_Prime_Divisors( const int64_t&  sum, 
                             std::set<int>&  divisors )
{
    // Create temp list
    std::set<int> temp_divisors;

    // Iterate over values
    for( int i=2; i<=(sum-1); i++ ){
        if( (sum % i) == 0 ){
            
            // Compute divisors of value
            Compute_Prime_Divisors( i, temp_divisors );

            // Check if prime divisor
            if( temp_divisors.size() <= 0 ){
                divisors.insert(i);
            }

            // Otherwise, call recursively
            else{
                Compute_Prime_Divisors( i, divisors);
            }
        }
    }

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
    while( temp_val > 0 ){
        
        // Add to output
        output.push_back( (temp_val & 1) );

        // Decrement
        temp_val >>= 1;

    }

    // Check size
    if( (int)output.size() <= 0 ){
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
 * @brief Check if Permutation
*/
template <typename LISTTYPE>
bool Is_Permutation( LISTTYPE list1,
                     LISTTYPE list2 )
{
    // Check sizes
    if( list1.size() != list2.size() ){
        return false;
    }

    // Sort both lists
    return std::is_permutation( list1.begin(),
                                list1.end(),
                                list2.begin() );
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
    for( int i=0; i<((int)value.size()/2); i++ )
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
    std::vector<bool> histogram(value.size(),false);

    // Error check
    if( (int)value.size() > 9 ){
        return false;
    }

    // Iterate over string
    for( int i=0; i<(int)value.size(); i++ ){
        if( value[i] < '1' || value[i] > '9' ){ return false;}
        histogram[value[i] - '1'] = true;
    }

    // Check if any false
    for( int i=0; i<(int)value.size(); i++ ){
        if( histogram[i] == false ){ return false; }
    }
    return true;
}

/**
 * @brief GCD
*/
template <typename DataType>
DataType GCD( DataType a,
              DataType b )
{
    while( a != 0 && b != 0 ){
        if( a > b ){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }

    if( a > 0 ) return a;
        return b;
}

/**
 * @brief Euler Totient Function
*/
template <typename DataType>
DataType Euler_Totient( DataType const& n )
{
    // Iterate 
    DataType t=0;
    for( DataType i=1; i<n; i++ ){
        if( GCD(i,n) == 1 ){
            t++;
        }
    }
    return t;
}

/**
 * @brief Euler Totient Function
*/
template <typename DataType>
DataType Euler_Totient( DataType const& n,
                        Primes<DataType> const& sieve )
{
    // Dummy Condition
    if( n == 1 ){ return 1; }
    if( n < 1 ){ return 0; }

    // Lehmer's Conjecture
    if( sieve.is_prime(n) )
    {
        return (n-1);
    }

    // Iterate 
    DataType t=n;
    for( DataType i=2; i<=n/2; i++ ){
        if( n % i == 0 &&
            sieve.is_prime(i) )
        {
            t *= (1 - (1.0 / i));
        }
    }
    return t;
}

#endif
