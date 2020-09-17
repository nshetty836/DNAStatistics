#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int ACount = 0, CCount = 0, TCount = 0, GCount = 0;
int AACount = 0, ACCount = 0, ATCount = 0, AGCount = 0, CACount = 0,
    CCCount = 0, CTCount = 0, CGCount = 0, TACount = 0, TCCount = 0,
    TTCount = 0, TGCount = 0, GACount = 0, GCCount = 0, GTCount = 0,
    GGCount = 0;
int stringCount = 0, nucleotideCount = 0, bigramCount = 0;
char nucleotide;
string bigram;
string line;
int sum = 0;
int mean = 0;
int variance = 0;
int stdDev = 0;

void readFile(ifstream & DNAinput)
{
   while (getline(DNAinput >> ws, line))
   {
     for(int k = 0; k <line.length(); ++k)
     {
       transform(line.begin(), line.end(),line.begin(), ::toupper);
     }
     nucleotideCount += line.length()-1;
     stringCount++;
     cout << line << endl;
     for(int i = 0; i < line.length(); ++i)
     {
       if(nucleotide == 'A')
          ACount++;
       else if(nucleotide == 'C')
          CCount++;
       else if(nucleotide == 'T')
          TCount++;
       else if(nucleotide == 'G')
          GCount++;
       if(line.length()%2 == 0){

       }
       if(i % 2 == 0 && i != line.length()-1){
         cout << i+2 << endl;
         cout << line.substr(i, 2) << endl;
         if(line.substr(i,2) == "AA"){
            AACount++;
         }
         if(line.substr(i,2) == "AC"){
            ACCount++;
         }
         if(line.substr(i,2) == "AT"){
            ATCount++;
         }
         if(line.substr(i,2) == "AG"){
            AGCount++;
         }
         if(line.substr(i,2) == "CA"){
            CACount++;
         }
         if(line.substr(i,2) == "CC"){
            CCCount++;
         }
         if(line.substr(i,2) == "CT"){
            CTCount++;
         }
         if(line.substr(i,2) == "CG"){
            CGCount++;
         }
         if(line.substr(i,2) == "TA"){
            TACount++;
         }
         if(line.substr(i,2) == "TC"){
            TCCount++;
         }
         if(line.substr(i,2) == "TT"){
            TTCount++;
         }
         if(line.substr(i,2) == "TG"){
            TGCount++;
         }
         if(line.substr(i,2) == "GA"){
            GACount++;
         }
         if(line.substr(i,2) == "GC"){
            GCCount++;
         }
         if(line.substr(i,2) == "GT"){
            GTCount++;
         }
         if(line.substr(i,2) == "GG"){
            GGCount++;
         }
         bigramCount++;
       }
     }
   }
   // cout << stringCount << endl;
   // cout << nucleotideCount << endl;
   cout << "bigram count: " << bigramCount << endl;
   cout << "AA count: " << AACount << endl;
   cout << "AT count: " << ATCount << endl;
   cout << "CG count: " << CGCount << endl;

   // cout << ACount << endl;
   // cout << CCount << endl;
   // cout << TCount << endl;
   // cout << GCount << endl;
   DNAinput.close();
}

void calcStats(){

}

void writeFile(){

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
