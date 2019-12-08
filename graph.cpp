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
#include <vector>
#include <stack>
#include <queue>
#include "pqueue.h"

using namespace std;

// ============================== Constructor ==================================
template <class KeyType>
graph<KeyType>::graph(std::string filename)
//Preconditions:  N/A
//Postcondition:  Constructs adjMatrix and adjList
{
  constructAdjMatrix(filename);   //does error check
  constructAdjList();
}


// ============================= Copy Constructor ==============================
template <class KeyType>
graph<KeyType>::graph(const graph<KeyType>& g)
//Preconditions:  N/A
//Postcondition:  this will be the same as graph g
{
  this->numVertices = g.numVertices;
  this->adjList = g.adjList;
  this->adjMatrix = g.adjMatrix;
  this->colors = g.colors;
}


// ============================= Destructor ====================================
template <class KeyType>
graph<KeyType>::~graph()
//Preconditions:  N/A
//Postcondition:  N/A
{
  //bc we are using libaries they have Destructors implemented already
}


// ============================ Depth First Search Method ======================
template <class KeyType>
void graph<KeyType>::dfs()
//Preconditions:  N/A
//Postcondition:  Will return the order in which vertexs are processed
{
  for(int i = 0; i < numVertices; i++)
  {
    if (colors[i] == WHITE)
    {
      dfsNonRecursive(i);
    }
  }
}


// ============================ Topological Sort Method ========================
template <class KeyType>
string graph<KeyType>::topologicalsort()
//Preconditions:  N/A
//Postcondition:  Will detect cycle and output sorted order
{
  std::vector<int> inDegree = countInDegree();
  queue<int> processQueue;
  ostringstream topSort;
  int vertex = 0;
  int j = 0;

  topSort << "[";
  while( (inDegree[vertex] != 0) && (vertex < inDegree.size()) )vertex++;     //find an vertex having in-degree 0
  if (vertex >= inDegree.size())
  {
    topSort << "cycle detected]";
    return topSort.str();
  }
  processQueue.push(vertex);
  //cout << "The topological order of this graph is: "; //uncomment to cout instead of assert for visuals
  while ( !processQueue.empty() )
  {
    vertex = processQueue.front();
    processQueue.pop();
    topSort << vertex;
    if(j != numVertices - 1) topSort << ", ";
    j++;
    for (int i = 0; i < adjList.at(vertex).size(); i++ )
    {
      int document_vertex = adjList.at(vertex)[i];
      inDegree[document_vertex] --;     //= adjMatrix[vertex][document_vertex];
      if ( inDegree[document_vertex] == 0 )
      {
        processQueue.push(document_vertex);

      }

    }
  }
  topSort << "]";

  return topSort.str();
}


// ============================= Count In Degree Method ========================
template <class KeyType>
std::vector<int> graph<KeyType>::countInDegree()
//Preconditions:  N/A
//Postcondition:  returns a vector of the inDegree count for each vertex
{
  vector<int> countInD;
  countInD.resize(numVertices,0);
  for(int i =0; i < numVertices; i++)
  {
    vector<int> keyVec = adjList.at(i);
    for(int j = 0; j < keyVec.size(); j++)
    {
      countInD[keyVec[j]]++;
    }
  }
  return countInD;

}


// ============================ Display Colors  Method =========================
template <class KeyType>
string graph<KeyType>::display_colors()
//Preconditions:  N/A
//Postcondition:  will return string of colors of the vertices
{
  //cout << "The colors of this graph is: "; //uncomment to cout instead of assert for visuals
  ostringstream colorStr;
  int j = 0;


  colorStr << "[";
  for (std::vector<int>::const_iterator i = colors.begin(); i != colors.end(); ++i)
  {
    colorStr << *i;
    if (j != numVertices - 1) colorStr << ", ";
    j++;
  }

  colorStr << "]";
  return colorStr.str();
}


// =========================== Display Adjaceny List Method ====================
template <class KeyType>
string graph<KeyType>::display_adjList()
//Preconditions:  N/A
//Postcondition:  returns a string represenation of the adjList
{
  //cout << "The Adjancey List of this graph is: "; //uncomment to cout instead of assert for visuals
  ostringstream aList;
  int mapKey = 0;


  for(auto it = adjList.begin(); it != adjList.end(); ++it)   //https://stackoverflow.com/questions/18362896/printing-the-vector-in-a-map
  {
    int j = 0;
    aList << "\n" << it->first << " : ";
    for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
    {
      aList << *it2;
      if (j != adjList.at(mapKey).size() - 1) aList << ", ";
      j++;
    }
    mapKey++;
  }

    return aList.str();
}



// =========================== Display Adjaceny Matrix Method ==================
template <class KeyType>
string graph<KeyType>::display_adjMatrix()
//Preconditions:  N/A
//Postcondition:  returns a string represenation of the adjMatrix
{
  //cout << "The Adjancey Matrix of this graph is: "; //uncomment to cout instead of assert for visuals
  ostringstream aMatrix;

  aMatrix << "\n";
  for (int i = 0; i < adjMatrix.size(); i++)
  {
    for (int j = 0; j < adjMatrix[i].size(); j++)
    {
      aMatrix << adjMatrix[i][j] << " ";

    }
    aMatrix << "\n";
  }

  return aMatrix.str();
}


