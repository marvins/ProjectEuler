/**
 * @file    euler013.cpp
 * @author  Marvin Smith
 * @date    4/28/2015
*/
// C++ Standard Libraries
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Main Function
 */
int main ( int argc, char* argv[] ) 
{
    // Get the file name
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <filename>" << std::endl;
    }

    std::string filename = argv[1];

    // Misc Variables
    double value = 0;
    double a;
  
    // Parse the file
    ifstream fin;
    fin.open(filename.c_str());
    
    for(int i=0;i<100;i++){
        fin >> a;
        value += a;
    }
    std::cout << std::fixed << value << std::endl;
  
    return 0;
}



