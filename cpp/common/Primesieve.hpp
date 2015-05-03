#ifndef __PRIME_SIEVE_H__
#define __PRIME_SIEVE_H__

// C++ Standard Libraries
#include <cinttypes>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/**
 *  @class Prime Sieve Class
 *  
 *  Implements a basic prime sieve
 */
class Primes{

    public:
        
        /**
         * @brief Constructor given maximum value and debugging flag.
         */
        Primes( int64_t const& maxval, 
                bool const&   debug = false) 
            : MAX(maxval)
        {
            // MAX value
            long int root = static_cast<long int>(ceil(sqrt(static_cast<double>(MAX))));
            m_pos = 1;
            if(debug)cout << "Starting Library Construction" << endl;

            // Iterate over data
            m_data.begin();
            for(long int i=0;i<MAX;i++){
                m_data.push_back(true);
            }

            // Set 0 to false
            m_data[0]=false;
            for(long int i=1;i<=root;i++)
            {
                if(m_data[i-1]){
                    for( long int j = i*2; j <= MAX; j+= i){
                        m_data[j-1] = false;
                        
                        // Print the debugging data
                        if(debug){
                            cout << status(i,root);
                        }
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
                    if( m_pos > MAX ){ 
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
            if(number > 0 && number < MAX)
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
            for( int i=0; i<MAX; i++ ){
                if( m_data[i] ){
                    sum++;
                }
            }
            return sum;
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
        vector<bool> m_data;
        
        // Max Value
        const int64_t MAX;

        // Position
        int64_t m_pos;
};

#endif
