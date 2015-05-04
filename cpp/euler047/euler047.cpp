/**
 * @file    euler047.cpp
 * @author  Marvin Smith
 * @date    5/3/2015
*/

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <set>

// Common Libraries
#include "../common/Math_Utilities.hpp"
#include "../common/Primesieve.hpp"


using namespace std;

/**
 * @class An_Entry
*/
class An_Entry{

    public:
       
        /**
         * @brief Constructor
        */
        An_Entry( const int64_t& id )
          : m_id(id)
        {

        }


        /**
         * @brief Add primes
        */
        void Update( std::vector<int> const& prime_list )
        {
            for( int i=0; i<prime_list.size(); i++ ){
                if( prime_list[i] != 1 && prime_list[i] != m_id ){
                    m_prime_set.insert( prime_list[i] );
                }
            }
        }
        
        /**
         * @brief Add prime
        */
        void Update( int const& prime_value )
        {
            if( prime_value != 1 && prime_value != m_id ){
                m_prime_set.insert( prime_value );
            }
        }

        /**
         * @brief Get Prime List
        */
        std::vector<int> Get_Prime_List()const{
            
            // Create output list
            std::vector<int> prime_list;
            std::set<int>::iterator it = m_prime_set.begin();
            for(; it != m_prime_set.end(); it++ )
            {
                prime_list.push_back((*it));
            }

            return prime_list;
        }


    private:

        /// Id
        int64_t m_id;
        
        /// Prime Set
        std::set<int> m_prime_set;

}; // End of An_Entry Class


/**
 * @brief Prune the list
*/
void Prune_List( const int64_t&          value,
                 std::vector<int>&       divisor_list,
                 std::vector<An_Entry>&  entry_list,
                 Primes<int64_t> const&  primes )
{
    // construct new list
    std::vector<int> value_list = divisor_list;
    divisor_list.clear();
    
    // Iterate over the divisor list
    for( int i=0; i<value_list.size(); i++ )
    {
        // If the prime is not false, then check its own entry list
        if( primes.is_prime(value_list[i]) == false )
        {
            // Adjust the primes in the entry
            entry_list[value].Update( entry_list[value_list[i]].Get_Prime_List() );
        }
        else{
            entry_list[value].Update( value_list[i] );
        }

    }

    divisor_list = entry_list[value].Get_Prime_List();
}


/** 
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{
    // Set our max integer to iterate over
    int64_t max_range = 1000000;
    
    // Compute our max prime
    int64_t max_prime = 10000;
    
    // Build the prime sieve
    Primes<int64_t> primes(max_prime);

    // Temp Divisor List
    std::vector<int> divisor_list;
    bool flag = false;
    int64_t counter = 0;

    // List of Entries
    std::vector<An_Entry> entry_list;
    for( int64_t i=0; i<max_range; i++ ){
        entry_list.push_back(An_Entry(i));   
    }

    // Iterate over numbers
    for( int64_t i=3; i<max_range; i++ ){
        
        // Factorize
        divisor_list = Compute_Divisors( i );
        
        // Prune List
        Prune_List( i, divisor_list, entry_list, primes );
        
        // Check size
        if( divisor_list.size() == 4 ){
            flag = true;
            counter++;
        }else{
            flag = false;
            counter = 0;
        }

        // check for exit
        if( counter >= 4 ){
            std::cout << (i-3) << std::endl;
            break;
        }
    }

    // Exit Program
    return 0;
}

