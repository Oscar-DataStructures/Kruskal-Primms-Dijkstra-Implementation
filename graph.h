/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#ifndef _graph_h
#define _graph_h

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>
#include "djs.h"

using namespace std;

enum Color {WHITE, GRAY, BLACK};	//0 = white, 1 = gray, 2 = black

template <class KeyType>
class graph
{
	public:
		graph(std::string filename);		//making an adjacency list/matrix as datatype
		graph(const graph<KeyType>& g);
		~graph();


		void dfs();		//it visits in small to large by changing the order of the adjList
		std::string topologicalsort();
		std::vector<int> countInDegree();

		std::string display_colors();
		std::string display_adjList();
		std::string display_adjMatrix();

		std::string Kruskal();
		void Prim(int root);
		std::string Dijkstra(int s);

		graph<KeyType>& operator=(const graph<KeyType>& g);   //sets this table equal to the assigned h's table

	private:
		std::vector<int> colors;		//make a std::vector to hold the color of n things
		int numVertices;

		void constructAdjMatrix(std::string filename);
		void constructAdjList();

		std::string removeWhiteSpaces(std::string line);
		void dfsNonRecursive(int vertex);

		std::map<int, std::vector<int> > adjList;
		std::vector<std::vector<int> > adjMatrix;
};


#include "graph.cpp"

#endif
