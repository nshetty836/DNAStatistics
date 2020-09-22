//implementation .cpp file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "DNAStats.h"

// default constructor
DNAStats::DNAStats(){
  double ACount = 0.0, CCount = 0.0, TCount = 0.0, GCount = 0.0;
  double AACount = 0.0, ACCount = 0.0, ATCount = 0.0, AGCount = 0.0, CACount = 0.0,
         CCCount = 0.0, CTCount = 0.0, CGCount = 0.0, TACount = 0.0, TCCount = 0.0,
         TTCount = 0.0, TGCount = 0.0, GACount = 0.0, GCCount = 0.0, GTCount = 0.0,
         GGCount = 0.0;
  double AProb = 0.0, CProb = 0.0, TProb = 0.0, GProb = 0.0;
  double AAProb = 0.0, ACProb = 0.0, ATProb = 0.0, AGProb = 0.0, CAProb = 0.0,
         CCProb = 0.0, CTProb = 0.0, CGProb = 0.0, TAProb = 0.0, TCProb = 0.0,
         TTProb = 0.0, TGProb = 0.0, GAProb = 0.0, GCProb = 0.0, GTProb = 0.0,
         GGProb = 0.0;
  double stringCount = 0.0, nucleotideCount = 0.0, bigramCount = 0.0;
  string bigram, DNAseq;
  double mean = 0.0, varianceNumerator = 0.0, variance = 0.0, stdDev = 0.0;
  double gaussianA = 0.0, gaussianB = 0.0, gaussianC = 0.0, gaussianD = 0.0;
}

// overloaded constructor
DNAStats::DNAStats(double A_Count, double C_Count, double T_Count, double G_Count,
       double AA_Count, double AC_Count, double AT_Count, double AG_Count, double CA_Count,
       double CC_Count, double CT_Count, double CG_Count, double TA_Count, double TC_Count,
       double TT_Count, double TG_Count, double GA_Count, double GC_Count, double GT_Count,
       double GG_Count, double A_Prob, double C_Prob, double T_Prob, double G_Prob,
       double AA_Prob, double AC_Prob, double AT_Prob, double AG_Prob, double CA_Prob,
       double CC_Prob, double CT_Prob, double CG_Prob, double TA_Prob, double TC_Prob,
       double TT_Prob, double TG_Prob, double GA_Prob, double GC_Prob, double GT_Prob,
       double GG_Prob, double string_Count, double nucleotide_Count, double bigram_Count,
       string bigram_, string DNA_seq,
       double mean_, double variance_Numerator, double variance_, double std_Dev,
       double gaussian_A, double gaussian_B, double gaussian_C, double gaussian_D){
  ACount = A_Count, CCount = C_Count, TCount = T_Count, GCount = G_Count;
  AACount = AA_Count, ACCount = AC_Count, ATCount = AT_Count, AGCount = AG_Count, CACount = CA_Count,
  CCCount = CC_Count, CTCount = CT_Count, CGCount = CG_Count, TACount = TA_Count, TCCount = TC_Count,
  TTCount = TT_Count, TGCount = TG_Count, GACount = GA_Count, GCCount = GC_Count, GTCount = GT_Count,
  GGCount = GG_Count;
  AProb = A_Prob, CProb = C_Prob, TProb = T_Prob, GProb = G_Prob;
  AAProb = AA_Prob, ACProb = AC_Prob, ATProb = AT_Prob, AGProb = AG_Prob, CAProb = CA_Prob,
  CCProb = CC_Prob, CTProb = CT_Prob, CGProb = CG_Prob, TAProb = TA_Prob, TCProb = TC_Prob,
  TTProb = TT_Prob, TGProb = TG_Prob, GAProb = GA_Prob, GCProb = GC_Prob, GTProb = GT_Prob,
  GGProb = GG_Prob;
  stringCount = string_Count, nucleotideCount = nucleotide_Count, bigramCount = bigram_Count;
  bigram = bigram_, DNAseq = DNA_seq;
  mean = mean_, varianceNumerator = variance_Numerator, variance = variance_, stdDev = std_Dev;
  gaussianA = gaussian_A, gaussianB = gaussian_B, gaussianC = gaussian_C, gaussianD = gaussian_D;
}

