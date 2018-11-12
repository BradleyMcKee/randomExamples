#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "histequal.h"
#include "frame.h"

using namespace std;

///=============================================================================================
void histEqual::setHistData(histEqual *h, vector<frame>& colorVector, vector<histEqual>& histVector)
{
    int i=0, n=0, bin=0, freq=1;

    frame *f;
    f = new frame;

    n = colorVector.size();

    bin = f->getIntBlockValue(colorVector, 0);
    for (i=1; i<=n; i++)
    {
        if (f->getIntBlockValue(colorVector, i) == bin)
        {
            freq++;
        }
        else
        {
            h->histBinValue = bin;
            h->histFreqValue = freq;
            h->cdfValue = 0;
            h->heValue = 0;
            histVector.push_back(*h);
            bin = f->getIntBlockValue(colorVector, i);
            freq = 1;
        }
    }

    delete f;
}

///=============================================================================================
void histEqual::computeCDF(vector<histEqual>& myVector)
{
    int sum=0;

    vector<histEqual>::iterator it;

    for (it=myVector.begin(); it != myVector.end(); it++)
    {
        it->cdfValue = sum + it->histFreqValue;
        sum = sum + it->histFreqValue;
    }
}

///=============================================================================================
void histEqual::computeHE(vector<histEqual>& myVector, int L, int M, int N)
{
    int cdfMin=1, heRound=0;
    double he=0.0, r=0.0;

    vector<histEqual>::iterator it;

    it = myVector.begin();
    if (it->cdfValue == 0)
        it++;
    cdfMin = it->cdfValue;

    for (it=myVector.begin(); it != myVector.end(); it++)
    {
        he = ((static_cast<double>(it->cdfValue) - static_cast<double>(cdfMin)) / (static_cast<double>(M) * static_cast<double>(N) - 1.0)) * (static_cast<double>(L) - 1.0);
        heRound = static_cast<int>(he);
        r = he - static_cast<double>(heRound);
        if (r > .5)
            it->heValue = heRound + 1;
        else
            it->heValue = heRound;
    }
}

///=============================================================================================
int histEqual::getHEvalue(vector<histEqual>& myVector, int k)
{
    int binMin=0, binMax=0, binMid=0;

    binMax = myVector.size();
    binMid = (binMin + binMax) / 2;

    while ((myVector[binMid].histBinValue != k) && (binMin <= binMax))
    {
        if (k < myVector[binMid].histBinValue)
        {
            binMax = binMid - 1;
        }
        else
        {
            binMin = binMid + 1;
        }
        binMid = (binMin + binMax) / 2;
    }
    if (binMin <= binMax)
    {
        return myVector[binMid].heValue;
    }
    else
    {
        return -1;
    }
}

///=============================================================================================
histEqual::histEqual()
{
    int histBinValue = 0;
    int histFreqValue = 0;
    int cdfValue = 0;
    int heValue = 0;
}

///=============================================================================================
void histEqual::printToFile(vector<histEqual>& myVector)
{
    ofstream outPrint;

    vector<histEqual>::iterator it;

    outPrint.open("output_hist_data.txt");

    outPrint << setw(8) << left << "Bin" << setw(12) << left << "Frequency" << setw(8) << left << "CDF" << setw(8) << left << "HE" << endl;
    outPrint << "------------------------------------" << endl;

    for (it=myVector.begin(); it != myVector.end(); it++)
    {
        outPrint << setw(8) << left << it->histBinValue << setw(12) << left << it->histFreqValue << setw(8) << left << it->cdfValue << setw(8) << left << it->heValue << endl;
    }

    outPrint.close();
}
///=============================================================================================
