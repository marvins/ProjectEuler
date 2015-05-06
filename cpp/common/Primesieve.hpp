#ifndef __PRIME_SIEVE_H__
#define __PRIME_SIEVE_H__

// C++ Standard Libraries
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

/**
 *  @class Prime Sieve Class
 *  
 *  Implements a basic prime sieve
 */
template < typename DATATYPE, 
           typename DEBUG = std::false_type>
class Primes{

    public:

        /// Define our datatype
        typedef DATATYPE datatype;
        
        /**
         * @brief Constructor given maximum value.
         */
        Primes( datatype const&  max_prime,
                bool const&      debug = false )
            : m_max_prime_value(max_prime),
              m_data(std::vector<bool>(max_prime,true)),
              m_pos(2)
        {
            
            //  Log Entry
            if( std::is_same<DEBUG,std::true_type>::value == true ){
                cout << "Starting Library Construction" << endl;
            }
            
            // The root can be used to crunch the rough number of primes
            datatype root = static_cast<datatype>(ceil(sqrt(static_cast<double>(m_max_prime_value))));

            // Test Primes
            m_data[0] = false;
            for(datatype i=1;i<=root;i++)
            {
                // Check if the previous value is true
                if(m_data[i-1]){

                    // For each prime, set each multiple of it 
                    // in the data list to false since they will be divisible by us.
                    for( datatype j = i*2; 
                         j <= m_max_prime_value; 
                         j+= i)
                    {
                        // Falsify the prime status
                        m_data[j-1] = false;
                    }

                    // Print the debugging data
                    if( std::is_same<DEBUG,std::true_type>::value == true ){
                       cout << status(i,root);
                    }

                }

            }
            // Print the debugging flag
            if(debug) cout << endl;

        }


        /**
         * Start Processing Prime Numbers
         */
        void prime_start(){
            m_pos = 2;
        }


        /**
         * Get the next prime.
         *
         * @param[out] end Check if the value is the last prime number.
         */
        int64_t prime_next(bool& end )
        {

            // Variables
            bool point = false;
            long int value,num;

            // If the position is below the array size
            if( m_pos < m_data.size() )
            {
                point = is_prime(value);
                while(!is_prime(m_pos) && (m_pos!=-1)){
                    m_pos++;
                    if( m_pos > m_max_prime_value ){ 
                        end=true; 
                        return 0;
                    }
                }

                m_pos++;

                if((m_pos-1) > m_data.size()||(m_pos == -1))
                {
                    end = true;
                    return 0;
                }
                else
                {
                    end = false;
                    return m_pos-1;
                }
            }
            end = true;
            return 0;

        }


        /**
         * @brief Check if a number is prime.
         * 
         * @param[in] number Number to test.
         *
         * @return True if the number is prime, false otherwise.
         */
        bool is_prime(const long int& number ) const
        {
            if(number > 0 && number < m_max_prime_value)
            {
                return m_data[number-1];
            }
            return false;
        }

        /**
         * @brief Check the number of primes
         *
         * @return Number of primes.
        */
        int Get_Number_Primes()const
        {
            int sum = 0;
            for( int i=0; i<m_max_prime_value; i++ ){
                if( m_data[i] ){
                    sum++;
                }
            }
            return sum;
        }


        /**
         * @brief Get a single list of primes
         *
         * @return prime list
        */
        std::vector<datatype> Get_Prime_List( const int& max_prime )const{
            
            // Create output container
            std::vector<datatype> output;
            
            // Iterate over list
            int64_t counter = 0;
            int min_val = std::min( (int64_t)max_prime, (int64_t)m_data.size());
            for( int i=0; i<min_val; i++ ){
                if( m_data[i] == true ){
                    output.push_back(i+1);
                }
            }
            return output;
        }


    private:

        /**
         * Get the status
        */
        std::string status( int64_t const& x,
                            int64_t const& y ) const
        {
            // Output stream buffer
            std::ostringstream buff;

            // Compute a z value
            double z = x/(double)y;

            // Create output
            string output = " Building Library [";

            // Iterate over output
            for(int i=0;i<40;i++){
                if((i/40.0)<(z))
                    output += '*';
                else
                    output += ' ';
            }

            output += "] ";
            buff << ((x/(double)y)*100);
            output += buff.str();
            output += "% \r";

            return output;
        }

        
        // Data Array
        std::vector<bool> m_data;
        
        /// Max Prime Value
        const datatype  m_max_prime_value;

        // Current Iterator Position
        datatype m_pos;
};

#endif
