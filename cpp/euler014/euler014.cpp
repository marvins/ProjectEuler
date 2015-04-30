/**
 * @file    euler014.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief Count
*/
void count( int64_t& value , 
            int64_t& counter )
{
    // Increment the counter
    counter++;

    // If value is 1, finish recursion
    if( value == 1 )
        return;

    // If even, split
    else if( value%2 == 0 )
        value = value/2;
    
    // If odd, go higher
    else
        value = 3*value+1;
    
    // Continue
    count( value , counter );
}


/** 
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Variables
    int64_t value = 13;
    int64_t counter = 0;
    int64_t temp;
    int64_t max = 0;
    int64_t max_counter = 0;

    // Iterate over the chain
    for(int64_t i=4; i<1000000; i++)
    {
        temp = i;
        counter = 0;
        count(temp,counter);
     
        if(counter > max_counter){
            max_counter = counter;
            max = i;
        }
   }
   cout << max << endl;
   
   return 0;
}

