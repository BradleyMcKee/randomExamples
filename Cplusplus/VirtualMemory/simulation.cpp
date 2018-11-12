#include "simulation.h"

using namespace std;

void virtualMemory::setup(std::vector<int> virtualAddresses)
{
int counter,c2, virtualaddressLength;
int tempval;
double temp2;
inputsize = virtualAddresses.size();

pages.resize(numberofpages);
counter = 0;
c2 = 0;
virtualaddressLength = virtualAddresses.size();
for(int i =0; i<numberofpages;i++)
{
    while(counter < virtualaddressLength && c2 < pageSize )
    {

    tempval = virtualAddresses[counter];
    sortingmem.push_back(tempval);
    pages[i].push_back(tempval);
    //cout << tempval << "  " << c2 << endl;
        //INCREASE COUNTER UNTIL IT REACHES THE LENGTH OF THE FILE
        counter++;
        //INCREASE C2 UNTIL THE END OF THE PAGE (Last page won't be full)
        c2++;


    }
    //cout << "outtta loop " << endl;

    //RESET PAGE INDEX
    c2 = 0;
}
pageSize = pages[0].size();
temp2 = (double)inputsize/pageSize;
numberofpages = round(temp2);

}


void virtualMemory::output()
{

            cout << "first element page 1   "<< pages[0][0] << endl;
            cout << "first element page 2   "<< pages[1][0] << endl;
            cout << "first element page 3   "<< pages[2][0] << endl;
            cout << "first element page 4   "<< pages[3][0] << endl;
            cout << "first element page 5   "<< pages[4][0] << endl;
            cout << "first element page 6   "<< pages[5][0] << endl;

}
/*
    Find the location of the desired page on disk -> virtual addresses that need mapped.
    Find a free frame:
   If there is a free frame, use it
   If there is no free frame, use a page replacement algorithm to select a victim frame
*/
void virtualMemory::fifoSimulation()
{
    //FIRST IN FIRST OUT ALG - TAKE THE FIRST ONE THAT WAS INPUTTED AND REPLACE IT WITH THE NEWEST ADDRESS
    pageReplacementALG = "FIFO";
    int fifoarray[frames];
    pageFault = 0;
    int counter1 = 0;//BOOLEAN FLAG
    int counter2 = 0;
    int counter3 = 1;
    for(int h = 0;h < numberofpages ;h++)// ITERATES THROUGH THE PAGES
    {
    for(int i = 0;i < pageSize ;i++) // ITERATE THROUGH THE VIRTUALADDRESSES OF A PAGE
    {
        if(frames > i)//FILL UP FRAMES WITH VIRTUAL ADDRESSES AND COUNT IT
        {
            fifoarray[i] = pages[h][i];
            pageFault++;
        }
        if(i >= frames) //if i is greater than or equal to frames
        {
            for(int j = 0; j < frames;j++) // counter  less then amount of frames
            {
                if(fifoarray[j] == pages[h][i]) //current frame is equal to value in that page that index
                {
                    counter1 = -1;// make another if statement false
                    counter3++; //increments counter
                }
            }
            if(counter1 == 0) // IF TRUE THEN COUNT THE PAGE FAULT
            {
                fifoarray[counter2] = pages[h][i];
                pageFault++;
                counter3 = 0;
            }


             //if(fifoarray[j] == pages[h][i]) frame matches address
            if(counter3 > 1)
            {
                counter2++;
            }
            counter1 = 0; // reset it back to zero

            if(counter2 > frames)
            {
                counter2 = 1;
            }
        }
    }

    }


}

