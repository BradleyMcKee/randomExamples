#ifndef BRIGHT_H
#define BRIGHT_H
#include "frame.h"

using namespace std;

class frame;

class bright
{
    public:
/*
        void setHistData(histEqual *h, vector<frame>& colorVector, vector<histEqual>& histVector);
        void computeCDF(vector<histEqual>& myVector);
        void computeHE(vector<histEqual>& myVector, int L, int M, int N);
        int getHEvalue(vector<histEqual>& myVector, int k);
        histEqual();
        void printToFile(vector<histEqual>& myVector);
*/
    private:
        int brighistBinValue;
        int histFreqValue;
        int cdfValue;
        int brightvalue;
};

#endif // BRIGHT_H
