#include <iostream> //pre-processor directive
using namespace std;
class DNAStats{
public:
  DNAStats(); //default constructor
  DNAStats(double A_Count, double C_Count, double T_Count, double G_Count,
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
         double gaussian_A, double gaussian_B, double gaussian_C, double gaussian_D);
  ~DNAStats(); //destructor

  // calculates relative probability of each nucleotide and bigram
  void calcRelativeProbabilities(ifstream & DNAinput);

  // calculates mean, variance, and standard deviation
  void calcStats(ifstream & DNAinput);

  // prints all statistics to a text file
  void printStats(ofstream & fileOut);

  // calculates string lengths based on Gaussian Distribution and
  // prints new sequences of those length to text file
  void printGaussian(ofstream & fileOut);

  double ACount, CCount, TCount, GCount;
  double AACount, ACCount, ATCount, AGCount, CACount,
         CCCount, CTCount, CGCount, TACount, TCCount,
         TTCount, TGCount, GACount, GCCount, GTCount,
         GGCount;
  double AProb, CProb, TProb, GProb;
  double AAProb, ACProb, ATProb, AGProb, CAProb,
         CCProb, CTProb, CGProb, TAProb, TCProb,
         TTProb, TGProb, GAProb, GCProb, GTProb,
         GGProb;
  double stringCount, nucleotideCount, bigramCount;
  string bigram, DNAseq;
  double mean, varianceNumerator, variance, stdDev;
  double gaussianA, gaussianB, gaussianC;
  int gaussianD;
};
