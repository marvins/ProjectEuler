/** 
 * @file    euler068.cpp
 * @author  Marvin Smith
 * @date    5/9/2015
*/

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Convert a number list to a solution
 */
std::string Number_List_To_String( std::vector<int> const& solution )
{
    std::string output;
    for( int i=0; i<solution.size(); i++ ){
        output.push_back( solution[i] );
    }
    return output;
}

std::string String_To_Solution( const std::string& solution )
{
    std::string output;
    for( int i=0; i<solution.size(); i++ )
        output += num2str( solution[i]-'a');

    return output;
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    
    // Create a list from 1 - 10
    std::vector<int> ngon_values;
    for( int i=1; i<= 10; i++ )
        ngon_values.push_back(i);
    
    // Sums
    std::vector<int> sums(5,0);

    // Current best values
    std::vector<std::string> solution_list;
    std::string best_value, str_value;

    // Iterate over permutations
    do{

        // Make sure all 3-value sets are the same sum
        sums[0] = ngon_values[0] + ngon_values[1] + ngon_values[2];
        sums[1] = ngon_values[3] + ngon_values[2] + ngon_values[4];
        sums[2] = ngon_values[5] + ngon_values[4] + ngon_values[6];
        sums[3] = ngon_values[7] + ngon_values[6] + ngon_values[8];
        sums[4] = ngon_values[9] + ngon_values[8] + ngon_values[1];

        if( sums[0] == sums[1] &&
            sums[0] == sums[2] && 
            sums[0] == sums[3] && 
            sums[0] == sums[4] )
        {
            // Check if outer is lowest
            if( ngon_values[0] > ngon_values[3] ||
                ngon_values[0] > ngon_values[5] || 
                ngon_values[0] > ngon_values[7] || 
                ngon_values[0] > ngon_values[9] )
            {
                continue;
            }

            // Check the values
            str_value.clear();
            str_value.push_back( ngon_values[0] + 'a' );
            str_value.push_back( ngon_values[1] + 'a' );
            str_value.push_back( ngon_values[2] + 'a' );
            str_value.push_back( ngon_values[3] + 'a' );
            str_value.push_back( ngon_values[2] + 'a' );
            str_value.push_back( ngon_values[4] + 'a' );
            str_value.push_back( ngon_values[5] + 'a' );
            str_value.push_back( ngon_values[4] + 'a' );
            str_value.push_back( ngon_values[6] + 'a' );
            str_value.push_back( ngon_values[7] + 'a' );
            str_value.push_back( ngon_values[6] + 'a' );
            str_value.push_back( ngon_values[8] + 'a' );
            str_value.push_back( ngon_values[9] + 'a' );
            str_value.push_back( ngon_values[8] + 'a' );
            str_value.push_back( ngon_values[1] + 'a' );
            solution_list.push_back( str_value );
            
        }
       

    } while( std::next_permutation( ngon_values.begin(),
                                    ngon_values.end() ));

    // sort
    std::sort( solution_list.begin(), solution_list.end() );
    
    // Convert to string with numbers
    best_value = String_To_Solution( solution_list.back() );

    // Print the best result
    std::cout << best_value << std::endl;


    // Exit Program
    return 0;
}

