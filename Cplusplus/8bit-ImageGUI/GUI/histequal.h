#ifndef HISTEQUAL_H
#define HISTEQUAL_H
#include <iostream>
#include <fstream>
#include <vector>
#include "frame.h"

using namespace std;

class frame;

class histEqual
{
    public:
        void setHistData(histEqual *h, vector<frame>& colorVector, vector<histEqual>& histVector);
       void computeCDF(vector<histEqual>& myVector);
        void computeHE(vector<histEqual>& myVector, int L, int M, int N);
        int getHEvalue(vector<histEqual>& myVector, int k);
        histEqual();
        void printToFile(vector<histEqual>& myVector);

    private:
        int histBinValue;
        int histFreqValue;
        int cdfValue;
        int heValue;
};

#endif // HISTEQUAL_H
