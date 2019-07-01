//
// Created by ronald on 6/28/2019.
//
// This header function.h contain all the
// function used in the main program for
// decoding and printinig the RDW indices
// from a communication sequence
//

#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <math.h>

using namespace std;

double truncate(double& val, unsigned int fractionalDigits)
{
    return trunc(val * powf(10, fractionalDigits)) / powf(10, fractionalDigits);
}

void printData(map <string, int> &data, std::vector<std::string> names) {

    double RDWCV = double(data[names[4]])/(double)100.0;
    double RDWSD = double(data[names[0]])/(double)100.0;

    cout << "RDWCV=" << truncate(RDWCV, 1) << "," << "RDWSD=" << truncate(RDWSD, 1) << "\\" << "r" << endl;
    cout << std::endl;
}

void decodeSequence(map <string, int> &data, std::vector<std::string> names, string input){

    std::string subject(input);
    std::regex rgx("([0-9]{4})+((\\r)*)");
    //regex object for matching 4 characters followed
    // by a Carriage Return: _ _ _ _\r

    try {
        std::sregex_iterator begin(subject.begin(), subject.end(), rgx);
        std::sregex_iterator end;
        string result;
        int i = 0;
        // finding all the matching pattern.
        while (begin != end) {
            std::smatch match = *begin;
            data[names[i]] = stoi(match.str()); // store in data.
            //std::cout << match.str() << "\n";
            begin++;
            i++;
        }
    } catch (std::regex_error& e) {
        // Syntax error in the regular expression
    }
}
