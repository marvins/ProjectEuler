/**
 * @file    euler048.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standrad Libraries
#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

// Set the range
int range = 12;

/**
 * @brief Reset the array values
*/
void Reset_Array( vector<int64_t>&  value,  
                  int const&        s )
{
    // Start setting value
    value[0] = s;
    for(int i=1; i<(int)value.size(); i++ ){
        value[i] = 0;
    }
}


/**
 * @brief Calculate Power Values
*/
void Calc_Power(  vector<int64_t>& value,
                  int const&       scalar )
{
    // Iterate over range
    for(int i=1;i<scalar;i++)
    {
        value[0] *= scalar;
        for(int j=1;j<range;j++)
        {
            value[j] *= scalar;
            if(value[j-1]>=10)
            {
                value[j] += value[j-1]/10;
                value[j-1]= value[j-1]%10;
            }
        }
    } 
}


/**
 * @brief Add Arrays
*/
void Add_Array( vector<int64_t>&        value,
                vector<int64_t> const&  array)
{
    for(int i=0;i<range;i++)
    {
        value[i] += array[i];
        if(i!=0)
        {
            if(value[i-1]>=10)
            {
                value[i] += value[i-1]/10;
                value[i-1]= value[i-1]%10;
            }
        }
    }
}


/**
 * @brief Print the array
*/
void Print(vector<int64_t>const& value )
{    
    for(int i=9;i>=0;i--)
        cout << value[i];
    cout << endl;
}


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Create the two arrays
    vector<int64_t>  value(range);
    vector<int64_t>  total_sum(range);

    // Start processing
    Reset_Array( total_sum, 1);

    // Start computing
    for(int i=2;i<=1000;i++)
    {
        // Reset the array values
        Reset_Array( value,i);

        // Cacluate the power of the value
        Calc_Power( value,i);

        // Add the power to the current sum
        Add_Array( total_sum, value);
    }

    // Print the value
    Print( total_sum);
    
    // Exit Program
    return 0;
}

