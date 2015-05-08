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
    for( int i=0; i<(int)data.size(); i++ ){

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
    for( int i=0; i<(int)(number.size()/2); i++ ){
        if( number[i] != number[number.size()-i-1] ){ 
            return false;
        }
    }
    return true;
}

/**
 * @brief Strip String
*/
std::string String_Strip( const std::string& input,
                          const std::string& pattern )
{
    // Flag on if we should strip
    bool strip_char = false;

    // Iterate through value
    std::string value = input;
    int i=0;
    while( value.size() > 0 ){

        // iterate through each pattern
        strip_char = false;
        for( int j=0; j<(int)pattern.size(); j++ ){
            if( value.front() == pattern[j] ){
                strip_char = true;
                break;
            }
        }

        // if we need to strip, then strip
        if( strip_char == true ){
            value = value.substr(1);
        } 
        
        // Otherwise stop working once we don't have to strip
        else{
            break;
        }

        // increment i
        i++;
    }
    
    // Move right to left
    i = value.size()-1;
    while( value.size() > 0 ){

        // iterate through each pattern
        strip_char = false;
        for( int j=0; j<(int)pattern.size(); j++ ){
            if( value.back() == pattern[j] ){
                strip_char = true;
                break;
            }
        }

        // if we need to strip, then strip
        if( strip_char == true ){
            value = value.substr(0, value.size()-1);
        } else{
            break;
        }

        // deccrement i
        i--;
    }

    return value;
}

#endif
