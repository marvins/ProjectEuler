/**
 * @brief   euler043.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <vector>

// Common Libraries
#include "../common/Permutation_Engine.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @class SubStringFunctor
 */
class SubStringFunctor{

    public:

        /**
         * @brief Function operator
        */
        bool operator()( const std::vector<int>& str )const
        {
            // Split string d2,d3,d4
            int substr1 = str[1]*100 + str[2]*10 + str[3];
            int substr2 = str[2]*100 + str[3]*10 + str[4];
            int substr3 = str[3]*100 + str[4]*10 + str[5];
            int substr4 = str[4]*100 + str[5]*10 + str[6];
            int substr5 = str[5]*100 + str[6]*10 + str[7];
            int substr6 = str[6]*100 + str[7]*10 + str[8];
            int substr7 = str[7]*100 + str[8]*10 + str[9];

            if( substr1 %  2 != 0 ){ return false; }
            if( substr2 %  3 != 0 ){ return false; }
            if( substr3 %  5 != 0 ){ return false; }
            if( substr4 %  7 != 0 ){ return false; }
            if( substr5 % 11 != 0 ){ return false; }
            if( substr6 % 13 != 0 ){ return false; }
            if( substr7 % 17 != 0 ){ return false; }

            return true;
        }

}; // End of SubStringFunctor

/**
 * @brief Main Function
*/
int main(int argc , char *argv[])
{
    // Sum
    int64_t sum = 0;
  
    //  Number of iterations
    int count = 10;

    // Create our fuctor
    SubStringFunctor Euler43;
    vector<int> list;
    vector<vector<int> > results;

    // Add list element 
    for(int i=0;i<count;i++)
        list.push_back(i);

    // Run permutations
    permute_pandigital(list, results, 0, count, false, Euler43);

    for(int i=0;i<results.size();i++)
        for(int j=count-1;j>=0;j--)
            sum += results[i][j]*pow(10,9-j);

    cout << sum << endl;

    return 0;
}

