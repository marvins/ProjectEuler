/**
 * @file    euler032.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <set>
#include <vector>


// Common Libraries
#include "../common/Permutation_Engine.hpp"
#include "../common/StringUtilities.hpp"


using namespace std;

/**
 * @brief Check if values are pandigital
*/
bool Is_Pandigital( const int64_t&  value01,
                    const int64_t&  value02,
                    const int64_t&  value03 )
{
    // Convert all to strings
    std::string val_str_01 = num2str( value01 );
    std::string val_str_02 = num2str( value02 );
    std::string val_str_03 = num2str( value03 );
    
    // Check the size
    int val_size = val_str_01.size() + val_str_02.size() + val_str_03.size();
    if( val_size != 9 ){
        return false;
    }

    // Create histogram
    std::vector<bool> histogram(10, false);
    
    // Check each value
    for( int i=0; i<(int)val_str_01.size(); i++ )
        histogram[val_str_01[i]-'0'] = true;
    for( int i=0; i<(int)val_str_02.size(); i++ )
        histogram[val_str_02[i]-'0'] = true;
    for( int i=0; i<(int)val_str_03.size(); i++ )
        histogram[val_str_03[i]-'0'] = true;

    // Check if there are any false values
    for( int i=1; i<(int)histogram.size(); i++ )
        if( histogram[i] == false )
            return false;

    return true;
}


/**
 * @brief Main Functions
*/
int main( int argc, char* argv[] )
{
    // Sum value
    int64_t sum = 0;
    int64_t max_a = 2000;
    int64_t max_b = 2000;
    int64_t product;
    std::set<int32_t> dictionary;

    // Iterate over value range
    for( int64_t a=0; a<max_a; a++ )
    for( int64_t b=0; b<max_b; b++ ){
       
        // Set the product
        product = a * b;

        // Check if pandigital
        if( Is_Pandigital( a, b, product) == true ){
            
            // Check if the sum as been posted to the dictionary
            if( dictionary.find(product) == dictionary.end() ){
                dictionary.insert(product);
                sum += product;
            }
        }
    }

    // Print the sum
    std::cout << sum << std::endl;

    // Exit Program
    return 0;
}