//   If there is a free frame, use it
//   If there is no free frame, use a page replacement algorithm to select a victim frame
void virtualMemory::lruSimulation()
{
    //LEAST RECENTLY USED ALG - TAKE THE LEAST USED FROM THE FRAMES AND REPLACE IT WITH CURRENT ADDRESS
    pageReplacementALG = "LRU";
    int lruarray[frames],fcount[frames];
    int counter = 0;
    pageFault = 0;
            bool isitpf = true;//BOOLEAN
            int whichoneisit = 1;
            for(int h = 0;h < numberofpages ;h++)// ITERATES THROUGH THE PAGES
            {
                for(int i = 0;i < pageSize ;i++) // ITERATE THROUGH THE VIRTUALADDRESSES OF A PAGE
                {
                        if(frames > i)//FILL UP FRAMES WITH VIRTUAL ADDRESSES AND COUNT IT
                        {
                        lruarray[i] = pages[h][i];
                        pageFault++;
                        }
                    for(int j = 0; j < frames;j++) // ITERATE THROUGH FRAMES
                    {
                        if(lruarray[j] == pages[h][i]) //if current frame is equal to value in that page that index
                        {
                            isitpf = false; // it is not a page fault because it is in main memory ALREADY
                            whichoneisit++; //figure out which one it is
                        }

                   if(whichoneisit>1)
                    {
                            for(int k=0;k<frames;k++)
                            {
                               if(lruarray[k] == lruarray[j])
                               {
                                   counter++;
                                   fcount[k] = counter;
                               }
                            }
                    }
                    isitpf = true;

                    }

                    if(isitpf == true) // if it is a pagefault
                    {
                     pageFault++;
                     whichoneisit = 1;
                        for(int l=0;l<frames;l++)
                        {
                            if(fcount[l]< counter) //replaces least used one.
                            {
                                lruarray[l] = pages[h][i];
                            }
                        }
                        counter = 0; //RESET COUNTER CAUSE WE FOUND WHICH ONE HAS THE LEAST COUNTS
                    }

                }
            }
}


void virtualMemory::mruSimulation()
{
     //LEAST RECENTLY USED ALG - TAKE THE LEAST USED FROM THE FRAMES AND REPLACE IT WITH CURRENT ADDRESS
    pageReplacementALG = "MRU";
    int lruarray[frames],fcount[frames];
    int counter = 0;
    pageFault = 0;
            bool isitpf = true;//BOOLEAN
            int whichoneisit = 1;
            for(int h = 0;h < numberofpages ;h++)// ITERATES THROUGH THE PAGES
            {
                for(int i = 0;i < pageSize ;i++) // ITERATE THROUGH THE VIRTUALADDRESSES OF A PAGE
                {
                        if(frames > i)//FILL UP FRAMES WITH VIRTUAL ADDRESSES AND COUNT IT
                        {
                        lruarray[i] = pages[h][i];
                        pageFault++;
                        }
                    for(int j = 0; j < frames;j++) // ITERATE THROUGH FRAMES
                    {
                        if(lruarray[j] == pages[h][i]) //if current frame is equal to value in that page that index
                        {
                            isitpf = false; // it is not a page fault because it is in main memory ALREADY
                            whichoneisit++; //figure out which one it is
                        }

                            if(whichoneisit>1)
                            {
                            for(int k=0;k<frames;k++)
                            {

                               if(lruarray[k] == lruarray[j])
                               {
                                   counter++;
                                   fcount[k] = counter;
                               }
                            }
                            }
                    isitpf = true;
                    }

                    if(isitpf == true) // if it is a pagefault
                    {
                     pageFault++;
                     whichoneisit = 1; //run which one is it to figure out the index of the frames has the lowest amount of fcount's
                        for(int l=0;l<frames;l++)
                        {
                            if(fcount[l] > counter) //replaces MOST used one.
                            {
                                lruarray[l] = pages[h][i];
                            }
                        }
                        counter = 0 ;//RESET COUNTER
                    }

                }
            }
}

void virtualMemory::optimalSimulation()
{
    //  LOOK AHEAD AT THE INDEXS AND SEE IF IT IS USED MORE THAN IT'S CURRENT USE IF SO DETERMINE DISTANCE
    pageFault = 0;



}


int virtualMemory::returnpageSize()
{
   return pageSize;
}
int virtualMemory::returnpf()
{
    return pageFault;
}

double virtualMemory::returnpageFault()
{
   double percentPF = 100* pageFault/inputsize;
   return percentPF;
}

int virtualMemory::returnNumofPages()
{
    return numberofpages;
}
string virtualMemory::returnALGtype()
{
    return pageReplacementALG;
}
