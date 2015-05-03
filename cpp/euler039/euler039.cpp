/**
 * @file    euler039.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
 *
 * @note{ 
 *     My solution is to compute the max and min values of two sides. Then brute force it.
 *
 *     Given a^2 + b^2 = c^2, and max perimeter = 1000.
 *     
 *     Then, a + b + c = 1000
 *     so merging, we get...
 *     
 *        a^2 + b^2 = (1000 - a - b)^2
 *   ->   a^2 + b^2 = a^2 + b^2 + 2ab - 2000a - 2000b + 1000000
 *   ->   0 = 2ab - 2000a - 2000b + 1000000
 *   ->   f(a) = b = (1000(a - 500)) / (a - 1000)
 *
 *  Finally, the limit of f(a) as a -> 0 = 500 so that is our max.
 * }
*/

// C++ Standard Libraries
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    //  Determine our max P value
    int16_t max_perimeter = 1000;

    // Create output total list
    std::vector<int32_t> p_totals(max_perimeter+1, 0);

    // Iterate over possible values of sides
    int32_t max_side = 500;

    // Iterate over sides
    int32_t p;
    double c;
    const double eps = 0.0001;
    for( int a=1; a<max_side; a++ )
    for( int b=1; b<max_side; b++ )
    {
        // Compute hypotenuse
        c = std::sqrt( a*a + b*b );

        // Check perimeter
        p = a + b + c;

        // Update total list
        if( std::fabs(c - std::floor(c)) < eps && p <= 1000 ){
            p_totals[p]++;
        }
    }

    // Sum the totals
    int32_t max_count = 0;
    int32_t max_p;
    for(int i=1; i<p_totals.size(); i++){
        
        if( p_totals[i] > max_count ){
            max_count = p_totals[i];
            max_p     = i;
        }
    }

    // Print Result
    std::cout << max_p << std::endl;

    // Exit Program
    return 0;
}

