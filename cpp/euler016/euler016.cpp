/**
 * @file    euler016.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Array List
    std::vector<int> array;
    int64_t sum = 0;
    array.push_back(2); 
    
    // Iterate 
    for(int i=0;i<500;i++)
        array.push_back(0);

    // Iterate over set of numbers
    for( int i=1; i<1000; i++)
    {
        // Multiply by 2
        array[0] *= 2;

        // Iterate over values
        for( int j=1; j<(int)array.size(); j++)
        {
            // power the array
            array[j] *= 2;
            if(array[j-1]>=10)
            {
                array[j] += array[j-1]/10;
                array[j-1] = array[j-1]%10;
            }
        }    
    }

    // Sum the values
    for(int i=0; i<(int)array.size(); i++)
    {
        sum += array[i];
    }

    cout << sum << endl;

    return 0;
}

