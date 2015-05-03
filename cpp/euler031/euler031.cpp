/**
 * @file    euler031.cpp
 * @author  Marvin Smith
 * @date    5/2/2015
*/

// C++ Standard Libraries
#include <iostream>

using namespace std;


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ){

    //start at 1 due to 200p coin
    int count = 1;

    //iterate through all possible 1p
    for(int p1=0; p1<=(200); p1++)

        //iterate through all possible 2p
        for(int p2=0; p2<=(100); p2++)

            //iterate through all 5p
            for(int p5=0; p5<=(40); p5++)

                //iterate through all 10p
                for(int p10=0; p10<=(20); p10++)

                    //iterate through all 20p
                    for(int p20=0; p20<=(10); p20++)

                        //iterate through all 50p
                        for(int p50=0; p50<=(4); p50++)

                            //iterate through all 100p
                            for(int p100=0; p100<=(2); p100++)

                                if( (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 + 50*p50 + 100*p100) == 200 ){
                                    count++;
                                }
    cout << count << endl;

    return 0;
}