// ========================== Kruskal's Algorithm Method =======================
template <class KeyType>
std::string graph<KeyType>::Kruskal()
//Preconditions:  N/A
//Postcondition:
{
  djs<KeyType> a;
  for(int i = 0; i < numVertices; i++)
  {
    a.makeSet(i);
  }
}


// =========================== Prim's Algorithm Method =========================
template <class KeyType>
void graph<KeyType>::Prim(int root)
//Preconditions:  N/A
//Postcondition:
{
  vector<int> keyValues;
  for(int i = 0; i < numVertices; i++)
  {
    keyValues.push_back(infinity);
  }
  // keyValues[root] = 0;
  // priority_queue <int> q;
  // while (q.empty() == false)
  // {
  //   int u = q.extractMin();
  //   int vecLen = adjList.at(u).size();    //gets size of vector at key j
  //   for(int i = 0; i < vecLen; i++)   //gets neighbors
  //   {
  //
  //   }
  //
  // }


}


// ========================= Dijkstra's Algorithm Method =======================
template <class KeyType>
std::string graph<KeyType>::Dijkstra(int s)
//Preconditions:  N/A
//Postcondition:
{
  // initialize graph
  // initialize pq
  // pq.insertAll(graph.getVertices())
  //
  // while (pq is not empty) {
  //   vertex = pq.remove()
  //   edges = vertex.getEdges()
  //
  //   for all edges {
  //     destination = edge.getDestination()
  //     newDistance = edge.getLength() + vertex.getDistance()
  //     if (newDistance < destination.getDistance()) {
  //       destination.setShortestDistance(newDistance)
  //       pq.update(destination)
  //     }
  //   }

}


// =========================== Assignment Opertor Method =======================
template <class KeyType>
graph<KeyType>& graph<KeyType>::operator=(const graph<KeyType>& g)
//Preconditions:  N/A
//Postcondition:  Sets this to be the same as g
{
  this->numVertices = g.numVertices;
  this->adjList = g.adjList;
  this->adjMatrix = g.adjMatrix;
  this->colors = g.colors;
}


//==============================================================================
//============================== PRIVATE METHODS ===============================
//==============================================================================


// ========================== Adjaceny Matrix Constructor ======================
template <class KeyType>
void graph<KeyType>::constructAdjMatrix(std::string filename)
//Preconditions:  N/A
//Postcondition:  Constructs an adjMatrix and does an error check
{
  std::string vertices;
  std::string line;
  std::ifstream inFile;

  inFile.open(filename);

  if (!inFile)    //file opening failed
  {
    std::cerr << "Unable to open file"; //FIX, always outputs
    exit(1);
  }

  getline(inFile, vertices);    //we get the num of vertices this way
  numVertices = stoi(vertices);
  adjMatrix.resize(numVertices);    //resize the vector so we can push to the subvec

  for(int i = 0; i < numVertices; i++)   //populate the adjList
  {
    getline(inFile, line);
    line = removeWhiteSpaces(line);

    for(int j = 0; j < line.length(); j++)
    {
      int intResult = line[j] - '0';    //turn a char to an int
      adjMatrix[i].push_back(intResult);
    }
  }

  inFile.close();
}


// =========================== Adjaceny List Constructor =======================
template <class KeyType>
void graph<KeyType>::constructAdjList()
//Preconditions:  N/A
//Postcondition:  constructs an adjList
{

  for (int i = 0; i < adjMatrix.size(); i++)    //can build list from matrix
  {
    adjList[i];   //populate keys
    std::vector<int> result;
    for (int j = 0; j <(adjMatrix[i].size()) ; j++)
    {
      if(adjMatrix[i][j] != 0)    //we dont care about 0 weight bc no connection
      {
       result.push_back(j);   //pushes vertex not weight
      }
    }
    adjList[i] = result;
    colors.push_back(WHITE);
  }
}


// ======================== Remove White Spaces Method =========================
template <class KeyType>
string graph<KeyType>::removeWhiteSpaces(std::string line)
//Preconditions:  N/A
//Postcondition:  removes all white spaces from a given line
{
  string result = "";
  for(char c: line)   //for every char in line
  {
    if (c != '\n' && c != ' ' && c != '\t')   //strips white characters
    {
      result += c;
    }
  }

  return result;
}


// ========================== DFS NonRecursive Method ==========================
template <class KeyType>
void graph<KeyType>::dfsNonRecursive(int vertex)
//Preconditions:  N/A
//Postcondition:  outputs the order in which vertices are processed
{
  stack<int> processStack;

  colors[vertex] = GRAY;
  processStack.push(vertex);

  cout << "Order of Processed Vertices: ";
  while(processStack.empty() != true)   //while stack is not empty
  {
    int u = processStack.top();       //returns top element
    processStack.pop();   //pops top element
    int vecLen = adjList.at(u).size();    //gets size of vector at key j
    //cout << "\nLength of the vector:" <<vecLen << endl; //uncomment to cout instead of assert for visuals
    for(int i = 0; i < vecLen; i++)
    {
      int v = adjList.at(u)[i];   //get the vertex at u
      //cout << "Vertex: " << v << endl; //uncomment to cout instead of assert for visuals
      if(colors[v] == WHITE)    //if vertex is white
      {
        processStack.push(v);   //add vertex to stack
        colors[v] = GRAY;   //color vertex gray
      }
    }

    colors[u] = BLACK;    //once no more neighbors we color black
    // j++;    //iterator variable increment
    cout << u << " ";   //cout the order vertices are processed
  }
  cout << "\n" << endl;
}
