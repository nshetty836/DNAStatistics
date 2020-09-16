#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void readFile(ifstream & DNAinput)
{
  string line;
  int count = 0;
   while (getline(DNAinput, line))
   {
     cout << line << endl;
   }
   DNAinput.close();
}
int main(int argc, char** argv){

  if(argc >= 2)
  {
    string fileName = argv[1];
    ifstream DNAinput(fileName);

    if (DNAinput.is_open() == false)
    {
      cout << "Invalid usage. Please give a data file name." << endl;
      return -1;
    }
    else{
      readFile(DNAinput) ;
    }
  }
}
