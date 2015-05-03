/**
 * @file    euler038.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
 */

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>

// Common Libraries
#include "../common/Math_Utilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    
    // Max N Value
    const int64_t max_n = 10;

    // Max Integer
    const int64_t max_integer = 10000;

    // Temp Values
    int64_t product;
    std::string concatenated;
    int64_t max_product = 0;
    int64_t temp_product;
    int64_t n;

    // Iterate over integers
    for( int64_t i=1; i<max_integer; i++ ){
        
        // Clear string
        concatenated = "";

        // Iterate over N range
        for( n=1; n <= max_n; n++ ){
            
            // Compute product
            product = i * n;

            // Convert product to string and concatenate
            concatenated += num2str(product);

            // Check length
            if( concatenated.size() >= 9 ){
                break;
            }
        }

        // Check length
        if( concatenated.size() > 9 ){
            continue;
        }

        // Otherwise, check pandigital
        if( Is_Pandigital( concatenated ) == true ){
            
            // Convert to integer
            temp_product = str2num<int64_t>(concatenated);
            if( temp_product > max_product ){
                max_product = temp_product;
            }
        }

    }

    // Print result
    std::cout << max_product << std::endl;

    // Exit Program
    return 0;
}


