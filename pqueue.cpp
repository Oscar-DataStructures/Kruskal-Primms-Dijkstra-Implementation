#include "pqueue.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;


#ifndef _pqueue_cpp
#define _pqueue_cpp

/*
defaul constructor
precondition:
int n is greater or equal to 0, if there is no parameter being passed, n=10
postcondition:
an empty heap with size 0 is created in an array with n capacity
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n)
{
  capacity = n;
  A = new KeyType*[capacity];
  heapSize = 0;
}


/*
construct heap from array
precondition:
initA is an array with size n
int n is the size of array initA
postcondition:
a MinHeap containing all items in array initA will be created
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType* initA[], int n)
{
  heapSize = n;
  capacity = heapSize*2;
  A = new KeyType*[capacity];
  for (int i=0; i<heapSize; i++){
    *(A[i]) = *(initA[i]);
  }
  buildHeap();
}

/*
copy constructor
precondition:
parameter heap is another object in class MinHeap
postcondition:
the heap calling this function would have all items in the heap being passed with original order
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
{
  if(this != &heap){
    destroy();
    copy(heap);
  }
}

/*
destructor
precondition:
an exsited MinHeap object
postcondition:
the memory being taken by this heap is freed and all information of this heap is reset to 0
*/
template <class KeyType>
MinHeap<KeyType>::~MinHeap()
{
  heapSize = 0;
  capacity = 0;
  destroy();
}

/*
heapsort, return result in sorted
precondition:
sorted is an array with a size equal or greater to the heap
postcondition:
the first n items in sorted is the items in the heap in ascending order
while the heap is no longer a Minheap but all items are sorted in decending order
*/
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType* sorted[])
{
  int origianl = heapSize;
  for (int i = 1; i<=origianl-1; i++){
    *(sorted[i-1]) = *(A[0]);
    swap(heapSize-1,0);
    heapSize -= 1;
    heapify(0);
  }
  *(sorted[origianl-1]) = *(A[0]);
  heapSize = origianl;
  for (int i=0; i<heapSize; i++){
    *(A[i]) = *(sorted[heapSize-1-i]);
  }
  buildHeap();
}

/*
return string representation
precondition:
the heap is existed with size greater or equal to 0
postcondition:
return an string representation of the heap, with all items seperated by ", "
*/
template <class KeyType>
std::string MinHeap<KeyType>::toString() const
{
  string result = "[";
  for(int i = 0; i < heapSize; i++){
    if (result!="[") result += ", ";
    result += to_string( *(A[i]) );
  }
  result += "]";
  return result;
}

/*
assignment operator
precondition:

postcondition:
*/
template <class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
{
  if(this != &heap){
    destroy();
    copy(heap);
  }
  return *this;
}

/*
heapify subheap rooted at index
precondition:
postcondition:
*/
template <class KeyType>
void MinHeap<KeyType>::heapify(int index)
{
  int l = leftChild(index);
  int r = rightChild(index);
  int smallest = index;
  if (l < heapSize){
    if ( *(A[l]) <= *(A[index]) )  smallest = l;
  }
  if (r < heapSize) {
    if ( *(A[r]) <= *(A[smallest]) )  smallest = r;
  }
  if (smallest != index) {
    swap(smallest,index);
    heapify(smallest);
  }
}

/*
build heap
precondition:
postcondition:
*/
template <class KeyType>
void MinHeap<KeyType>::buildHeap()
{
  for (int i= (heapSize/2)-1; i>=0; i--){
    heapify(i);
  }
}

/*
swap elements in A
precondition:

postcondition:

*/
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2)
{
  KeyType i = *(A[index1]);
  *(A[index1])= *(A[index2]);
  *(A[index2])= i;
}

/*
copy heap to this heap
precondition:
parameter heap is a differe
postcondition:
*/
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
{
  capacity = heap.capacity;
  A = new KeyType*[capacity];
  for (int i=0;i<heap.heapSize;i++){
     KeyType temp = *(heap.A[i]);
     A[i] = &temp;
  }
  heapSize = heap.heapSize;
}

/*
deallocate heap
precondition:
an existed heap object with an array containing its data
postcondition:
deallocate the array that's containing the heap
*/
template <class KeyType>
void MinHeap<KeyType>::destroy()
{
  for (int i = 0; i < heapSize; i++)
    {
        delete A[i];
    }
}


template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n): MinHeap<KeyType>(n)
{
} // construct an empty MPQ with capacity n

// copy constructor
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq):  MinHeap<KeyType>(pq)
{}

 // return the minimum element
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
  KeyType* a = A[0];
  return (a);
}

 // delete the minimum element and return it
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
{
  KeyType* newPointer = new KeyType(*(A[0]));
  swap(heapSize-1,0);
  heapSize--;
  buildHeap();
  return (newPointer);
}

// decrease the value of an element
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
  A[index] = key;
  buildHeap();
}

// insert a new element
template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
{
  heapSize++;
  if (heapSize>=capacity) {
    KeyType** temp = A;
    capacity *=2;
    A = new KeyType*[capacity];
    for (int i=0;i<heapSize-1;i++){
      A[i]= temp[i];
    }
  }
  A[heapSize-1] = key;
  if (heapSize>1){
    buildHeap();
  }
}

// return whether the MPQ is empty
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
  return (!heapSize);
}

// return the number of keys
template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
{
  return heapSize;
}

// return a string representation of the MPQ
template <class KeyType>
string MinPriorityQueue<KeyType>::toString() const
{
  string result = "[";
  for(int i = 0; i < heapSize; i++){
    if (result!="[") result += ", ";
    result +=to_string(*(A[i]));
  }
  result += "]";
  return result;
}
/*
//
template <class KeyType>
string to_string(const node<KeyType>& node)
{
  string result;
  result = node.key;
  result = result + " : "+ to_string(node.priority);
  return result;
}
*/
#endif
