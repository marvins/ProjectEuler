/**
 *  @file    euler084.cpp
 *  @author  Marvin Smith
 *  @date    5/8/2015
 *
 *  I am bad at statistics, so I am going to take a stab at it
 *  manually.
 */

// C++ Standard Libraries
#include <array>
#include <cinttypes>
#include <iostream>

using namespace std;

/**
 * @enum Board
 */
enum class Board : int{
    GO   = 0  /**< Go, Collect $200*/,
    JAIL = 10 /**< Jail*/,
    G2J  = 30 /**< Go to Jail.*/,
}; // End of Board Enum


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{
    // Number of monopoly board locations
    const int8_t  number_locations = 40;

    // Number of die faces
    const int8_t max_die_face_count = 4;
    
    // Counts at each location
    std::array<int64_t,number_locations> board_visit_counters;
    board_visit_counters.fill(0);

    // Misc variables
    int current_position = (int)Board::GO;


    // Roll a whole bunch of times
    const int64_t  number_of_rolls = 1000000;
    int8_t die_roll_01;
    int8_t die_roll_02;
    int8_t double_roll_count = 0;


    // Start rolling
    for( int64_t roll=0; roll<=number_of_rolls; roll++ )
    {
        // Compute the dice rolls
        die_roll_01 = rand() % max_die_face_count + 1;
        die_roll_02 = rand() % max_die_face_count + 1;

        // Check for a matching pair
        if( die_roll_01 == die_roll_02 ){
            double_roll_count++;
        }
        

        // Update current position
        current_position = (current_position + die_roll_01 + die_roll_02) % number_locations;
        
        // Check for double roll
        if( double_roll_count == 3 ){
            current_position = (int)Board::JAIL;
            double_roll_count = 0;
        }
        
        // Check for landing on G2J
        if( current_position == (int)Board::G2J ){
            current_position = (int)Board::JAIL;
            double_roll_count = 0;
        }


    }

    // Exit Program
    return 0;
}


