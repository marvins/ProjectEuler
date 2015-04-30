/**
 * @file    euler009.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
 */
#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief Check if Pythagorean Triplet.
*/
bool is_pythagorean_triplet( const int& a,
                             const int& b,
                             const int& c )
{
    if( (a*a + b*b) == (c*c) ){
        return true;
    }
    return false;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Current values
    int64_t sum;

    // Iterate over three sets of values
    for( int i=1; i<1000; i++ ){
    for( int j=1; j<1000; j++ ){
    for( int k=1; k<1000; k++ ){

        // Compute the sum 
        sum = i + j + k;
        
        // Check if Pythagorean Triplet
        if( is_pythagorean_triplet( i, j, k) != true ){
            continue;
        }

        // Check if sum
        if( sum == 1000 ){
            std::cout << (i*j*k) << std::endl;
            return 0;
        }

    }}}
    

    // Return success
    return 0;
}

