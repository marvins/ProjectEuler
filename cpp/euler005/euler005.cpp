/** 
 * @file    euler005.cpp
 * @author  Marvin Smith
 * @date    4/28/2015
*/
#include <iostream>

using namespace std;

/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Max Possible Value
    int64_t max_value = 9999999999;

    // Start counting
    int64_t value = 100;
    while( value < max_value ){

        // Iterate from 1 to 20
        bool valid = true;
        for( int i=2; i<=20; i++ ){
            if( value % i != 0 ){
                valid = false;
                break;
            }
        }

        // Check if valid
        if( valid == true ){
            std::cout << value << std::endl;
            return 0;
        }

        // Increment the value
        value++;

    }

    // return success
    return 0;
}

