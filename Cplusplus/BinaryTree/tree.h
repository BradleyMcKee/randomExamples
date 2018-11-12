#include <iostream>
#include <list>
#include <ctime>
#include <cstddef>
#include <stdlib.h>
#include <vector>
#include <fstream>


struct node{
    char val;
    node *left;
    node *right;
    std::vector<char> myList;
};

class tree{
public:
        tree(){root = NULL;};
        ~tree(){};

void insertpair2(char c1,char c2)
{
if(root ==NULL)
{
        root = new node;
        root ->left = NULL;
        root ->right = NULL;
        root ->val = c1;
        root ->myList.push_back(c2);
}
else{
  insertpair(c1,c2,root);
}

}


void insertpair(char c1,char c2, node *current)
{
  if(c1 == current->val)
    current->myList.push_back(c2);
  if(c1<current->val)
  {
    if(current->left!=NULL)
     insertpair(c1,c2, current->left);
    else
    {
      current->left=new node;
      current->left->val=c1;
      current->left->myList.push_back(c2);
      current->left->left=NULL;
      current->left->right=NULL;
    }
  }
  else if(c1>current->val)
  {
    if(current->right!=NULL)
      insertpair(c1,c2, current->right);
    else
    {
      current->right=new node;
      current->right->val=c1;
      current->right->myList.push_back(c2);
      current->right->left=NULL;
      current->right->right=NULL;
    }
  }

}

void display()
{
    std::cout<< "DISPLAYING PAIRS OF CHARACTER TREE\n";
    makedisplay(root);
}

void makedisplay(node *p)
{

if(p !=NULL)
{
   if(p->left)
   makedisplay(p->left);
   std::cout << " "  << p->val << "( " ;
   for(int i=0;i<(p->myList.size());i++)
   {
       std::cout << p->myList[i] << " ";
   }
   std::cout << ")\n";
   if(p->right)
   makedisplay(p->right);
}
}

private:
        node* root;
};






