/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


// ========================== Default Constructor ==============================
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n): MinHeap<KeyType>(n)
//Preconditions:  N/A
//Postcondition:  N/A
{
  // construct an empty MPQ with capacity n
}


// =========================== Copy Constructor ================================
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq):  MinHeap<KeyType>(pq)
//Preconditions:  N/A
//Postcondition:  N/A
{

}


// ============================= Minimum Method ================================
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
//Preconditions:  N/A
//Postcondition:  N/A
{
  KeyType* a = A[0];

  return (a);
}


// =========================== Extract Min Method ==============================
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
//Preconditions:  N/A
//Postcondition:  N/A
{
  KeyType* newPointer = new KeyType(*(A[0]));
  swap(heapSize-1,0);
  heapSize--;
  buildHeap();

  return (newPointer);
}


// ===========================Decrease Key Method ==============================
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
//Preconditions:  N/A
//Postcondition:  N/A
{
  A[index] = key;
  buildHeap();
}


// ============================ Insert Method ==================================
template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
//Preconditions:  N/A
//Postcondition:  N/A
{
  heapSize++;
  if (heapSize>=capacity)
  {
    KeyType** temp = A;
    capacity *=2;
    A = new KeyType*[capacity];

    for (int i=0;i<heapSize-1;i++)
    {
      A[i]= temp[i];
    }
  }

  A[heapSize-1] = key;
  if (heapSize>1)
  {
    buildHeap();
  }
}


// ============================== Empty Method =================================
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
//Preconditions:  N/A
//Postcondition:  N/A
{
  return (!heapSize);
}



// ============================== Length Method ================================
template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
//Preconditions:  N/A
//Postcondition:  N/A
{
  return heapSize;
}


// =========================== To String Method ================================
template <class KeyType>
string MinPriorityQueue<KeyType>::toString() const
//Preconditions:  N/A
//Postcondition:  N/A
{
  string result = "[";
  for(int i = 0; i < heapSize; i++)
  {
    if (result!="[") result += ", ";
    result +=to_string(*(A[i]));
  }

  result += "]";
  return result;
}
