/**
 * @file    euler062.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
*/

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <set>
#include <string>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Misc Variables
    uint64_t cubic;
    std::string cubic_str, cubic_sorted;
    std::set<std::string> cubic_flag_set[5];
    std::vector<std::string> max_values(5);
    bool break_loop = false;

    // Define our computation range
    const uint64_t min_value = 1;
    const uint64_t max_value = 60000;
    
    // Start computing cubic values
    for( uint64_t i=min_value; i<max_value && break_loop != true; i++ ){

        // Compute the cubic
        cubic = (i*i*i);

        // convert to string
        cubic_str = num2str(cubic);
    
        // sort letters
        std::sort( cubic_str.begin(), cubic_str.end() );
        
        // add to set
        for( int j=0; j<5; j++ ){
            if( cubic_flag_set[j].find(cubic_str) == cubic_flag_set[j].end() )
            {
                cubic_flag_set[j].insert(cubic_str);
                if( max_values[j] == "" ){
                    max_values[j] = num2str(cubic);
                }
                
                if( j == 4 ){
                    cubic_sorted = cubic_str;
                    break_loop = true;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }

    // Iterate back over
    for( uint64_t i=min_value; i<max_value; i++ ){
        
        // Get the cubic string
        cubic_str = num2str(i*i*i);

        // Sort
        std::sort( cubic_str.begin(), cubic_str.end() );

        // Check
        if( cubic_str == cubic_sorted ){
            std::cout << (i*i*i) << std::endl;
            return 0;
        }
    }
        
    
    // Exit Program
    return 0;
}

