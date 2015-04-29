/** 
 * @file    euler006.cpp
 * @author  Marvin Smith
 * @date    4/28/2015
*/
#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Sum and Products
    int64_t  sum = 0;
    int64_t  sum_sq = 0;

    //  Iterate from 1 to 100
    for( int i=1; i<=100; i++ ){
        
        // Sum the square
        sum_sq += (i*i);

        // Sum the value
        sum += i;

    }

    // Square and diff
    int64_t result = (sum * sum) - sum_sq;

    // print
    std::cout << result << std::endl;

    // Return 
    return 0;
}

