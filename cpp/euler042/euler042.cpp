/**
 * @file    euler042.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/**
 * @brief Check if a number is a triangle number
*/
bool Is_Triangle_Number( const int64_t& value ){

    // Compute a triangle sum
    int64_t triangle_sum = 1;
    int64_t counter = 2;
    while( value >= triangle_sum ){
    
        // Check exit condition
        if( triangle_sum == value ){ 
            return true; 
        }
        
        // Compute the next triangle
        triangle_sum = ( counter * (counter+1) )/2;

        // Increment Counter
        counter++;
    }
    
    return false;
}

/**
 * @brief Check if the words is a triangle number
*/
bool Is_Triangle_Word( const std::string& word ){

    // Convert word to sum value
    int64_t  sum = 0;
    for( int i=0; i<word.size(); i++ ){
        sum += word[i] - 'A' + 1;
    }

    // Check if the word is triangle
    if( Is_Triangle_Number( sum ) == true ){
        return false;
    }

    return true;
}

/**
 * @brief Load Word File
 */
std::vector<std::string> Load_Word_File( const std::string& filename )
{
    // Create our output list
    std::vector<std::string> output;
    
    // Misc variable
    char buffer[256];

    // Open the filename
    std::ifstream fin;
    fin.open(filename.c_str());

    // Start fetching data
    while( fin.getline( buffer, 256, ',') ){
        
        // Add to buffer
        output.push_back( String_Strip(std::string(buffer), ",\""));

    }


    // Close the file
    fin.close();

    // return the output
    return output;

}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    
    // Check for filename
    if( argc < 2 ){
        std::cerr << "error: Need the words.txt file requied from Project Euler." << std::endl;
        std::cerr << "usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // Otherwise, set the filename
    std::string filename = argv[1];

    // Load the words
    std::vector<std::string> words =  Load_Word_File( filename );
    
    // Check if each word is a triangle number
    std::vector<std::string>::iterator it;
    it = std::remove_if( words.begin(), words.end(), Is_Triangle_Word);
    words.resize( std::distance( words.begin(), it ));

    // Print Result
    std::cout << words.size() << std::endl;

    // Exit Program
    return 0;
}

