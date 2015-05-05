/**
 * @file    euler53.cpp
 * @author  Marvin Smith
 * @date    9/24/2013
 */

// C++ Standard Libraries
#include <iostream>

// Common Libraries
#include "../common/BigIntegerLibrary.hh"

using namespace std;

/**
 * @brief Combinatorics (n choose r)
*/
BigInteger nCr( const BigInteger& n, const BigInteger& r )
{
    // Compute divisor components
    BigInteger numerator   = factorial(n);
    BigInteger denominator = factorial(r)*factorial(n-r);

    return BigInteger(numerator/denominator);

}

/**
 *  Main Function
 */
int main( int argc, char* argv[] ){


    // iterate from 1 to 100 for n
    BigInteger result;
    int count = 0;
    for( size_t n=1; n<=100; n++ ){

        // for r, iterate from 0 to n
        for( size_t r=0; r<=n; r++ ){

            result = nCr( n, r);
            
            if( result > 1000000 )
                count++;
        }
    }

    cout << count << endl;
    
    
    return 0;

}

