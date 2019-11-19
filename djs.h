/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#ifndef _djs_h
#define _djs_h

#include <iostream>
#include <string>
#include <map>

using namespace std;

template <class KeyType>
class Node
{
	public:
		KeyType data; //value held in node
		int rank;
		Node<KeyType>* parent; //parent node

		//TODO:overload == operator for data
};


template <class KeyType>
Node<KeyType>* newNode(KeyType data);


template <class KeyType>
class djs
{
	public:
    djs();
    djs(const djs<KeyType>& ds);
		~djs();

		djs<KeyType>& deepCopy();
		void clearNodes();
		void makeSet(KeyType x);
		void unionSets(KeyType x, KeyType y);
		KeyType findSet(KeyType x);


		std::string display_setMap();
		djs<KeyType>& operator=(const djs<KeyType>& ds);

	protected:
		map<KeyType, Node<KeyType>*> setMap;	//mapping of set values to nodes which have tree structure built using pointers
		Node<KeyType>* helpFindSet(KeyType x);

};

#include "djs.cpp"

#endif
