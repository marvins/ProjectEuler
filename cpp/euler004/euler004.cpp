/**
 * @file    euler004.cpp
 * @author  Marvin Smith
 * @date    4/28/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <sstream>
#include <string>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Product
    int64_t product;
    std::string product_str;
    int64_t largest_palindrome = 0;
    
    // Multiply two sets of 3 digit numbers
    for( int i=0; i<999; i++ ){
    for( int j=0; j<999; j++ ){
        
        // Compute Product
        product = i * j;

        // Convert to string
        product_str = num2str(product);
    
        // Check if palindrome
        if( is_palindrome( product_str ) == true ){
            
            // Check if larger
            if( largest_palindrome < product ){
                largest_palindrome = product;
            }
        }

    }}

    // Print the result
    std::cout << largest_palindrome << std::endl;

    // return status
    return 0;
}

