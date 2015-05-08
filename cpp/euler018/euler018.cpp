/**
 * @file    euler018.cpp
 * @author  Marvin Smith
 * @date    4/29/2015
*/
#include <cinttypes>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Load the data
*/
std::vector<std::vector<int>> Parse_Data( std::string const& filename )
{
    // Create output data
    std::vector<std::vector<int>> output;
    std::vector<int> row;
    int value;

    // Open file
    std::ifstream fin;
    fin.open(filename.c_str());

    // Load into array
    fin >> value;

    while( !fin.eof() ){

        // Add to the current row
        row.push_back(value);
        
        // If we have filled the row
        if( (int)row.size() == (int)(output.size()+1)){
            output.push_back(row);
            row.clear();
        }

        fin >> value;
    }

    // Close the file
    fin.close();

    // return the data
    return output;
}


/** 
 * @brief Main Function
*/
int main(int argc, char* argv[])
{
    // Check input arguments
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <pathname>" << std::endl;
        return -1;
    }

    // Get the filename
    std::string filename = argv[1]; 

    // Parse the data
    std::vector<std::vector<int>> triangle = Parse_Data( filename );

    // Start backwards
    for( int row=triangle.size()-1; row> 0; row-- ){
        
        // Iterate over each column pair
        for( int col=0; col<(int)triangle[row].size()-1; col++ ){
            if( triangle[row][col] > triangle[row][col+1] ){
               triangle[row-1][col] += triangle[row][col]; 
            }
            else{
               triangle[row-1][col] += triangle[row][col+1]; 
            }
        }
    }

    // Print result
    std::cout << triangle[0][0] << std::endl;

    // return
    return 0;
}
