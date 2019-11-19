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

		void clearNodes();
		void makeSet(KeyType x);
		void unionSets(KeyType x, KeyType y);
		Node<KeyType>* findSet(KeyType x);

		std::string toString() const;
		
	protected:
		map<int, KeyType> setMap;

};

#include "djs.cpp"

#endif
