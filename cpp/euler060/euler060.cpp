/**
 * @file    euler060.cpp
 * @author  Marvin Smith
 * @date    9/27/2013
 */

// C++ Standard Libraries
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <memory>
#include <mutex>
#include <set>
#include <thread>
#include <vector>

// Common Libraries
#include "../common/Primesieve.hpp"
#include "../common/StringUtilities.hpp"

using namespace std;


/**
 * @class Supreme Prime Checker
*/
class Supreme_Prime_Checker{

    public:
        
        /// Pointer Type
        typedef std::shared_ptr<Supreme_Prime_Checker> ptr_t;

        /**
         * @brief Constructor.
         *
         * @param[in] max_array_size Max size of the array.
         * @param[in] primes Prime sieve to check against.
        */
        Supreme_Prime_Checker( const int& max_array_size,
                               Primes<int64_t,std::false_type> const& primes )
          : m_primes(primes),
            m_lookup_table(std::vector<std::vector<int8_t>>(max_array_size,std::vector<int8_t>(max_array_size,2)))
        {
            // Initialize same values to always fail
            for( int i=0; i<max_array_size; i++ ){
                m_lookup_table[i][i] = 0;
            }
        }

        /**
         * @brief Lookup
        */
        bool Is_Prime_Pair( const int64_t& prime1,
                            const int64_t& prime2 )
        {
            // Check lookup table
            if( m_lookup_table[prime1][prime2] == 2 ||
                m_lookup_table[prime2][prime1] == 2 )
            {
                // Create strings
                std::string p1 = num2str(prime1);
                std::string p2 = num2str(prime2);

                // Concatenate and test
                m_lookup_table[prime1][prime2] = m_primes.is_prime(str2num<int64_t>(p1 + p2));
                m_lookup_table[prime2][prime1] = m_primes.is_prime(str2num<int64_t>(p2 + p1));
            }

            return (m_lookup_table[prime1][prime2] && m_lookup_table[prime2][prime1]);
        }

        /**
         * @brief Get Valid Prime Indeces
         */
        std::vector<int64_t> Get_Valid_Indices()const{
            
            // Create output
            std::vector<int64_t> output;
            for( int i=0; i<(int)m_lookup_table.size(); i++ )
            for( int j=0; j<(int)m_lookup_table[i].size(); j++ ){
                if( m_lookup_table[i][j] == 1 ){
                    output.push_back( i );
                }
            }

            // Clean up
            std::sort( output.begin(), output.end());
            std::vector<int64_t>::iterator it;
            it = std::unique( output.begin(), output.end() );

            output.resize(std::distance(output.begin(), it));

            return output;
        }

    private:

        // Prime Sieve
        Primes<int64_t,std::false_type> m_primes;

        // First Prime Reference
        std::vector<std::vector<int8_t>> m_lookup_table;

}; // End of Supreme_Prime_Checker_Class

/// Global Instance
Supreme_Prime_Checker::ptr_t prime_checker(nullptr);

std::vector<int64_t> sums;
std::mutex mtx;
std::vector<int64_t> valid_pairs;

/**
 * @brief Task Runner
*/
void Runner( const int& min_a, const int& max_a )
{
    
    int64_t sum;

    // Iterate over A & B
    for( int a=min_a;  a<max_a;              a++ ){
    for( int b=a+1;    b<(int)valid_pairs.size(); b++ ){
        
        // Check this section
        if( prime_checker->Is_Prime_Pair( valid_pairs[a], valid_pairs[b] ) == false )
        {
            continue;
        }
        
        // Iterate over C
        for( int c=b+1;    c<(int)valid_pairs.size(); c++ ){
            if( prime_checker->Is_Prime_Pair( valid_pairs[a], valid_pairs[c] ) == false ||
                prime_checker->Is_Prime_Pair( valid_pairs[b], valid_pairs[c] ) == false )
            {
                continue;
            }
    
            for( int d=c+1;    d<(int)valid_pairs.size(); d++ ){
            
                if( prime_checker->Is_Prime_Pair( valid_pairs[a], valid_pairs[d] ) == false ||
                    prime_checker->Is_Prime_Pair( valid_pairs[b], valid_pairs[d] ) == false ||
                    prime_checker->Is_Prime_Pair( valid_pairs[c], valid_pairs[d] ) == false )
                    {
                        continue;
                    }
                    
                    for( int e=d+1;    e<(int)valid_pairs.size(); e++ ){
                    
                        if( prime_checker->Is_Prime_Pair( valid_pairs[a], valid_pairs[e] ) != false &&
                            prime_checker->Is_Prime_Pair( valid_pairs[b], valid_pairs[e] ) != false &&
                            prime_checker->Is_Prime_Pair( valid_pairs[d], valid_pairs[e] ) != false &&
                            prime_checker->Is_Prime_Pair( valid_pairs[c], valid_pairs[e] ) != false )
                        {
                            // Sum
                            sum = valid_pairs[a] + valid_pairs[b] +
                                  valid_pairs[c] + valid_pairs[d] + valid_pairs[e];
            
                            mtx.lock();
                            sums.push_back(sum);
                            mtx.unlock();
                        }
    }}}}}
}


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ){

    // define our max prime value
    const int64_t max_prime = 3999999999;
    const int64_t max_query_primes = 10000;

    // create prime sieve
    Primes<int64_t,std::false_type>  primes(max_prime);

    // Get a single list of primes
    std::vector<int64_t> prime_list = primes.Get_Prime_List( max_query_primes );

    // Create a prime checker
    prime_checker = Supreme_Prime_Checker::ptr_t(new Supreme_Prime_Checker( max_query_primes, primes));
    
    // Build the Prime Checker
    for( int i=0; i<(int)prime_list.size(); i++ ){
    for( int j=0; j<(int)prime_list.size(); j++ ){
        prime_checker->Is_Prime_Pair( prime_list[i], prime_list[j] );
    }}
    
    // Get a valid set
    valid_pairs = prime_checker->Get_Valid_Indices();

    // Iterate over each set, testing combinations
    

    // Start threads for each task
    std::thread t1( Runner,                      0,      valid_pairs.size()/5.0 );
    std::thread t2( Runner,   valid_pairs.size()/5.0,  2*valid_pairs.size()/5.0 );
    std::thread t3( Runner, 2*valid_pairs.size()/5.0,  3*valid_pairs.size()/5.0 );
    std::thread t4( Runner, 3*valid_pairs.size()/5.0,    valid_pairs.size());
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Sort
    std::sort( sums.begin(), sums.end() );

    std::cout << sums.front() << std::endl;
    
    // Exit Program
    return 0;
}

