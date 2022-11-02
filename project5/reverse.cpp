// Name: Scott Kang
// Email: kyung.ho.kang@vanderbilt.edu
// VUnetid: kangk
// Class: CS2201
// Date: 2019/10/20
// Honor statement: I have not given or received unauthorized aid on this assignment
// Description:
// Reverse a sound data file by reading in all the data samples,
// pushing them onto a stack, and then creating a new sound data
// file while popping values off the stack.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DblStack.h"


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (std::ifstream &infile, std::ofstream &outfile);



int main ()
{

   // open input & output data files
   std::ifstream infile;
   std::ofstream outfile;
   openFiles(infile, outfile);

   std::cout << "Reading the input file..." << std::endl;

   // read in the data on the first line of the file
   std::string firstLine, secondLine;

   getline(infile,firstLine);    // read in the first line
   getline(infile,secondLine);   // read in the second line

   DblStack stackTimeStep;
   DblStack stackSound;

   double timestep;
   double soundvalue;

   // put all the timestep in one stack and all the soundvalue in the other stack

   while(infile >> timestep >> soundvalue){
       stackTimeStep.push(timestep);
       stackSound.push(soundvalue);
   }

   DblStack orderedTimeStep;

   // replace all the items in stackTimeStep to orderedTimeStep so the order is not reversed

   while(stackTimeStep.isEmpty() == false){
       orderedTimeStep.push(stackTimeStep.top());
       stackTimeStep.pop();
   }


   std::cout << "There were " << "??" << " samples in the file." << std::endl;
   std::cout << "Creating output file... wait for Done message." << std::endl;


   // Now we are ready to output the data values to output file.
   // But first, we need to output the header lines
   //
   outfile << firstLine << std::endl;
   outfile << secondLine << std::endl;

   // orderedTimeStep is not reversed but stackSound is reversed. So put the data on a new outfile

   while(orderedTimeStep.isEmpty() == false && stackSound.isEmpty() == false){
       outfile << "  "  << orderedTimeStep.top() << "\t" << stackSound.top() << std::endl;
       stackSound.pop();
       orderedTimeStep.pop();
   }

   // close the files
   infile.close();
   outfile.close();

   std::cout << "Done." << std::endl;

   std::cout << "press enter to exit";
   std::cin.get();
   std::cin.get();

}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile)
{

	// open input data file
    std::string inFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inFileName;
	infile.open(inFileName.c_str());
	if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
		exit(1);
	}

	// open output data file
    std::string outFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outFileName;
	outfile.open(outFileName.c_str());
	if (outfile.fail()) {
        std::cout << "Error opening output data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
		exit(1);
	}
}
