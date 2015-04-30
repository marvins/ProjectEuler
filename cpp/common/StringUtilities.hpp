/**
 *  Common String Utilities
 */
#ifndef __UTILS_STRING_UTILITIES_HPP__
#define __UTILS_STRING_UTILITIES_HPP__

#include <sstream>
#include <string>
#include <vector>

/**
 *  @brief Convert a string to a number
 */
template <typename TP>
TP str2num( std::string const& value ){
    
    std::stringstream sin;
    TP result;
    sin << value;
    sin >> result;
    return result;
}

/**
 * @brief Convert a String to a Number List
*/
std::vector<int> str2num_array( std::string const& data )
{
    // Output 
    std::vector<int> output;

    // Iterate over output
    for( int i=0; i<data.size(); i++ ){

        // Convert to string
        output.push_back(data[i] - '0');
    }

    // return data
    return output;
}


/**
 *  @brief Convert a number to a string
 */
template <typename TP>
std::string num2str( TP const& value ){

    std::stringstream sin;
    sin << value;
    return sin.str();
}

/**
 * @brief Check if a number is a palindrome
 */
bool is_palindrome( const std::string& number ){
    
    // Iterate over the number
    for( int i=0; i<(number.size()/2); i++ ){
        if( number[i] != number[number.size()-i-1] ){ 
            return false;
        }
    }
    return true;
}

#endif
