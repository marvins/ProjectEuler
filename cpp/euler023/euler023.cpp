#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/**
 * @brief Compute the sum of divisors
*/
int64_t sum_divisors( const int64_t& value )
{
    // Compute Sum
    int64_t sum = 0;
  
    // Iterate over range
    for( int64_t i=2; i<=(value/2); i++)
    {
        if(value % i == 0)
            sum += i;
    }

    return sum+1;

}

/**
 * @brief Main Function
*/
int main(int argc,char* argv[])
{
    // Define our max value
    const int64_t max_value = 28124;

    // Define the list of divisor sums
    vector<int64_t> divisor_sums;
    
    int64_t tally = 0;

    // Create flag list of abundant values
    std::vector<bool> abundant_list( max_value, false );

    // Iterate over values
    for(int64_t i=12; i<max_value; i++){
        
        if(i<sum_divisors(i))
            divisor_sums.push_back(i);
    }


    // Build the list of values which are a sum of two abundant values
    for(int64_t i=0; i<divisor_sums.size(); i++){
    for(int64_t j=0; j<divisor_sums.size(); j++){

        // Check if the sum is less than the max
        if( divisor_sums[i] + divisor_sums[j] < max_value)
            abundant_list[divisor_sums[i] + divisor_sums[j]]=true;
    }}

    // Compute output sum of values not a product
    for(int64_t i=0; i<max_value; i++)
        if(!abundant_list[i])
            tally += i;

    cout << tally << endl;
    return 0;
}


