#include <bits/stdc++.h>
using namespace std;
 
class Graph 
{
	//vertex, edge
	int v, e;
	int** adj;

public:
	Graph(int v, int e);
	void addEdge(int start, int e);
	void BFS(int start);
	void DFS(int start, vector<bool>& visited);
};

int main()
{
	int vertex = 5, edge = 4;

	Graph G(vertex, vertex);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	
	cout << "BFS: ";
	G.BFS(0);
	cout << "\nDFS: ";
	vector <bool> visited(vertex, false);
	G.DFS(0, visited);
}


Graph::Graph(int v, int e)
{
	this->v = v;
	this->e = e;
	adj = new int*[v];
	for (int row = 0; row < v; row++)
	{
		adj[row] = new int[v];

		for (int column = 0; column < v; column++)
		{
			adj[row][column] = 0;
		}
	}
}


void Graph::addEdge(int start, int e)
{
	adj[start][e] = 1;
	adj[e][start] = 1;
}

void Graph::BFS(int start)
{
	vector<bool> visited(v, false);
	vector<int> q;
	q.push_back(start);
	visited[start] = true;

	int vis;
	while (!q.empty())
	{
		vis = q[0];
		cout << vis << " ";
		q.erase(q.begin());

		for (int i = 0; i < v; i++)
		{
			if (adj[vis][i] == 1 && (!visited[i])) 
			{
				q.push_back(i);
				visited[i] = true;
			}
		}
	}
}

void Graph::DFS(int start, vector<bool>& visited)
{
	cout << start << " ";
	visited[start] = true;
	for (int i = 0; i < v; i++)
	{
		if (adj[start][i] == 1 && (!visited[i]))
		{
			DFS(i, visited);
		}
	}
}