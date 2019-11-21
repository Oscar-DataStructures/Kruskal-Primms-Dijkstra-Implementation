#include <iostream>
#include <string>
using namespace std;

#ifndef _pqueue_h
#define _pqueue_h
const int DEFAULT_SIZE = 10;


template <class KeyType>
class MinHeap
{
  public:
    MinHeap(int n = DEFAULT_SIZE); // default constructor
    MinHeap(KeyType* initA[], int n); // construct heap from array
    MinHeap(const MinHeap<KeyType>& heap); // copy constructor
    ~MinHeap(); // destructor
    void heapSort(KeyType* sorted[]); // heapsort, return result in sorted
    std::string toString() const; // return string representation
    MinHeap<KeyType>& operator=(const MinHeap<KeyType>& heap); // assignment operator

  protected:
    KeyType **A; // array containing the heap
    int heapSize; // size of the heap
    int capacity; // size of A
    void heapify(int index); // heapify subheap rooted at index
    void buildHeap(); // build heap
    int leftChild(int index) { return 2 * index + 1; } // return index of left child
    int rightChild(int index) { return 2 * index + 2; } // return index of right child
    int parent(int index) { return (index - 1) / 2; } // return index of parent
    void swap(int index1, int index2); // swap elements in A
    void copy(const MinHeap<KeyType>& heap); // copy heap to this heap
    void destroy(); // deallocate heap
};



template <class KeyType>
class MinPriorityQueue : public MinHeap<KeyType>
{
  public:
    MinPriorityQueue(int n = DEFAULT_SIZE); // construct an empty MPQ with capacity n
    MinPriorityQueue(const MinPriorityQueue<KeyType>& pq); // copy constructor

    // Destructor inherited from MinHeap<KeyType>
    KeyType* minimum() const; // return the minimum element
    KeyType* extractMin(); // delete the minimum element and return it
    void decreaseKey(int index, KeyType* key); // decrease the value of an element
    void insert(KeyType* key); // insert a new element
    bool empty() const; // return whether the MPQ is empty
    int length() const; // return the number of keys
    std::string toString() const; // return a string representation of the MPQ

    // Assignment operator inherited from MinHeap<KeyType>

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

class FullError { }; // MinPriorityQueue full exception
class EmptyError { }; // MinPriorityQueue empty exception
class KeyError { }; // MinPriorityQueue key exception
/*
template <class KeyType>
class node
{
  public:
    node(KeyType label,float p){key= label; priority = p;};
    KeyType key;
    float priority;
};

template <class KeyType>
string to_string(const node<KeyType>& node);

template <class KeyType>
bool operator<=(const node<KeyType>& lnode,const node<KeyType>& rnode) {return (lnode.priority<=rnode.priority);}
*/
#include "pqueue.cpp"
#endif
