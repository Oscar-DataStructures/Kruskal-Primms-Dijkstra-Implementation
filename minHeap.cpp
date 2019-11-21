/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <iostream>
#include <string>

using namespace std;


// ========================== Default Constructor ==============================
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n)
//Preconditions:  greater or equal to 0, if there is no parameter being passed, n=10
//Postcondition:  an empty heap with size 0 is created in an array with n capacity
{
  capacity = n;
  A = new KeyType*[capacity];
  heapSize = 0;
}


// ========================== Constructor From Heap ============================
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType* initA[], int n)
//Preconditions:  initA is an array with size n, int n is the size of array initA
//Postcondition:  a MinHeap containing all items in array initA will be created
{
  heapSize = n;
  capacity = heapSize*2;
  A = new KeyType*[capacity];
  for (int i=0; i<heapSize; i++)
  {
    *(A[i]) = *(initA[i]);
  }

  buildHeap();
}


// =========================== Copy Constructor ================================
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
//Preconditions:  parameter heap is another object in class MinHeap
//Postcondition:  the heap calling this function would have all items in the heap being passed with original order
{
  if(this != &heap)
  {
    destroy();
    copy(heap);
  }
}


// ============================= Deconstructor =================================
template <class KeyType>
MinHeap<KeyType>::~MinHeap()
//Preconditions:  an exsited MinHeap object
//Postcondition:  the memory being taken by this heap is freed and all information of this heap is reset to 0
{
  heapSize = 0;
  capacity = 0;
  destroy();
}


// =========================== Heap Sort Method ================================
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType* sorted[])
//Preconditions:  sorted is an array with a size equal or greater to the heap
//Postcondition:  the first n items in sorted is the items in the heap in ascending order while the heap is no longer a Minheap but all items are sorted in decending order
{
  int origianl = heapSize;
  for (int i = 1; i<=origianl-1; i++)
  {
    *(sorted[i-1]) = *(A[0]);
    swap(heapSize-1,0);
    heapSize -= 1;
    heapify(0);
  }

  *(sorted[origianl-1]) = *(A[0]);
  heapSize = origianl;
  for (int i=0; i<heapSize; i++)
  {
    *(A[i]) = *(sorted[heapSize-1-i]);
  }

  buildHeap();
}


// =========================== To String Method ================================
template <class KeyType>
std::string MinHeap<KeyType>::toString() const
//Preconditions:  the heap is existed with size greater or equal to 0
//Postcondition:  return an string representation of the heap, with all items seperated by ", "
{
  string result = "[";
  for(int i = 0; i < heapSize; i++)
  {
    if (result!="[") result += ", ";
    result += to_string( *(A[i]) );
  }

  result += "]";

  return result;
}


// =========================== Assignment Method ===============================
template <class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
//Preconditions:  N/A
//Postcondition:  N/A
{
  if(this != &heap)
  {
    destroy();
    copy(heap);
  }

  return *this;
}


// ============================ Heapify Method =================================
template <class KeyType>
void MinHeap<KeyType>::heapify(int index)
//Preconditions:  N/A
//Postcondition:  N/A
{
  int l = leftChild(index);
  int r = rightChild(index);
  int smallest = index;

  if (l < heapSize)
  {
    if ( *(A[l]) <= *(A[index]) )  smallest = l;
  }

  if (r < heapSize)
  {
    if ( *(A[r]) <= *(A[smallest]) )  smallest = r;
  }

  if (smallest != index)
  {
    swap(smallest,index);
    heapify(smallest);
  }
}


// =========================== Build Heap Method ===============================
template <class KeyType>
void MinHeap<KeyType>::buildHeap()
//Preconditions:  N/A
//Postcondition:  N/A
{
  for (int i= (heapSize/2)-1; i>=0; i--)
  {
    heapify(i);
  }
}


// ============================== Swap Method ==================================
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2)
//Preconditions:  N/A
//Postcondition:  N/A
{
  KeyType i = *(A[index1]);
  *(A[index1])= *(A[index2]);
  *(A[index2])= i;
}


// ============================== Copy Method ==================================
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
//Preconditions:  N/A
//Postcondition:  N/A
{
  capacity = heap.capacity;
  A = new KeyType*[capacity];
  for (int i=0;i<heap.heapSize;i++)
  {
     KeyType temp = *(heap.A[i]);
     A[i] = &temp;
  }

  heapSize = heap.heapSize;
}


// ============================ Destroy Method =================================
template <class KeyType>
void MinHeap<KeyType>::destroy()
//Preconditions:  an existed heap object with an array containing its data
//Postcondition:  deallocate the array that's containing the heap
{
  for (int i = 0; i < heapSize; i++)
  {
    delete A[i];
  }
}
