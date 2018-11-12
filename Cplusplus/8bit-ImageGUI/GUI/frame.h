#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include <cmath>
using namespace std;

class histEqual;

class frame
{
    public:
    void setInputData(frame *f, char a[], vector<frame>& myVector, int n);
    int getIntBlockValue(vector<frame>& myVector, int i);
    char getCharBlockValue(vector<frame>& myVector, int i);
    int compute2Bytes(vector<frame>& myVector, int k);
    int compute4Bytes(vector<frame>& myVector, int k);
    void setHistogramVector(vector<frame>& myVector, int k, int w, int h);
    void setOutputData(vector<frame>& colorVector, vector<histEqual>& histVector, int k, int w);
    void setOverlay(vector<frame>& inVector, vector<frame>& olVector, int k, int w);
    void setBrightness(vector<frame>& myVector, int k, int b);
    void setContrast(vector<frame>& myVector, int k, int c);
    bool operator < (const frame& rtside) const;
    frame();
    void printToFile(vector<frame>& myVector, int n, int k, int a, int b, int c, int d, int e, int f);

        private:
        char charBlock;
        int intBlock;
};

#endif // FRAME_H
