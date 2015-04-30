/**
 * @file    euler015.cpp
 * @author  Marvin Smith
 * @date    4/28/2015
*/
#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/** 
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Number of rows
    int rows = 20;

    // Create the table
    std::vector<std::vector<int64_t> > table(rows+1, std::vector<int64_t>(rows+1, 0));
    
    // Initialize the table
    for( int i=0; i<table.size(); i++ ){

        // Set to zero
        table[i][0] = 1;
        table[0][i] = 1;
    }

    // Solve the table
    for( int i=1; i<table.size(); i++ )
    for( int j=1; j<table[i].size(); j++ ){
        table[i][j] = table[i-1][j] + table[i][j-1];
    }

    // Return response
    std::cout << table[rows][rows] << std::endl;

    return 0;
}
