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

using namespace std;

enum Color {WHITE, GRAY, BLACK};	//0 = white, 1 = gray, 2 = black


class graph
{
	public:
		graph(std::string filename);		//making an adjacency list/matrix as datatype
		graph(const graph& g);
		~graph();


		void dfs();		//it visits in small to large by changing the order of the adjList
		string topologicalsort();
		std::vector<int> countInDegree();

		string display_colors();
		string display_adjList();
		string display_adjMatrix();


		graph& operator=(const graph& g);   //sets this table equal to the assigned h's table

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
