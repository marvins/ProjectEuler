// C++ Standard Libraries
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/**
 * Convert Upper Case Letter to Number
 */
int letter_val(char);


/**
 * Load the Name File and Return list of names.
*/
void load_file( std::string const& filename,
                vector<string>& list);


/**
 * Main Function
*/
int main( int argc, char* argv[] )
{
    // Variables
    string name;
    vector<string> list;
    long long run_sum = 0;
    int letter;

    // Check arguments
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <names file>" << std::endl;
        return 1;
    }

    // Load the File
    load_file(argv[1], list);

    // Sort the list
    sort ( list.begin() , list.end() );

    // Iterate through the names
    for(int i=0;i<list.size();i++)
    {
        // Get the next name
        name = list[i];
        letter = 0;

        // Sum the name
        for(int j=0;j<name.length();j++)
            letter += letter_val(name[j]);
      
        // Add to the running sum
        run_sum += letter * (i+1);
    }

    cout << run_sum << endl;
    return 0;
}  

/**
 * Letter to Number
*/
int letter_val(char c)
{
  char letters[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  for(int i=1;i<=26;i++)
    if( c == letters[i-1] )
      return i;
  return 0;
}

/**
 * Load the File
*/
void load_file( std::string const& filename,
                vector<string>& list)
{
    string name;
    ifstream fin;
    fin.open(filename.c_str());
    
    fin.get();
    getline(fin,name,'\"');
    fin.get();
    
    while(fin.good()){
      fin.get();
      list.push_back(name);
      getline(fin,name,'\"');
      fin.get();
    }
    fin.close();
}
