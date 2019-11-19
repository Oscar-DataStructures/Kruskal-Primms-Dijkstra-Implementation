/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;


//============================ New Node Method ==============-==================
template <class KeyType>
Node<KeyType>* newNode(KeyType data)
//Preconditions: 	N/A
//Postcondition:	Returns a dynamically allocated keytype Node pointer that updates its key value to be the one in the parameter
{
	Node<KeyType>* node = new Node<KeyType>();		//dynamically allocate Node
	node->parent = NULL;
  node->rank = 0;
	node->data = data;															//Sets the node key to the key parameter

	return node;
}


// ========================== Default Constructor ==============================
template <class KeyType>
djs<KeyType>::djs()
//Preconditions:  N/A
//Postcondition:  N/A
{

}


// =========================== Copy Constructor ================================
template <class KeyType>
djs<KeyType>::djs(const djs<KeyType>& ds)
//Preconditions:  N/A
//Postcondition:  N/A
{
  this.setMap = ds.setMap;
}


// ============================ Deconstructor ==================================
template <class KeyType>
djs<KeyType>::~djs()
//Preconditions:  N/A
//Postcondition:  N/A
{
  clearNodes();
}


// ================================= Clear Nodes ===============================
template <class KeyType>
void djs<KeyType>::clearNodes()
// PreConditions:		N/A
// PostConditions:	Deallocates memory and destroys existing bst
{

}


// ============================ Make Set Method ================================
template <class KeyType>
void djs<KeyType>::makeSet(KeyType x)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* node = newNode(x);
  node->parent = node;
  node->rank = 0;
}


// ============================= Union Method ==================================
template <class KeyType>
void djs<KeyType>::unionSets(KeyType x, KeyType y)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* nodeX = newNode(x);
  Node<KeyType>* nodeY = newNode(x);

  nodeX = findSet(x);
  nodeY = findSet(y);

  if(nodeX->rank > nodeY->rank)
  {
    nodeY->parent = nodeX;
  }

  else
  {
    nodeX->parent = nodeY;
    if(nodeX->rank == nodeY->rank)
    {
      nodeY->rank++;
    }
  }

}


// ============================ Find Set Method ================================
template <class KeyType>
Node<KeyType>* djs<KeyType>::findSet(KeyType x)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* node = newNode(x);
  if (node == node->parent)
  {
    return node;
  }

  node->parent = findSet(x);
  return node->parent;
}


// ============================= To String Method ==============================
template <class KeyType>
std::string djs<KeyType>::toString() const
{
  std::stringstream ss;
  ss << "[";

  return ss.str();
}
