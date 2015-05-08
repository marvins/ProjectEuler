/**
 * @file   euler61.cpp
 * @author Marvin Smith
 * @date   10/15/2013
 */
#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#include "../common/BigIntegerLibrary.hh"
#include "../common/StringUtilities.hpp"

using namespace std;

// Polygon Flag Values
std::bitset<10000> figurate_flag_set[6];


/**
 * @brief Check if cyclic
*/
bool Is_Cyclic( uint16_t const& value1,
                uint16_t const& value2 )
{
   return ((value1%100) == (value2/100)); 
}

/**
 * @brief Polygon of n given j
 */
int Pjn( int const& j, int const& n ){

    switch( j ){
        case 3:
            return (n*(n+1)/2);
        case 4:
            return (n*n);
        case 5:
            return (n*(3*n-1)/2);
        case 6:
            return (n*(2*n-1));
        case 7:
            return (n*(5*n-3)/2);
        case 8:
            return (n*(3*n-2));
        default:
            throw string("Error: Unknown value");
            return -1;
    }
    return -1;
}


bool Is_Polygonal( int const& poly, const uint16_t& value ){
    return (figurate_flag_set[poly][value] == 1);
}

bool Is_Polygonal( int const& poly, const std::array<uint16_t,6>& value ){
    for( int i=0; i<6; i++ ){ 
        if( Is_Polygonal( poly, value[i] ) == true ){
            return true;
        }
    }
    return false;
}

/**
 * @brief Is Polygon
*/
bool Is_Polygonal_Any( const uint16_t& value ){
    for( int i=0; i<6; i++ ){
        if( Is_Polygonal( i, value ) == true ){ return true; }
    }
    return false;
}


/**
 * @brief Compute a recursive solution
*/
void Compute_Solution( std::array<uint16_t,6>& data,
                       std::bitset<6>&         polys_set,
                       const int&              index,
                       int                     sum )
{

    // Flags
    bool is_polygonal;

    // Check if 6
    if( index == 6 ){

        // Check counter
        for( int i=0; i<6; i++ ){
            if( polys_set[i] != 1 ){ return; }
        }

        std::cout << sum << std::endl;
        std::exit(1);
        return;
    }

    // Iterate
    for( uint16_t i=1000; i<10000; i++ )
    {
        // At index = 5, we need to check with the first
        if( index == 5 ){
            if( (Is_Cyclic( data[index-1], i ) && Is_Cyclic( i, data[0])) == false ){
                continue;
            }
        }
        // Skip this test on the first index
        else if( index > 0 ){
            if( Is_Cyclic( data[index-1], i) == false ){
                continue;
            }
        }

        // Check figurate
        if( Is_Polygonal_Any(i) == false ){
            continue;
        }

        // Check duplicates
        for( int j=0; j<index; j++ ){
            if( i == data[j] ){ 
                continue; 
            }
        }

        // Set the data
        data[index] = i;

        // Proceed
        bool swap_flag = false;
        for( int j=0; j<6; j++ ){
            if( Is_Polygonal(j, i) == true && polys_set[j] == 0 ){
                polys_set[j] = 1;
                Compute_Solution( data, polys_set, index + 1, sum + i );
                polys_set[j] = 0;
            }
        }
    }
}


/**
 * Main Function
 */
int main( int argc, char* argv[] ){

    // Misc Variables
    int x, idx;
    
    // Initialize the flag sets
    for( int i=0; i<6; i++ ){
        figurate_flag_set[i] = 0;
    }
    
    // iterate through the list, building the sets
    for( size_t i=3; i<=8; i++ ){

        // counter
        x = 0;

        // add values
        while( true ){

            // compute number
            idx = Pjn(i,x);

            // Skip if below 1000
            if( idx < 1000 ){ 
                x++;
                continue; 
            }

            // if the value is greater than 4, break
            if( idx >= 10000 ){ break; }

            // Set flag
            figurate_flag_set[i-3][idx] = 1;
            
            // Increment count
            x++;
        }

    }

    // Call the compute method
    std::array<uint16_t,6> placeholder;
    std::bitset<6> polys_set = 0;
    Compute_Solution( placeholder, polys_set, 0, 0 );

    return 0;
}

