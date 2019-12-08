/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <sstream>
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <map>

using namespace std;


//============================ New Node Method =================================
template <class KeyType>
Node<KeyType>* newNode(KeyType data)
//Preconditions: 	N/A
//Postcondition:	Returns a dynamically allocated keytype Node pointer that updates its key value to be the one in the parameter
{
	Node<KeyType>* node = new Node<KeyType>();		//dynamically allocate Node
	node->parent = node;
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
  this->setMap = ds.setMap;
	deepCopy();
}


// ============================ Deconstructor ==================================
template <class KeyType>
djs<KeyType>::~djs()
//Preconditions:  N/A
//Postcondition:  N/A
{
  clearNodes();
}


// ============================== Deep Copy Method =============================
template <class KeyType>
djs<KeyType>& djs<KeyType>::deepCopy()
// PreConditions:		N/A
// PostConditions:	N/A
{
		//TODO: this needs to reconstruct the tree structure
}


// ================================= Clear Nodes ===============================
template <class KeyType>
void djs<KeyType>::clearNodes()
// PreConditions:		N/A
// PostConditions:	Deallocates memory and destroys existing bst
{
		//TODO: needs to dynamically deallocate nodes
}


// ============================ Make Set Method ================================
template <class KeyType>
void djs<KeyType>::makeSet(KeyType x)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* node = newNode(x);
	setMap[x] = node;	//creates key x with node as value
}


// ============================= Union Method ==================================
template <class KeyType>
void djs<KeyType>::unionSets(KeyType x, KeyType y)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* nodeX = setMap[x];
  Node<KeyType>* nodeY = setMap[y];

  nodeX = helpFindSet(nodeX);
  nodeY = helpFindSet(nodeY);

  if(nodeX->rank >= nodeY->rank)
  {
    nodeY->parent = nodeX;
		if(nodeX->rank == nodeY->rank)
    {
      nodeX->rank++;
    }
  }

  else
  {
    nodeX->parent = nodeY;
  }

}


// ============================ Find Set Method ================================
template <class KeyType>
KeyType djs<KeyType>::findSet(KeyType x)
//Preconditions:  N/A
//Postcondition:  N/A
{
  Node<KeyType>* rootNode = setMap[x];
	rootNode = helpFindSet(rootNode);

	return rootNode->data;
}


// ============================= Display Set Map  Method =======================
template <class KeyType>
std::string djs<KeyType>::display_setMap()
//Preconditions:  N/A
//Postcondition:  N/A
{
  ostringstream sMap;

  for(auto it = setMap.begin(); it != setMap.end(); ++it)
  {
		sMap << it->first << " : ";	//prints each key
		Node<KeyType>* tmp = it->second;
		sMap << tmp->data;

		while (tmp->parent != tmp)
		{
			tmp = tmp->parent;
			sMap << ", " << tmp->data ;
		}
		sMap << "\n";
  }

  return sMap.str();
}


//==============================================================================
//============================== PRIVATE METHODS ===============================
//==============================================================================


// ========================= Help Find Set Method ==============================
template <class KeyType>
Node<KeyType>* djs<KeyType>::helpFindSet(Node<KeyType>* node)
//Preconditions:  N/A
//Postcondition:  N/A
{
  if (node == node->parent)
  {
    return node;
  }

  node->parent = helpFindSet(node->parent);

  return node->parent;
}
