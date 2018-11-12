#include <stdio.h>
#include <iostream>

//basically since I create programs on many different IDE's that process differently
//This was a test that I used to see if data was taken in through the big endian or little endian
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;

   if (*c)
   {
       printf("Little endian");
       std::cout << "\n" << &c << "\n";
   }
   else
   {
        printf("Big endian");
        std::cout << "\n" << &c << "\n";
   }

   getchar();
   return 0;
}
