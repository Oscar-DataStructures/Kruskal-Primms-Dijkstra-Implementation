#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <typeinfo>
#include "pqueue.h"
using namespace std;

int main(){

  //testing two template constructors and the node class
  MinPriorityQueue<int> mpq0;
  MinPriorityQueue<int> mpq1(3);
  MinPriorityQueue<float> mpq0_f(20);
  MinPriorityQueue< node<string> > mpq0_n(20);
  //test both empty and toString method
  assert(mpq0.toString()=="[]");
  assert(mpq0.empty()==true);
  assert(mpq1.empty()==true);
  assert(mpq1.toString()=="[]");
  assert(mpq0_f.toString()=="[]");
  assert(mpq0_f.empty()==true);
  assert(mpq0_n.empty()==true);
  assert(mpq0_n.toString()=="[]");


  //testing insert and length methods
  int a=3;
  int* a_p = &a;
  mpq1.insert(a_p);
  assert(mpq1.toString()=="[3]");
  assert(mpq1.length()==1);

  int intarray[11] = {11,15,20,7,17,20,500,15,0,6,8};
  for (int i=0;i<11;i++){
    mpq0.insert(&intarray[i]);
  }
  assert(mpq0.length()==11);
  assert(mpq0.toString()=="[0, 6, 20, 11, 7, 20, 500, 15, 15, 17, 8]");


  //test the minimum method and the extractMin method
  a_p = mpq0.minimum();
  assert((*a_p)==0);
  assert(mpq0.length()==11);
  int* d;
  d = mpq0.extractMin();
  assert(mpq0.length()==10);
  assert((*d)==0);
  assert(mpq0.toString()=="[6, 7, 20, 11, 8, 20, 500, 15, 15, 17]");
  int e = 9; int* e_p = &e;
  mpq0.decreaseKey(3, e_p);
  assert(mpq0.toString()=="[6, 7, 20, 9, 8, 20, 500, 15, 15, 17]");
  *e_p = 5;
  mpq0.decreaseKey(3, e_p);
  assert(mpq0.toString()=="[5, 6, 20, 7, 8, 20, 500, 15, 15, 17]");

  
  //testing the destructor
  mpq0.~MinPriorityQueue();
  mpq1.~MinPriorityQueue();


  cout<< "all tests are passed successfully" <<endl;

  return 0;
}
