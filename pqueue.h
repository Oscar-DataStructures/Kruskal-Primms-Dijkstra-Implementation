/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#ifndef _pqueue_h
#define _pqueue_h

#include <iostream>
#include <string>
#include "minHeap.h"

using namespace std;


template <class KeyType>
class MinPriorityQueue : public MinHeap<KeyType>
{
  public:
    MinPriorityQueue(int n = DEFAULT_SIZE);   // construct an empty MPQ with capacity n
    MinPriorityQueue(const MinPriorityQueue<KeyType>& pq);    // copy constructor
    // Destructor inherited from MinHeap<KeyType>

    KeyType* minimum() const;   // return the minimum element
    KeyType* extractMin();    // delete the minimum element and return it
    void decreaseKey(int index, KeyType* key);    // decrease the value of an element
    void insert(KeyType* key);    // insert a new element
    bool empty() const;   // return whether the MPQ is empty
    int length() const;   // return the number of keys
    std::string toString() const;   // return a string representation of the MPQ


    // Specify that MPQ will be referring to the following members of MinHeap<KeyType>.
    using MinHeap<KeyType>::A;
    using MinHeap<KeyType>::heapSize;
    using MinHeap<KeyType>::capacity;
    using MinHeap<KeyType>::parent;
    using MinHeap<KeyType>::swap;
    using MinHeap<KeyType>::heapify;
    using MinHeap<KeyType>::destroy;
    using MinHeap<KeyType>::buildHeap;
    /* The using statements are necessary to resolve ambiguity because
    these members do not refer to KeyType. Alternatively, you could
    use this->heapify(0) or MinHeap<KeyType>::heapify(0).
    */
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq);

class FullError { };    // MinPriorityQueue full exception
class EmptyError { };   // MinPriorityQueue empty exception
class KeyError { };   // MinPriorityQueue key exception

#include "pqueue.cpp"


#endif
