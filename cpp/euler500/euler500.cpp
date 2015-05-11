/**
 * @file    euler500.cpp
 * @author  Marvin Smith
 * @date    5/10/2015
 *
 * Notes: http://mathschallenge.net/index.php?section=faq&ref=number/number_of_divisors
*/

// C++ Standard Libraries
#include <cinttypes>

// Boost Libraries
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;


/** 
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Create a huge integer
    cpp_int large_number = 2;
    cpp_int result = pow(large_number,500500);

    // Exit Program
    return 0;
}

