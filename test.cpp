// full test file

#include "version.h"
#include <iostream>
#include <cstring>
#include "src/Testing/include.h"
#include "src/Math/test/testMath.h"

using namespace std;


int main(int argc, char *argv[]){
    cout << "TEST Version: " << FULLVERSION_STRING << endl;
    cout << argv[1] << " == Math" << endl;
    
    if(strcmp(argv[1], "Math")==0){
        return testMath()==true;
    }else if(strcmp(argv[1], "DataStruMemLeaks")==0){
        
    }
    
    
    return 0; // if does not return 0, test fails
}
