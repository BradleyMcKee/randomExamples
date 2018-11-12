//c++ program for encapsulation
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;
// I used this file to help demonstrate to a few classmates in college on how data encapsulation works in C++

class encapsulatedData
{
  private:
    int x;
    int y;

    public:
      //make functions that will pass private variables;
      void setx(int a)
      {
        x = a;
      }
      void sety(int b)
      {
        y = b;
      }
      int getx()
      {
        return x;
      }
      int gety()
      {
        return y;
      }
};

//main function
int main()
{
  int pointx, pointy;
 encapsulatedData obj [100];

//This for-loop basically populates the obj array of 100 indexes
for(int i =0;i<100;i++)
{
  pointx = rand() % 100;
  pointy = rand() % 100;
  //set these points to x and y
  obj[i].setx(pointx);
  obj[i].sety(pointy);
}

//just a test print to make sure data is being generated
for(int l = 0; l<10;l++)
{
   cout << obj[l].getx() << "   " ;
   cout << obj[l].gety() << "\n";
}

 return 0;
}
