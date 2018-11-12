#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <math.h>
/*
struct pages{
    int pageNum;
    std::vector<int> addresses;

    void offset(int currentpage,int idk);
};
*/

struct virtualMemory{

    int numberofpages;// WE DETERMINE THIS BY DOING TOTAL ENTRIES/PAGESIZE
    std::vector <int> sortingmem;
    /*
        FOR PAGE SIZE:
        [3] = {512,1024,2048} THIS IS THE NUMBER OF WORDS
        1 word = 32 bits of information
        512 * 32 =
        1024 * 32 =
        2048 * 32 =
     */
    int pageSize;

    std::string pageReplacementALG;
    /*
        [3] = {4,8,12} THIS IS THE NUMBER OF FRAME SIZES

    */
    int frames;

//pages page;
    std::vector <std::vector<int> > pages;
    int inputsize;
    int pageFault;  //Increment when page fault occurs and increment it after new number is loaded into frame.
    double percentPF;

void setup(std::vector<int> virtualAddresses);

void output();


void fifoSimulation();

void lruSimulation();

void mruSimulation();

void optimalSimulation();

int returnpageSize();
int returnpf();
int returnNumofPages();
double returnpageFault();
std::string returnALGtype();

};



#endif
