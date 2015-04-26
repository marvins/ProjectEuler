/**
 * @file    euler002.cpp
 * @author  Marvin Smith
 * @date    4/25/2015
*/
#include <iostream>

/**
 * Fibonacci Number
 */
int Fibonacci( int const& F )
{
    // Handle Exit Conditions
    if( F < 2 ){ return F; }

    // Otherwise
    return Fibonacci( F-1 ) + Fibonacci( F-2 );
}


/**
 * Find Max Fibonacci
 */
int Find_Max_Fibonacci( const int& max_value )
{
    // Start iteration
    int counter = 2;
    int Fmax = counter;
    while( true ){

        // Update FMax
        Fmax = counter-1;

        // Check counter
        if( Fibonacci(counter++) > max_value )
        {
            return Fmax;
        }

        // Error Check
        if( counter > 1000000 ){
            return -1;
        }
    }
    return -1;
}

/**
 * Main Function
 */
int main( int argc, char* argv[] )
{

    // Compute Max Euler Value for Given Input
    const int max_value = 4000000;
    const int Fmax = Find_Max_Fibonacci( max_value );

    // Compute Sum of Even Fibonacci Numbers
    int result = 0;
    int value;
    for( int i=0; i<=Fmax; i++ ){
        value = Fibonacci(i);
        if( value % 2 == 0 ){
            result += value;
        }
    }

    // Print Result
    std::cout << result << std::endl;

    return 0;
}


