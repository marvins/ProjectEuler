#ifndef __PRIME_SIEVE_H__
#define __PRIME_SIEVE_H__

// C++ Standard Libraries
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

/**
 *  @class Prime Sieve Class
 *  
 *  Implements a basic prime sieve
 */
class Primes{

    public:

        /**
         * Constructor
         */
        Primes( long int maxval, bool debug = false) 
            : MAX(maxval)
        {
            // MAX value
            long int root = static_cast<long int>(ceil(sqrt(static_cast<double>(MAX))));
            pos = 1;
            if(debug)cout << "Starting Library Construction" << endl;

            // Iterate over data
            data.begin();
            for(long int i=0;i<MAX;i++){
                data.push_back(true);
            }

            // Set 0 to false
            data[0]=false;
            for(long int i=1;i<=root;i++)
            {
                if(data[i-1]){
                    for( long int j = i*2; j <= MAX; j+= i){
                        data[j-1] = false;
                        
                        // Print the debugging data
                        if(debug){
                            cout << status(i,root);
                        }
                    }
                }

                // Print the debugging flag
                if(debug) cout << endl;
            }

        }


        /**
         * Start Processing Prime Numbers
         */
        void prime_start(){
            pos = 2;
        }


        /**
         * Get the next prime.
         *
         * @param[out] end Check if the value is the last prime number.
         */
        long int prime_next(bool& end )
        {

            // If the position is below the array size
            if( pos < (int)data.size() )
            {
                while(!is_prime(pos) && (pos!=-1)){
                    pos++;
                    if( pos > MAX ){ 
                        end=true; 
                        return 0;
                    }
                }

                pos++;

                if((pos-1) > (int)data.size()||(pos == -1))
                {
                    end = true;
                    return 0;
                }
                else
                {
                    end = false;
                    return pos-1;
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
                return data[number-1];
            }
            return false;
        }


    private:

        string status(long int x, long int y)const
        {
            std::ostringstream buff;
            double z = x/(double)y;
            string output = " Building Library [";

            for(int i=0;i<40;i++)
                if((i/40.0)<(z))
                    output += '*';
                else
                    output += ' ';
            output += "] ";
            buff << ((x/(double)y)*100);
            output += buff.str();
            output += "% \r";

            return output;
        }

        vector<bool> data;
        const long int MAX;
        long int pos;
};

#endif
