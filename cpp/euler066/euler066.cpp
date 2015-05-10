/**
 * @file    euler066.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
 * 
 * Reference: http://en.wikipedia.org/wiki/Pell%27s_equation#Fundamental_solution_via_continued_fractions
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>

// Common Libraries
#include "../common/BigIntegerLibrary.hh"


using namespace std;


/**
 * @brief Recursive Min Function
*/
BigInteger Search_Min_X( BigInteger const& D, 
                         BigInteger const& a0,
                         BigInteger const& m0,
                         BigInteger const& d0,
                         BigInteger const& num0,
                         BigInteger const& den0,
                         BigInteger const& num1,
                         BigInteger const& den1,
                         BigInteger const& count,
                         BigInteger const& max_count )
{

    // Check solution
    if( count == max_count ){
        return 0;
    }
    
    // Update M
    BigInteger m1 = d0 * a0 - m0;

    // Update D
    BigInteger d1 = (D - m1 * m1) / d0;

    // Update A
    BigInteger a1 = (BigInteger((int)std::sqrt(D.toLong())) + m1) / d1;

    // Update Numerator
    BigInteger num2 = a1 * num1 + num0;
    BigInteger den2 = a1 * den1 + den0;
    
    // Check numerator
    if( num2 * num2 - D * den2 * den2 == 1 ){
        return num2;
    }

    // Continue
    return Search_Min_X( D, 
                         a1, 
                         m1,
                         d1,
                         num1, 
                         den1, 
                         num2, 
                         den2, 
                         count+1, 
                         max_count );
}

/**
 * @brief Compute the Continued Fraction
*/
BigInteger Compute_Continued_Fraction( const BigInteger& D,
                                       const BigInteger& max_iterations )
{
    // A
    BigInteger a = BigInteger((int)std::sqrt(D.toLong()));

    // Numererator and Denominators
    BigInteger num0 = 1;
    BigInteger den0 = 0;

    BigInteger num1 = a;
    BigInteger den1 = 1;

    // Check Square Root
    if( num1 * num1 == D ){ 
        return 0; 
    }

    // Initial M, D
    BigInteger m = 0;
    BigInteger d = 1;

    // Start recursive search
    return Search_Min_X( D, a, 
                         m, d,
                         num0, den0, 
                         num1, den1, 
                         0, max_iterations );
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // min x
    BigInteger min_x;

    // Recursive controls
    BigInteger max_iterations = 100;

    // current max result of d
    BigInteger max_result = 0;
    BigInteger max_D = 0;

    // Iterate over the range of D
    for( int D=2; D <= 1000; D++ )
    {
        // Compute the continued fraction
        min_x = Compute_Continued_Fraction( D, max_iterations );
        
        // Check if the min_x computed is the latest max
        if( min_x > max_result ){
            max_result = min_x;
            max_D = D;
        }

    }

    // Print Result
    std::cout << max_D << std::endl;

    // Exit Program
    return 0;
}

