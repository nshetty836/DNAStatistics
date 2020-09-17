#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
double ACount = 0, CCount = 0, TCount = 0, GCount = 0;
double AACount = 0, ACCount = 0, ATCount = 0, AGCount = 0, CACount = 0,
    CCCount = 0, CTCount = 0, CGCount = 0, TACount = 0, TCCount = 0,
    TTCount = 0, TGCount = 0, GACount = 0, GCCount = 0, GTCount = 0,
    GGCount = 0;
double AAProb = 0.0, ACProb = 0.0, ATProb = 0.0, AGProb = 0.0, CAProb = 0.0,
       CCProb = 0.0, CTProb = 0.0, CGProb = 0.0, TAProb = 0.0, TCProb = 0.0,
       TTProb = 0.0, TGProb = 0.0, GAProb = 0.0, GCProb = 0.0, GTProb = 0.0,
       GGProb = 0.0;
int stringCount = 0, nucleotideCount = 0, bigramCount = 0;
char nucleotide;
string bigram;
string line;
int sum = 0;
int mean = 0;
int variance = 0;
int stdDev = 0;

void calcRelativeProbabilities(ifstream & DNAinput, ofstream & fileOut)
{
   while (getline(DNAinput >> ws, line))
   {
     transform(line.begin(), line.end(),line.begin(), ::toupper);
     nucleotideCount += line.length()-1;
     stringCount++;
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
         if(line.substr(i,2) == "AA")
            AACount++;
         if(line.substr(i,2) == "AC")
            ACCount++;
         if(line.substr(i,2) == "AT")
            ATCount++;
         if(line.substr(i,2) == "AG")
            AGCount++;
         if(line.substr(i,2) == "CA")
            CACount++;
         if(line.substr(i,2) == "CC")
            CCCount++;
         if(line.substr(i,2) == "CT")
            CTCount++;
         if(line.substr(i,2) == "CG")
            CGCount++;
         if(line.substr(i,2) == "TA")
            TACount++;
         if(line.substr(i,2) == "TC")
            TCCount++;
         if(line.substr(i,2) == "TT")
            TTCount++;
         if(line.substr(i,2) == "TG")
            TGCount++;
         if(line.substr(i,2) == "GA")
            GACount++;
         if(line.substr(i,2) == "GC")
            GCCount++;
         if(line.substr(i,2) == "GT")
            GTCount++;
         if(line.substr(i,2) == "GG")
            GGCount++;
         bigramCount++;
       }
     }

     AAProb = AACount / bigramCount;
     ACProb = ACCount / bigramCount;
     ATProb = ATCount / bigramCount;
     AGProb = AGCount / bigramCount;
     CAProb = CACount / bigramCount;
     CCProb = CCCount / bigramCount;
     CTProb = CTCount / bigramCount;
     CGProb = CGCount / bigramCount;
     TAProb = TACount / bigramCount;
     TCProb = TCCount / bigramCount;
     TTProb = TTCount / bigramCount;
     TGProb = TGCount / bigramCount;
     GAProb = GACount / bigramCount;
     GCProb = GCCount / bigramCount;
     GTProb = GTCount / bigramCount;
     GGProb = GGCount / bigramCount;
   }
   // cout << stringCount << endl;
   // cout << nucleotideCount << endl;

   fileOut << "Here is the relative probability of each nucleotide bigram:" << endl;
   fileOut << "AA: " << AAProb << endl;
   fileOut << "AC: " << ACProb << endl;
   fileOut << "AT: " << ATProb << endl;
   fileOut << "AG: " << AGProb << endl;
   fileOut << "CA: " << CAProb << endl;
   fileOut << "CC: " << CCProb << endl;
   fileOut << "CT: " << CTProb << endl;
   fileOut << "CG: " << CGProb << endl;
   fileOut << "TA: " << TAProb << endl;
   fileOut << "TC: " << TCProb << endl;
   fileOut << "TT: " << TTProb << endl;
   fileOut << "TG: " << TGProb << endl;
   fileOut << "GA: " << GAProb << endl;
   fileOut << "GC: " << GCProb << endl;
   fileOut << "GT: " << GTProb << endl;
   fileOut << "GG: " << GGProb << endl;
}

void calcStats(ifstream & DNAinput, ofstream & fileOut){
  DNAinput.clear();
  DNAinput.seekg (0, ios::beg);
  while (getline(DNAinput >> ws, line)){
    cout << line << endl;
  }
}

int main(int argc, char** argv){

  if(argc >= 2)
  {
    string fileName = argv[1];
    ifstream DNAinput(fileName);
    ofstream fileOut("NikitaShetty.out");

    if (DNAinput.is_open() == false)
    {
      cout << "Invalid usage. Please give a readable data file name." << endl;
      return -1;
    }
    else{
      calcRelativeProbabilities(DNAinput, fileOut) ;
      calcStats(DNAinput, fileOut);

      DNAinput.close();
    }
  }
}
