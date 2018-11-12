#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include "simulation.h"

using namespace std;

string tester;
int temp,counter;
vector <int> virtualAddresses;
int pageSize [3] = {512,1024,2048};
int frames [4] = {4,8,12,300};
int pgoptions = 3;
int foptions = 4;

int main()
{
    virtualMemory virtualMem;
    cout << "CS 471 PROBLEM 2" << endl;
    ifstream inputFile("input2.dat");
    while (inputFile >> tester)
    {
    temp = atoi(tester.c_str());
    virtualAddresses.push_back(temp); //CREATES VECTOR OF INPUT #'S
    }
    virtualAddresses.begin();

    virtualMem.setup(virtualAddresses);

        virtualMem.frames = frames[0];

    //USE THREAD PROCESS TO ACCESS THIS.....
    ofstream outputFile;

    outputFile.open("Results.txt");
    outputFile << "\tPage size \t\t| #of pages  \t\t| Page replacement ALG \t\t| Page fault percentage\n";
    for(int t=0;t<3;t++)
    {
        for(int q=0;q<3;q++)
        {
            virtualMem.pageSize = pageSize[q];
            virtualMem.frames = frames[t];
            virtualMem.fifoSimulation();
    outputFile << virtualMem.returnpageSize() << "\t" << virtualMem.numberofpages << "\t" << virtualMem.returnALGtype() << "\t" << virtualMem.pageFault <<  "%  \n";
            virtualMem.lruSimulation();
    outputFile << virtualMem.returnpageSize() << "\t" << virtualMem.numberofpages << "\t" << virtualMem.returnALGtype() << "\t" << virtualMem.pageFault <<  "%  \n";
        }
    }


    outputFile.close();




    return 0;
}
