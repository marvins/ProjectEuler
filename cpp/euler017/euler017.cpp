/**
 * @file    euler017.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// List of characters per word
int ones[10] = {0,3,3,5,4,4,3,5,5,4};
int tens[10] = {0,3,6,6,5,5,5,7,6,6};
int teens[10]= {3,6,6,8,8,7,7,9,8,8};

int twenty  = 6;
int hundred = 7;
int thousand = 8;

/**
 * @brief Count the digits per value
*/
int count_digits( int const& m )
{
    // Sum
    int64_t result = 0;

    // Get the singles
    int64_t b1   = m % 10;
    int64_t b10  = ((m%100) - b1) / 10;
    int64_t b100 = ((m % 1000) - (b10 * 10) - b1) / 100;

    // Check if above 99
    if( b100 != 0 ){
        
        // Check the "and" condition
        if( b10 > 0 || b1 > 0 ){
            result += 3;
        }
        
        // Add the "three-hundred" component
        result += ones[b100] + hundred;

    }

    // Check if teens or twenties
    if( b10 == 0 ){
       result += ones[b1]; 
    }
    else if( b10 == 1 ){
        result += teens[b1];
    }
    else
        result += tens[b10] + ones[b1];

    return result;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Variables
    int64_t total=0;

    // Iterate to 1000
    for(int i=1; i<=1000; i++)
    {
        total += count_digits(i);
    }

    // Add 1000
    total += ones[1] + thousand;

    // Print
    cout << total << endl;
    
    return 0;
}

