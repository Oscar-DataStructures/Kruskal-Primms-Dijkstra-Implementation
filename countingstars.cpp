/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 8
*/
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

enum Color {WHITE, GRAY, BLACK};	//0 = white, 1 = gray, 2 = black


class graph
{
	public:
		graph(int row,int column, vector<int> color)
		{
  			constructAdjList(row,column);   //does error check
			this->colors = color;
		}
		~graph()
		{
			this->colors.clear();		
			this->numVertices = 0;
			this->adjList.clear();
		}


		int dfs()
		{
			int result = 0;
			for(int i = 0; i < numVertices; i++)
  			{
    			if (colors[i] == WHITE)
				{
					dfsNonRecursive(i);
					result++;
				}   
  			}
			return result;
		}


	private:
		std::vector<int> colors;		//make a std::vector to hold the color of n things
		int numVertices;
		std::map<int, std::vector<int> > adjList;

		void constructAdjList(int rows, int columns)
		{
			std::string vertices;
  			std::string line;
  			numVertices = rows * columns;
  			for(int i = 0; i < numVertices; i++)   
  			{
				adjList[i];   //populate keys
    			std::vector<int> result;
				if ((i+columns)>=0 && ((i+columns)<numVertices)) result.push_back((i+columns));
				if ((i-columns)>=0 && ((i-columns)<numVertices)) result.push_back((i-columns));
				if ( (i+1)%columns != 0 ) result.push_back((i+1));
				if ( i%columns !=0 ) result.push_back((i-1));
    			adjList[i] = result;
  			}
		}

		void dfsNonRecursive(int vertex)
		{
			stack<int> processStack;
  			colors[vertex] = GRAY;
  			processStack.push(vertex);
  			while(processStack.empty() != true)   //while stack is not empty
  			{
    			int u = processStack.top();       //returns top element
    			processStack.pop();   //pops top element
    			int vecLen = adjList.at(u).size();    //gets size of vector at key j
    			for(int i = 0; i < vecLen; i++)
    			{
      				int v = adjList.at(u)[i];   //get the vertex at u
    				if(colors[v] == WHITE)    //if vertex is white
      				{
				        processStack.push(v);   //add vertex to stack
        				colors[v] = GRAY;   //color vertex gray
      				}
    			}
				colors[u] = BLACK;    //once no more neighbors we color black
  			}
		}

		
};


// ==================================== Input ===================================
// =============================================================================
void input()
{
	string size,line;
	vector<int> color;
	int cases = 1;
 	while (getline(cin, size))
	{
		int rows = stoi(size.substr(0, size.find(" ") ) );
		int columns = stoi(size.substr(size.find(" ")+1) );
		for (int i=0; i<rows; i++)
		{
			getline(cin, line);
			for (int j=0; j<columns; j++)
			{
				if (line[j] == '#') color.push_back(BLACK);
				if (line[j] == '-') color.push_back(WHITE);
			}
		}
		graph temp(rows, columns, color);
		cout << "Case "<< cases << ": " << temp.dfs() << endl;
		cases++;
		//temp.~graph();
		color.clear();
	}
}

// ==================================== Main ===================================
// =============================================================================
int main()
{
	input();
	return 0;
}