//calculates the relative probabilities of nucleotides and bigrams
void DNAStats::calcRelativeProbabilities(ifstream & DNAinput){
   while (getline(DNAinput >> ws, DNAseq))
   {
     transform(DNAseq.begin(), DNAseq.end(),DNAseq.begin(), ::toupper);
     nucleotideCount += DNAseq.length()-1;
     stringCount++;
     char nucleotide;

     //looping through sequence to count nucleotides and bigrams
     for(int i = 0; i < DNAseq.length(); ++i)
     {
       nucleotide = DNAseq.at(i);
       if(nucleotide == 'A' || nucleotide == 'C' ||
          nucleotide == 'T' || nucleotide == 'G')
       {
         if(nucleotide == 'A')
            ACount++;
         else if(nucleotide == 'C')
            CCount++;
         else if(nucleotide == 'T')
            TCount++;
         else if(nucleotide == 'G')
            GCount++;

         //if sequence has an odd number of nucleotides, pair last nucleotide with first
         if(DNAseq.length()%2 == 0 && i == DNAseq.length()-2){
           string oddBigram{DNAseq.at(i), DNAseq.at(0)};
           if(oddBigram == "AA")
              AACount++;
           if(oddBigram == "AC")
              ACCount++;
           if(oddBigram == "AT")
              ATCount++;
           if(oddBigram == "AG")
              AGCount++;
           if(oddBigram == "CA")
              CACount++;
           if(oddBigram == "CC")
              CCCount++;
           if(oddBigram == "CT")
              CTCount++;
           if(oddBigram == "CG")
              CGCount++;
           if(oddBigram == "TA")
              TACount++;
           if(oddBigram == "TC")
              TCCount++;
           if(oddBigram == "TT")
              TTCount++;
           if(oddBigram == "TG")
              TGCount++;
           if(oddBigram == "GA")
              GACount++;
           if(oddBigram == "GC")
              GCCount++;
           if(oddBigram == "GT")
              GTCount++;
           if(oddBigram == "GG")
              GGCount++;
           bigramCount++;
         }

         //counting the bigrams of each sequence
         if(i % 2 == 0 && i != DNAseq.length()-1){
           if(DNAseq.substr(i,2) == "AA")
              AACount++;
           if(DNAseq.substr(i,2) == "AC")
              ACCount++;
           if(DNAseq.substr(i,2) == "AT")
              ATCount++;
           if(DNAseq.substr(i,2) == "AG")
              AGCount++;
           if(DNAseq.substr(i,2) == "CA")
              CACount++;
           if(DNAseq.substr(i,2) == "CC")
              CCCount++;
           if(DNAseq.substr(i,2) == "CT")
              CTCount++;
           if(DNAseq.substr(i,2) == "CG")
              CGCount++;
           if(DNAseq.substr(i,2) == "TA")
              TACount++;
           if(DNAseq.substr(i,2) == "TC")
              TCCount++;
           if(DNAseq.substr(i,2) == "TT")
              TTCount++;
           if(DNAseq.substr(i,2) == "TG")
              TGCount++;
           if(DNAseq.substr(i,2) == "GA")
              GACount++;
           if(DNAseq.substr(i,2) == "GC")
              GCCount++;
           if(DNAseq.substr(i,2) == "GT")
              GTCount++;
           if(DNAseq.substr(i,2) == "GG")
              GGCount++;
           bigramCount++;
         }
       }
     }
   }

   //calculating all relative probabilities of nucleotides and bigrams
   AProb = ACount / nucleotideCount;
   CProb = CCount / nucleotideCount;
   TProb = TCount / nucleotideCount;
   GProb = GCount / nucleotideCount;

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

//calculates the mean, variance, and standard deviation of string lengths
void DNAStats::calcStats(ifstream & DNAinput){
  DNAinput.clear();
  DNAinput.seekg (0, ios::beg);
  mean = nucleotideCount / stringCount;
  while (getline(DNAinput >> ws, DNAseq)){
    varianceNumerator += pow((DNAseq.length()-1) - mean, 2);
  }
  variance = varianceNumerator / stringCount;
  stdDev = sqrt(variance);
}

//prints all statistics to a text file
void DNAStats::printStats(ofstream & fileOut){
  fileOut << "Nikita Shetty" << endl;
  fileOut << "Student ID: 2350802" << endl;
  fileOut << "Class: CPSC 350" << endl;
  fileOut << "Date: 9/21/2020\n" << endl;
  fileOut << "Assignment 1" << endl;


  fileOut << "The Sum of the length of the DNA strings is: " << nucleotideCount << endl;
  fileOut << "The Mean of the length of the DNA strings is: " << mean << endl;
  fileOut << "The Variance of the length of the DNA strings is: " << variance << endl;
  fileOut << "The Standard Deviation of the length of the DNA strings is: " << stdDev << endl;

  fileOut << "\nHere is the relative probability of each nucleotide: " << endl;
  fileOut << "A: " << AProb << endl;
  fileOut << "C: " << CProb << endl;
  fileOut << "T: " << TProb << endl;
  fileOut << "G: " << GProb << endl;

  fileOut << "\nHere is the relative probability of each nucleotide bigram:" << endl;
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

//calculates length of sequence from a Gaussian Distribution and prints new sequences to a text file
void DNAStats::printGaussian(ofstream & fileOut){
  double randProbability;
  string newSeq;
  fileOut << "\n1000 DNA sequences following the Gaussian Distribution: " << endl;
  for(int i = 0; i < 1000; ++i){
    newSeq = "";
    //generating two random numbers from 0 to 1
    gaussianA = (double)rand() / (RAND_MAX + 1.0);
    gaussianB = (double)rand() / (RAND_MAX + 1.0);

    gaussianC = sqrt((-2) * log(gaussianA)) * cos(2 * M_PI * gaussianB);
    gaussianD = round(stdDev * gaussianC + mean);
    if(gaussianD < 1)
      gaussianD = 1;

    //generating random sequences of gaussian length based on relative probability of the nucleotides
    for(int j = 0; j < gaussianD; ++j){
      randProbability = (double)rand() / (RAND_MAX + 1.0);
      if (randProbability <= AProb)
        newSeq += "A";
      else if(randProbability <= (AProb+CProb))
        newSeq += "C";
      else if(randProbability <= (AProb + CProb + TProb))
        newSeq += "T";
      else if(randProbability <= (AProb + CProb + TProb + GProb))
        newSeq += "G";
    }
    fileOut << newSeq << endl;
  }
}

//destructor
DNAStats::~DNAStats(){
}
