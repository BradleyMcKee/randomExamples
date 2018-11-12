#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "frame.h"
#include "histequal.h"

using namespace std;

///=============================================================================================
//Function to create the vector arrays from the binary file's input character array
void frame::setInputData(frame *f, char a[], vector<frame>& myVector, int n)
{
    int i=0;
    vector<frame>::iterator it;

    for (i=0; i<n; i++)
    {
        myVector.push_back(*f);
    }

    it = myVector.begin();

    for (i=0; i<n; i++)
    {
        it->charBlock = a[i];
        it->intBlock = a[i];

        if (it->intBlock < 0)
        {
            it->intBlock = 256 + it->intBlock;
        }
        it++;
    }
}

///=============================================================================================
//function to get the vector arrays intBlock value
int frame::getIntBlockValue(vector<frame>& myVector, int i)
{
    return myVector[i].intBlock;
}

///=============================================================================================
//function to get the vector arrays charBlock value
char frame::getCharBlockValue(vector<frame>& myVector, int i)
{
    return myVector[i].charBlock;
}

///=============================================================================================
//function to calculate a decimal value from a 2 byte block in little endian format
int frame::compute2Bytes(vector<frame>& myVector, int k)
{
    int i=0, ans=0;

    ans = myVector[k].intBlock + (myVector[k+1].intBlock / 16) * 4096 + (myVector[k+1].intBlock % 16) * 256;

    return ans;
}

///=============================================================================================
//function to calculate a decimal value from a 4 byte block in little endian format
int frame::compute4Bytes(vector<frame>& myVector, int k)
{
    int i=0, ans=0;

    ans = myVector[k].intBlock + (myVector[k+1].intBlock / 16) * 4096 + (myVector[k+1].intBlock % 16) * 256
          + (myVector[k+2].intBlock / 16) * 1048576 + (myVector[k+2].intBlock % 16) * 65536
          + (myVector[k+3].intBlock / 16) * 268435456 + (myVector[k+3].intBlock % 16) * 16777216;

    return ans;
}

///=============================================================================================
//function to set a vector array to only contain the pixel data
//will handle pixel data with and without padding
//will sort the vector by intBlock values in ascending order
void frame::setHistogramVector(vector<frame>& myVector, int k, int w, int h)
{
    myVector.erase(myVector.begin(), myVector.begin()+k);
    sort(myVector.begin(), myVector.end());

    if (w%4 != 0)
    {
        myVector.erase(myVector.begin(), myVector.begin()+((4-w%4)*h));
    }
}

///=============================================================================================
//function to set HE data to the output vector array
//will handle output data with and without padding
void frame::setOutputData(vector<frame>& colorVector, vector<histEqual>& histVector, int k, int w)
{
    int i=0, j=0, w4=0, heValue=0;
    histEqual *h;
    h = new histEqual;

    w4 = w - (w % 4);

    if (w%4 == 0)
    {
        for (i=k; i<colorVector.size(); i++)
        {
            heValue = h->getHEvalue(histVector, colorVector[i].intBlock);
            if (heValue > 127)
            {
                heValue = heValue - 256;
            }
            colorVector[i].intBlock = heValue;
            colorVector[i].charBlock = heValue;
        }
    }
    else
    {
        heValue = h->getHEvalue(histVector, colorVector[k].intBlock);
        if (heValue > 127)
        {
            heValue = heValue - 256;
        }
        colorVector[k].intBlock = heValue;
        colorVector[k].charBlock = heValue;

        for (i=k+1; i<colorVector.size(); i++)
        {
            if ((i-k)%w4 == 0)
            {
                heValue = h->getHEvalue(histVector, colorVector[i].intBlock);
                if (heValue > 127)
                {
                    heValue = heValue - 256;
                }
                colorVector[i].intBlock = heValue;
                colorVector[i].charBlock = heValue;

                for (j=0; j<(4-(w%4)); j++)
                {
                    i++;
                }
            }
            else
            {
                heValue = h->getHEvalue(histVector, colorVector[i].intBlock);
                if (heValue > 127)
                {
                    heValue = heValue - 256;
                }
                colorVector[i].intBlock = heValue;
                colorVector[i].charBlock = heValue;
            }
        }
    }

    delete h;
}

///=============================================================================================
//function to set overlay data to the output vector array
//will handle output data with and without padding
void frame::setOverlay(vector<frame>& inVector, vector<frame>& olVector, int k, int w)
{
    int i=0, j=0, color=255, w4=0;

    w4 = w - (w % 4);

    if (w%4 == 0)
    {
        for (i=k; i<inVector.size(); i++)
        {
            if (olVector[i].intBlock != 255)
            {
                inVector[i].intBlock = color;
                inVector[i].charBlock = color;
            }
        }
    }
    else
    {
        if (olVector[k].intBlock != 255)
        {
            inVector[k].intBlock = color;
            inVector[k].charBlock = color;
        }
        for (i=k+1; i<inVector.size(); i++)
        {
            if ((i-k)%w4 == 0)
            {
                if (olVector[i].intBlock != 255)
                {
                    inVector[i].intBlock = color;
                    inVector[i].charBlock = color;
                }
                for (j=0; j<(4-(w%4)); j++)
                {
                    i++;
                }
            }
            else
                if (olVector[i].intBlock != 255)
                {
                    inVector[i].intBlock = color;
                    inVector[i].charBlock = color;
                }
        }
    }
}

