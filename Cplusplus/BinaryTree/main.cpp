#include "tree.h"
using namespace std;


int main()
{
    int numberofpairs;
    int menunum;
    tree chartree;
    /* NODE WORKS!!
    chartree.insertpair2('x','y');
    chartree.insertpair2('x','r');
    chartree.insertpair2('f','e');
    chartree.insertpair2('y','z');
*/
    char c1,c2;
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int randchar1,randchar2;
    string npair; //expect (A,E)
    cout << "Node Driver Menu" << endl
         << "1. Load Pairs from .txt file" << endl
         << "2. Generate random pairs" << endl
         << "3. Display pairs" << endl
         << "4. Exit" << endl
         << "Please Enter a Number to continue:  ";
    cin  >> menunum;
    cout << endl;


    if(menunum == 1)
    {

       ifstream input;
       input.open("inputfile.txt");
       if(!input)
       {
           cout << "THE FILE DOESN'T EXIST" << endl;
           return 1;

       }
        if(input.is_open())
        {
            char space;
            while(input >> c1  >> c2)
            {
        chartree.insertpair2(c1,c2);
            }
            input.close();
        }
        /*
        do{
         input >> c1 >> c2;
         chartree.insertpair2(c1,c2);

        }while(!input.eof());

*/     input.close();
       chartree.display();
    }
    else if(menunum == 2)
    {
        cout << "How many random pairs would you like to make?" << endl;
        cin >> numberofpairs;

        for(int i=0;i<numberofpairs;i++)
        {
        randchar1 = rand() %26; //RANG FROM 0 - 26
        randchar2 = rand() %26;

        chartree.insertpair2(alphabet[randchar1],alphabet[randchar2]);
        }
    chartree.display();
    }


    else if(menunum == 3)
    {
    cout << "Displaying Pairs" << endl;
        chartree.display();
    }
    else
    {
    cout << "GoodBye!";
    return 0;
    }

return 0;
}
