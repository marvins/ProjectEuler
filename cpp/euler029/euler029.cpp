/**
 * @file    euler029.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>


// Common Libraries
#include "../common/BigIntegerLibrary.hh"

using namespace std;


/** 
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // List of powers
    std::vector<BigInteger> power_list;

    // Start iterating from min to max, a->b
    int min_a = 2;
    int min_b = 2;
    int max_a = 100;
    int max_b = 100;
    
    for( int a=min_a; a<= max_a; a++ ){
    for( int b=min_b; b<= max_b; b++ ){
        power_list.push_back( power( a, b) );
    }}
    std::cout << "Non Unique: " << power_list.size() << std::endl;

    
    // Sort the list
    sort( power_list.begin(), 
          power_list.end() );
    
    // Strip out non-unique elements
    std::vector<BigInteger>::iterator it;
    it = unique( power_list.begin(),
                 power_list.end() );
    
    // Resize
    power_list.resize( std::distance( power_list.begin(), it ));

    // Print size
    std::cout << power_list.size() << std::endl;

    // Exit 
    return 0;
}


