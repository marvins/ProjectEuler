/**
 * @file    euler033.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
 */

// C++ Standard Libraries
#include <iostream>
#include <stdio.h>

using namespace std;


/**
 * @brief Greatest Common Divisor
*/
int64_t gcd( int64_t const& a, 
             int64_t const& b )
{
    int64_t r;
    int64_t u, v;
    u = a;
    v = b;
    while( v != 0 ){
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Temp Values
    double a,b,c,d;

    // Products
    int64_t numerator = 1;
    int64_t denominator = 1;

    // Iterate through ranges
    for(int i=2;i<=9;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k=1;k<=9;k++)
            {
                a = j*10+k;
                b = k*10+i;
                c = j;
                d = i;
                if((a/b)==(c/d)){

                    // Multiply to product
                    numerator   *= a;
                    denominator *= b;
                }
            }
        }
    }


    // Reduce the fraction
    int64_t gcd_result = gcd( numerator, denominator );
    while( gcd_result != 1 ){
        numerator   /= gcd_result;
        denominator /= gcd_result;
        gcd_result = gcd( numerator, denominator );
    }
    
    // Print the result
    std::cout << denominator << std::endl;

    return 0;
}
