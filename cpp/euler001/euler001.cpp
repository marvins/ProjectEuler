/**
 * @file    euler001.cpp
 * @author  Marvin Smith
 * @date    4/25/2015
 */
#include <iostream>

/**
 * @brief Main Function
 */
int main( int argc, char* argv[] ){

    // Define our running sum
    int sum = 0;

    // Iterate from 3 to 999
    for( int i=3; i<=999; i++ ){
        
        // Check if divisible by 3 or 5
        if( i%3 == 0 || i%5 == 0 ){
            sum += i;
        }
    }

    // Print Result
    std::cout << sum << std::endl;
    
    // Exit 
    return 0;
}

