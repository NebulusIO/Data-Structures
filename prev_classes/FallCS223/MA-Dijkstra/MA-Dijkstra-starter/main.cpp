#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Graph.h"
#include "Vertex.h"
using namespace std;

void graphTest()
{
	//populate graph
	Graph graph{};
	vector<Vertex> vertices{};

	//generate vertices
	for (int i = 0; i < 4; i++)
	{
		vertices.push_back(Vertex{});
	}

	/*
	Graph: 0 -> 1 (weight 4)
	       0 -> 3 (weight 10)
		   1 -> 2 (weight 4)
		   1 -> 3 (weight 8)
		   2 -> 3 (weight 15)
		   
	*/
	vertices[0].addEdge(&vertices[1], 4);
	vertices[0].addEdge(&vertices[3], 20);
	vertices[1].addEdge(&vertices[2], 4);
	vertices[1].addEdge(&vertices[3], 8);
	vertices[2].addEdge(&vertices[3], 15);

	//add vertices to graph
	for (auto vertex : vertices)
	{
		graph.addVertex(vertex);
	}

	unordered_map<Vertex, int> distances = graph.computeShortestPath(&vertices[0]);
	cout << "Distance from 0 to 0: " << distances[vertices[0]] << " (expected: 0)" << endl;
	cout << "Distance from 0 to 1: " << distances[vertices[1]] << " (expected: 4)" << endl;
	cout << "Distance from 0 to 2: " << distances[vertices[2]] << " (expected: 8)" << endl;
	cout << "Distance from 0 to 3: " << distances[vertices[3]] << " (expected: 12)" << endl;
}

int main(int argc, char* argv[])
{
	graphTest();
}