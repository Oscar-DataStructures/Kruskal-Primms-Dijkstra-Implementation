/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <typeinfo>
#include "pqueue.h"

using namespace std;


// =============== Test Default Constructor/toString/Empty Method ==============
void test_default_toString_empty()
{
  MinPriorityQueue<int> mpq0;
  MinPriorityQueue<int> mpq1(3);
  MinPriorityQueue<float> mpq0_f(20);

  assert(mpq0.toString()=="[]");
  assert(mpq0.empty()==true);
  assert(mpq1.empty()==true);
  assert(mpq1.toString()=="[]");
  assert(mpq0_f.toString()=="[]");
  assert(mpq0_f.empty()==true);
}


// ========================== Test Insert/Length Method ========================
void test_insert_length()
{
  MinPriorityQueue<int> mpq0;
  MinPriorityQueue<int> mpq1(3);

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
}


// ========================= Test Min/extractMin Method ========================
void test_min_extractMin()
{
  MinPriorityQueue<int> mpq0;
  MinPriorityQueue<int> mpq1(3);
  MinPriorityQueue<float> mpq0_f(20);

  //testing insert and length methods
  int a=3;
  int* a_p = &a;
  mpq1.insert(a_p);

  int intarray[11] = {11,15,20,7,17,20,500,15,0,6,8};
  for (int i=0;i<11;i++)
  {
    mpq0.insert(&intarray[i]);
  }

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
}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_default_toString_empty();
	std::cout << "Constructor/Empty/ToString Test	|Passed|" << std::endl;
	test_insert_length();
	std::cout << "Insert/Length Test		|Passed|" << std::endl;
	test_min_extractMin();
	std::cout << "Min/ExtractMin  Test		|Passed|" << std::endl;


	return 0;
}
