/**
 * @file    euler019.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Check if Sunday
*/
bool Is_Sunday( const int& year,
                const int& month )
{
    // via: http://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
    int d = 1;
    int m = (month-2) % 12;
    int y = year;
    if( month > 10 ){
        y -= 1;
    }
    int c = (y - (y % 100)) / 100;
    y = y%100;
    
    // Result
    int result = (d + (int)std::floor(2.6 * m - 0.2) + y + (int)std::floor(y/4) + (int)std::floor(c/4) - 2*c) % 7;
    
    if( result == 0 ){
        return true;
    }
    return false;
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Sum
    int sum = 0;

    // Iterate over year range
    for( int year=1901; year<2000; year++ )
    {

        // Iterate over month
        for( int month=1; month<=12; month++)
        {
            
            // Check if the day is a Sunday
            if( Is_Sunday( year, month ) == true )
            {
                sum++;
            }
        }
    }

    // Print Result
    std::cout << sum << std::endl;

    // Exit
    return 0;
}


