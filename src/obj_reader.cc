// Includes
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iterator>

#include <typeinfo>

// personal includes
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/face.h"
#include "../include/object.h"

// namespaces to use
using namespace std; 
using namespace graphic;

int main( int argc, char* argv[] ) {

    cout << ":: Reader Obj Files :: " << endl;
    
    string line;
    ifstream file;
    file.open("models/cube.obj", ios::in );

    if ( file.is_open() ) {
        while ( file ) {
            getline (file, line);

            stringstream str_stream(line);
            istream_iterator<string> begin(str_stream);
            istream_iterator<string> end;
            vector<string> sub_str(begin, end);
            
            for (auto item : sub_str)
                cout <<  item << " ";

            cout << endl;
        }
    }
    
    return 0;
}
