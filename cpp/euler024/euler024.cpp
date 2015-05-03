/**
 * @file    euler024.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Print the vector array
*/
void Print( const vector<int>& a )
{

  for(int i=0; i<a.size(); i++)
    cout << a[i];
  cout << endl;
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Construct array
    vector<int> array(10);
    int count = 1000000;;


    // Construct the array
    for(int i=0; i<array.size(); i++)
        array[i] = i;

    // Iterate through permutations
    for(int i=0; i< count-1; i++)
        next_permutation( array.begin(), array.end() );

    // Print the result
    Print( array );

    return 0;
}