///=============================================================================================
void frame::setBrightness(vector<frame>& myVector, int k, int b)
{
    int i=0, n=0, color=0;
    n = myVector.size();

    for (i=k; i<n; i++)
    {
        if (b>=0 && myVector[i].intBlock<=(255-b))
        {
            color = myVector[i].intBlock + b;
            myVector[i].charBlock = color;
        }
        if (b<0 && myVector[i].intBlock>=b)
        {
            color = myVector[i].intBlock + b;
            myVector[i].charBlock = color;
        }
    }
}

///=============================================================================================
void frame::setContrast(vector<frame>& myVector, int k, int c)
{
    int i=0, n=0, sum=0, mid=0, color=0;
    n = myVector.size();

    for (i=k; i<n; i++)
    {
        sum = sum + myVector[i].intBlock;
    }

    mid = sum / (n-k);

    cout << sum << "  " << "  " << n << "  " << k << "  " << mid << endl << endl;

    if (c >= 0)
    {
        for (i=k; i<n; i++)
        {
            if (myVector[i].intBlock<=mid && myVector[i].intBlock>=c)
            {
                color = myVector[i].intBlock - c;
                myVector[i].charBlock = color;
            }
            else if (myVector[i].intBlock>mid && myVector[i].intBlock<=(255-c))
            {
                color = myVector[i].intBlock + c;
                myVector[i].charBlock = color;
            }
            else if (myVector[i].intBlock<=mid && myVector[i].intBlock<c)
            {
                myVector[i].charBlock = 0;
            }
            else
            {
                myVector[i].charBlock = 255;
            }
        }
    }
    else
    {
        c = -c;
        for (i=k; i<n; i++)
        {
            if (myVector[i].intBlock<=mid && myVector[i].intBlock<=(mid-c))
            {
                color = myVector[i].intBlock + c;
                myVector[i].charBlock = color;
            }
            else if (myVector[i].intBlock>mid && myVector[i].intBlock>=(mid+c))
            {
                color = myVector[i].intBlock - c;
                myVector[i].charBlock = color;
            }
            else
            {
                myVector[i].charBlock = mid;
            }
        }
    }


}



///=============================================================================================
//Overloaded < operator for use with sort function
bool frame::operator < (const frame& rtside) const
{
    if (intBlock < rtside.intBlock)
    {
        return true;
    }
    return false;
}

///=============================================================================================
//constructor
frame::frame()
{
    char charBlock=' ';
    int intBlock=0;
}

///=============================================================================================
//function to output complete byte data of an input file
void frame::printToFile(vector<frame>& myVector, int n, int k, int a, int b, int c, int d, int e, int f)
{
    int i=0;
    ofstream outPrint;

    vector<frame>::iterator it;

    outPrint.open("output_all.txt");

    outPrint << "file size (and end of pixel data) is " << n << " Bytes" << endl
             << "pixel data start is " << k << " Bytes" << endl
             << "pixel width is " << a << " pixels" << endl
             << "pixel height is " << b << " pixels" << endl
             << "bits per pixel is " << c << " bits" << endl
             << "horizontal resolution is " << d << " pixels/meter" << endl
             << "vertical resolution is " << e << " pixels/meter" << endl
             << "number of colors is " << f << " colors" << endl << endl;
    outPrint << setw(12) << left << "Byte Loc" << setw(4) << left << "    " << setw(3) << left << "0" << setw(2) << left << "  "
             << setw(3) << left << "1" << setw(2) << left << "  " << setw(3) << left << "2" << setw(2) << left << "  " << setw(3) << left << "3" << setw(2) << left << "  "
             << setw(3) << left << "4" << setw(2) << left << "  " << setw(3) << left << "5" << setw(2) << left << "  " << setw(3) << left << "6" << setw(2) << left << "  "
             << setw(3) << left << "7" << setw(2) << left << "  " << setw(3) << left << "8" << setw(2) << left << "  " << setw(3) << left << "9" << setw(2) << left << "  "
             << setw(3) << left << "10" << setw(2) << left << "  " << setw(3) << left << "11" << setw(2) << left << "  " << setw(3) << left << "12" << setw(2) << left << "  "
             << setw(3) << left << "13" << setw(2) << left << "  " << setw(3) << left << "14" << setw(2) << left << "  " << setw(3) << left << "15" << setw(2) << left << "  "
             << endl;
    outPrint << "------------------------------------------------------------------------------------------------" << endl;

    for (it=myVector.begin(); it != myVector.end(); it++)
    {
        if (i == 0)
        {
            outPrint << setw(12) << right << i << setw(1) << left << ":" << setw(3) << "  " << setw(3) << left << it->intBlock << setw(2) << left << "  ";
            i++;
        }
        else if (i != 0 && i%16 == 0)
        {
            outPrint << endl;
            outPrint << setw(12) << right << i << setw(1) << left << ":" << setw(3) << "  " << setw(3) << left << it->intBlock << setw(2) << left << "  ";
            i++;
        }
        else
        {
            outPrint << setw(3) << left << it->intBlock << setw(2) << left << "  ";
            i++;
        }
    }

    outPrint.close();
}

///=============================================================================================
