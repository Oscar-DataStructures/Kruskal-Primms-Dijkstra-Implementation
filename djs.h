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
		KeyType key; //value held in node

  protected:
		Node<KeyType>* parent; //parent node
};


template <class KeyType>
Node<KeyType>* newNode(KeyType key);


template <class KeyType>
class djs : Node<KeyType>
{
	public:
    djs();
    djs(const djs<KeyType>& ds);
		~djs();
		// makeSet(KeyType x);
		// union(KeyType x);
		// findSset(KeyType x);

	protected:
		map<KeyType x, KeyType y> setMap;

};

#include "djs.cpp"

#endif
