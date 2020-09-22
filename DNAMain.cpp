#include <iostream>
#include <fstream>

#include "DNAStats.h"

using namespace std;

// main method to process a list
int main(int argc, char** argv){
  bool processAnother = true;
  string userChoice;

  // checking if there is a command line argument
  if(argc >= 2)
  {
    string fileName = argv[1];
    ofstream fileOut;
    ifstream DNAinput;
    fileOut.open("NikitaShetty.out");

    while(processAnother){
      DNAStats *ds = new DNAStats();
      DNAinput.open(fileName);
      // checking if text file name is valid and file can be opened
      if (DNAinput.is_open() == false)
      {
        cout << "ERROR: Invalid usage. Please give a readable data file name." << endl;
        cout << "Enter the file name: " << endl;
        cin >> fileName;
        DNAinput.clear();
        fileOut.clear();
        continue;
      }
      else{
        ds->calcRelativeProbabilities(DNAinput) ;
        ds->calcStats(DNAinput);
        ds->printStats(fileOut);
        ds->printGaussian(fileOut);

        // getting user input on whether to continue or end
        cout << "\n" << fileName << " successfully processed." << endl;
        cout << "Would you like to process another list? Enter 'Y' for yes or any letter for no." << endl;
        cin >> userChoice;
        if(userChoice == "Y" || userChoice == "y"){
          cout << "Enter the file name: " << endl;
          cin >> fileName;
          DNAinput.close();
          DNAinput.clear();
          fileOut.close();
          fileOut.clear();
          fileOut.open("NikitaShetty.out", ios::trunc);
          processAnother = true;
        }
        else{
          processAnother = false;
          DNAinput.close();
          delete ds;
          cout << "All done. Goodbye." << endl;
          return 1;
        }
      }
    }
  }
  else{
    cout << "\nERROR: Please give a data file name in the command line.\n" << endl;
  }
}
