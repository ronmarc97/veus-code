#include <iostream>
#include <map>
#include <string>
#include <map>
#include <vector>
#include <fstream>

#include "functions.h"


int main() {


    std::ifstream infile("inputs.txt");  //input file

    //create a map that stores strings indexed by integer
    std::map<std::string, int> indicesRDW;   // Red Cell Distribution Width indices
    std::vector<std::string> names = { "RDW_SD", "MCV", "MCHC", "MCH", "RDW_CV" };
    for(int i=0; i<names.size(); ++i)
        indicesRDW[names[i]] = 0;      //  set all of the data with 0 into the indicesRDW

    std::string line ;
    while( std::getline( infile, line ) ) // for each line read from the file
    {
        decodeSequence(indicesRDW, names, line);
        printData(indicesRDW, names);

    }

    return 0;
}
