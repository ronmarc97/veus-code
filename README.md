# veus-code

Decode RDW indices from a communication sequence that has been
dumped by an Automated Hematology Analyzer.

## Getting Started

The main() program read a sequential data on the standard input, waiting for that indefinitely,
then decoding and printing the RDW-CV and RDW-SD values. 
 
## Running the code

On Windows, you might use "Visual Studio", "Visual Studio Code" or "JetBrains CLion",
you can simply compile and run the code.

Using the command prompt: change the directory, using cd to the particular directory where the source file is stored.
Previously intalled a compiler g++(https://sourceforge.net/projects/tdm-gcc/) and set in the environment variables of the system.
For compiling Windows then make use of this:

          g++ -std=c++11 main.cpp -o main

                         or
						 
          g++ -std=c++0x main.cpp -o main
		  
Afeter compiling a .exe file is created, then for run this, execute:

                main.exe		  
		   
Also you could use this commands on Linux. Yo may use g++ the C++ compiler in gcc. 
Depending on your program, replacing gcc with g++.		 
           g++ main.cpp -o main  
		   ./main

## Author

* **Ronald Marcos** 
