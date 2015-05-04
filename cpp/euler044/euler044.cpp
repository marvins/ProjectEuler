/**
 * @file    euler044.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Library
#include <cinttypes>
#include <iostream>
#include <set>

using namespace std;

/**
 * @brief Pentagonal
*/
int64_t Pentagonal( const int64_t& value ){
    return (value * (3 * value - 1) )/2;
}

/**
 * @brief Build the Pentagonal Set
*/
std::set<int64_t>  Compute_Pentagonal_Set( const int64_t& max_value )
{

    // Construct output object
    std::set<int64_t> output;

    // Iterate over values
    for( int64_t i=1; i<max_value; i++ ){
        output.insert( Pentagonal( i ) );
    }

    // return 
    return output;
}


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Compute Max Petagonal Number
    int64_t max_pentagonal_number = 10000;

    // Build Big Number List
    std::set<int64_t> pentagonal_set = Compute_Pentagonal_Set( max_pentagonal_number );

    // Build two iterators
    std::set<int64_t>::iterator pit1 = pentagonal_set.begin();
    std::set<int64_t>::iterator pit2 = pentagonal_set.begin();

    // Iterate over each pair of pentagonal numbers
    int64_t sum, diff;
    int64_t min_dist = -1;
    for(pit1 = pentagonal_set.begin(); pit1 != pentagonal_set.end(); pit1++ ){
    for(pit2 = pit1; pit2 != pentagonal_set.end(); pit2++ ){
        
        // Skip if the iterators point to the same object
        if( pit1 == pit2 ){
            continue;
        }

        // Otherwise, check sum and difference
        sum  = (*pit2) + (*pit1);
        diff = (*pit2) - (*pit1);
        if( diff <= 0 ){ continue; }

        // Make sure both are pentagonal
        if( pentagonal_set.find(sum)  != pentagonal_set.end() &&
            pentagonal_set.find(diff) != pentagonal_set.end() )
        {
            // Compute distance
            if( min_dist == -1 ){ min_dist = diff; }
            min_dist = std::min( min_dist, diff );
        }

    }}
    
    // Print result
    std::cout << min_dist << std::endl;

    // Exit Program
    return 0;
}

