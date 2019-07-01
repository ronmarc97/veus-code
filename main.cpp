/* Copyright(c) 2019-present, Ronald Marcos.
 *  Created on: Jun 29, 2009
 *      Author: Ronald
 *
 *  Decode RDW indices from a communication sequence that
 *  has been dumped by an Automated Hematology Analyzer
 *
 *  The input must be read from standard input, indefinitely.
 *  No extra or wrong data appear in the input.
 *  A sequence has the following pattern: 4 characters for
 *  each value, followed by a Carriage Return ("\r").
 *
 *   _ _ _ _\r_ _ _ _\r_ _ _ _\r_ _ _ _\r_ _ _ _\r
 *    RDW_SD    MCV      MCHC     MCH     RDW_CV
 *
 * The output must be written to standard output.
 * only (and precisely) the requested information.
 * For each sequence there must be printed
 * RDW-CV and RDW-SD values with 2 integer digits, a
 * dot, and 1 fractional digit
 *
 *   RDWCV=_ _._,RDWSD=_ _._\r
 *
 * At the end of each the sequence, a Carriage Return \r
 * must also be printed
*/

#include <iostream>
#include <map>
#include <string>
#include <map>
#include <vector>
#include "functions.h"

using namespace std;


int main()
{
    //create a map that stores strings indexed by integer
    std::map<std::string, int> indicesRDW;   // Red Cell Distribution Width indices
    std::vector<std::string> names = { "RDW_SD", "MCV", "MCHC", "MCH", "RDW_CV" };
    for(int i=0; i<names.size(); ++i)
        indicesRDW[names[i]] = 0;      //  set all of the data with 0 into the indicesRDW

    /*  RDW_SD: Red Cell Distribution Width Standard Deviation
        MCV:    Mean Corpuscular Volume
        MCHC:   Mean Corpuscular Hemoglobin Concentration
        MCH:    Mean Corpuscular Hemoglobin
        RDW_CV: Red Cell Distribution Width Coefficient of Variation
    */

    string input;
    // waiting to read on standard input, indefinitely.
    while(getline(cin, input) && !input.empty()){
        decodeSequence(indicesRDW, names, input);
        printData(indicesRDW, names);
    }

    return 0;
}