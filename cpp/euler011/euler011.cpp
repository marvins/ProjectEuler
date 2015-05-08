// C++ Standard Libraries
#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;

/**
 * Divisor Count
*/
int divisor_count(long long);


/**
 * Main Program
*/
int main()
{
  
    // Variables
    long long value = 1;
    long long prev  = 0;
    int divisors = 1;
  
    // Get the divisor count
    divisors = divisor_count(value);
  
    // Iterate
    while(divisors < 500)
    {
        prev += value++;
        while(prev%13!=0){
            prev += value++;
            while(prev%11!=0){
                prev += value++;
                while(prev%7!=0){
                    prev += value++;
                    while(prev%5!=0){
                        prev += value++;
                        while(prev%3!=0){
                            prev += value++;
                            while(prev%2!=0){
                                prev += value++;
                            }
                        }
                    }
                }
            }
        }
    
    
        divisors = divisor_count(prev);
   
  }
  cout << endl;
  cout << prev << endl;
  return 0;
}

/**
 * Get the Number of divisors
*/
int divisor_count(long long value)
{
  int count = 0;
  long long lower_limit = value/2+1;

  for(long long i = 2; i < lower_limit; i++ )
    if(( value % i ) == 0 )
      count++;
  return count+1;
}
