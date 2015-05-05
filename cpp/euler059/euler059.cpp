/**
 * @file    euler059.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <deque>
#include <iostream>

using namespace std;


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Check arguments
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    // Get the filename
    std::string filename = argv[1];

    // Read the file
    std::string contents = 

