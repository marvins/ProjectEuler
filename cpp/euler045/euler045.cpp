/**
 * @file    euler045.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <cstdlib>
#include <deque>
#include <iostream>

// Enums
enum class NumberType{
    TRIANGLE,
    PENTAGONAL,
    HEXAGONAL,
}; // End of NumberType Enum


/**
 * @brief Triangle Number
*/
int64_t Triangle( const int64_t& n ){
    return (n * (n+1)/2);
}


/**
 * @brief Pentagonal Number
*/
int64_t Pentagonal( int64_t const& value ){
    return (value * ( 3 * value - 1)/2);
}


/**
 * @brief Hexagonal Number
*/
int64_t Hexagonal( int64_t const& value ){
    return (value * ( 2 * value - 1 ));
}


/**
 * @brief Generate the List
*/
std::deque<int64_t> Generate_List( const int64_t& max_number, 
                                   const NumberType& number_type )
{
    // Create output
    std::deque<int64_t> output;

    // Iterate over list
    for( int64_t i=1; i<max_number; i++ ){

        // Check type
        if( number_type == NumberType::TRIANGLE ){
            output.push_back(Triangle(i));
        }
        else if( number_type == NumberType::PENTAGONAL ){
            output.push_back(Pentagonal(i));
        }
        else{
            output.push_back(Hexagonal(i));
        }
    }

    // return output
    return output;
}

/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Define our max triangle, pentagonal, and hexagonal numbers
    const int64_t max_triangle_number   = 100000;
    const int64_t max_pentagonal_number = 100000;
    const int64_t max_hexagonal_number  = 100000;

    // Generate the lists
    std::deque<int64_t> triangle_list   = Generate_List( max_triangle_number,   NumberType::TRIANGLE );
    std::deque<int64_t> pentagonal_list = Generate_List( max_pentagonal_number, NumberType::PENTAGONAL );
    std::deque<int64_t> hexagonal_list  = Generate_List( max_hexagonal_number,  NumberType::HEXAGONAL );
    

    // Start an iterative search routine
    while( triangle_list.size() > 0 && 
           pentagonal_list.size() > 0 && 
           hexagonal_list.size() > 0 )
    {

        // Check if all list have the same first valaue
        if( triangle_list.front() == pentagonal_list.front() && 
            triangle_list.front() == hexagonal_list.front() )
        {
            // Skip first two expected
            if( triangle_list.front() != 1 &&
                triangle_list.front() != 40755 )
            {
                std::cout << triangle_list.front() << std::endl;
                break;
            }

            // Pop all sets
            triangle_list.pop_front();
            pentagonal_list.pop_front();
            hexagonal_list.pop_front();
        }

        // Otherwise, pop the lowest item
        else{
           
            // Check if triangle is lowest
            if( triangle_list.front() < pentagonal_list.front() &&
                triangle_list.front() < hexagonal_list.front() )
            {
                triangle_list.pop_front();
            }
            // Check if pentagonal is lowest
            else if( pentagonal_list.front() < triangle_list.front() && 
                     pentagonal_list.front() < hexagonal_list.front() )
            {
                pentagonal_list.pop_front();
            }
            // Check if hexagonal is lowest
            else if( hexagonal_list.front() < triangle_list.front() && 
                     hexagonal_list.front() < pentagonal_list.front() )
            {
                hexagonal_list.pop_front();
            }
            // Check if first two are equal and smaller
            else if( triangle_list.front() == pentagonal_list.front() &&
                     triangle_list.front() <  hexagonal_list.front() )
            {
                triangle_list.pop_front();
            }
            // Check if second two are equal and smaller
            else if( pentagonal_list.front() == hexagonal_list.front() && 
                     pentagonal_list.front() <  triangle_list.front() )
            {
                pentagonal_list.pop_front();
            }
            // Check if first and last are equal and smaller
            else if( triangle_list.front() == hexagonal_list.front() && 
                     triangle_list.front() <  pentagonal_list.front() )
            {
                triangle_list.pop_front();
            }

            // Otherwise, some error
            else{
                std::cerr << "error: Unknown condition" << std::endl;
                std::exit(-1);
            }

        }
    
    }

    // Exit Program
    return 0;
}

