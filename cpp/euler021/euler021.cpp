/**
 * @file    euler021.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;


/**
 * @brief Compute the sum of divisors
 */
int64_t sum( int64_t const& value )
{
    // Compute divisors, summing results
    int sum = 0;
  
    for(int i=2; i<=(value/2) ;i++)
    {
        if(value % i==0)
            sum += i;
    }
    return sum+1;
}


/**
 * @brief Main Function
 */
int main(int argc,char* argv[])
{
    // Define the max value
    const int64_t max_value = 10000;

    // Compute list of all sums for the range of values
    std::vector<int64_t> sum_divisors( max_value + 1);

    // Iterate over range
    for(int i=2; i<= sum_divisors.size(); i++)
      sum_divisors[i] = sum(i);
    
    // Compare values
    int64_t result_sum = 0;
    for( int i=2; i<= sum_divisors.size(); i++)
    {
        // Check if the amicable values are the same
      if( i == sum_divisors[sum_divisors[i]] && sum_divisors[i] !=0 && i != sum_divisors[i])
      {
            result_sum += i;
      }
    }
      
    cout << result_sum << endl;
    return 0;
}


