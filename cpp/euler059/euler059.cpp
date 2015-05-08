/**
 * @file    euler059.cpp
 * @author  Marvin Smith
 * @date    5/8/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <deque>
#include <fstream>
#include <iostream>
#include <regex>
#include <streambuf>

// Common Libraries
#include "../common/StringUtilities.hpp"

using namespace std;

/// Key Set
std::string valid_keyset = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
std::string invalid_keyset;

/**
 * @brief Apply XOR Cipher
 */
std::string Apply_XOR_Cipher( const std::string& input,
                              const std::string& cipher )
{
    // Create output
    std::string output; 
    
    // Iterate over input
    int counter = 0;
    for( int i=0; i<(int)input.size(); i++ ){
    
        // Add output
        output.push_back( input[i] ^ cipher[counter] );
        counter++;
        if( counter >= 3 ){
            counter = 0;
        }
    }
    
    // Return output
    return output;
}


/**
 * @brief Generate Cipher Keys
*/
void Generate_Cipher_Keys( const int&                key_size,
                           const std::string&        input,
                           std::deque<std::string>&  eligible_cipher_keys,
                           std::deque<std::string>&  eligible_results )
{
    // Create initial cipher
    std::string cipher, exit_cipher;
    for( int i=0; i<key_size; i++ ){
        cipher += 'a';
        exit_cipher += 'z';
    }

    // Start iterating
    while( true ){
        
        // Add key
        eligible_cipher_keys.push_back(cipher);
        eligible_results.push_back( Apply_XOR_Cipher( input, cipher ));
       
        // Check exit
        if( cipher == exit_cipher ){
            break;
        }

        // Increment
        for( int i=0; i<(int)cipher.size(); i++ ){
            if( cipher[i] != 'z' ){
                cipher[i]++;
                break;
            }
            else{
                cipher[i] = 'a';
            }
        }
    }
}


/**
 * @brief Compute Histogram
*/
std::vector<int> Build_Histogram( const std::string& input )
{
    // Create histogram
    std::vector<int> histogram(256,0);

    // Iterate over input, computing values
    for( int i=0; i<(int)input.size(); i++ ){

        // Add element
        histogram[input[i]]++;
    }

    // return histogram
    return histogram;
}

/**
 * Make sure the histogram has enough characters
*/
bool Test_Histogram_Enough_Chars( const std::vector<int>& histogram )
{
    // Check the size
    int64_t valid_chars = 0;
    int64_t invalid_chars = 0;

    for( int i=0; i<(int)histogram.size(); i++ ){
       
        // Process Valid Characters
        if( ( i >= 'a' && i <= 'z' ) ||
            ( i >= 'A' && i <= 'Z' ) ||
            ( i >= '0' && i <= '9' ) ||
            ( i == ' ' ) )
        {
            valid_chars += histogram[i]; 
        }
        
        // Process Invalid Characters
        else{
            invalid_chars += histogram[i]; 
        }
    }

    // Check ratio
    int64_t sum = valid_chars + invalid_chars;
    double ratio = (double)valid_chars / sum;
    if( ratio < 0.95 ){
        return false;
    }
    return true;
}


/**
 * @brief Estimate Ciphers
*/
void Prune_Cipher_Keys( std::deque<std::string>&  eligible_cipher_keys,
                        std::deque<std::string>&  eligible_results )
{
    // Misc Variables
    std::string temp_result;
    std::vector<int> temp_histogram;

    // Iterate through keys
    for( int i=0; i<(int)eligible_cipher_keys.size(); i++ )
    {
        // Check the histogram
        temp_histogram = Build_Histogram( eligible_results[i] );

        // Check if histogram has enough chars
        if( Test_Histogram_Enough_Chars( temp_histogram ) == false ){
            eligible_cipher_keys.erase( eligible_cipher_keys.begin() + i );
            eligible_results.erase( eligible_results.begin() + i );
            i--;
        }

    }
    
}
                      

/**
 * @brief Load the file.
 */
std::string Load_File( const std::string& filename ){
    
    // Misc variable
    char buffer[256];
    std::string output;

    // Open the filename
    std::ifstream fin;
    fin.open(filename.c_str());

    // Start fetching data
    while( fin.getline( buffer, 256, ',') ){
        
        // Add to buffer
        output.push_back((char)str2num<int>(std::string(buffer)));

    }

    // Close the file
    fin.close();

    // return the file data
    return output;
}


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
    std::string contents = Load_File( filename );

    // Generate Cipher Keys
    std::deque<std::string> eligible_cipher_keys;
    std::deque<std::string> eligible_results;
    Generate_Cipher_Keys( 3, 
                          contents,
                          eligible_cipher_keys, 
                          eligible_results );
        
    
    // Prune Cipher Keys
    Prune_Cipher_Keys( eligible_cipher_keys,
                       eligible_results );

    // Compute sum
    int64_t sum = 0;
    for( int i=0; i<(int)eligible_results.front().size(); i++ ){
        sum += eligible_results.front()[i];
    }
    std::cout << sum << std::endl;

    // Exit Program
    return 0;
}

