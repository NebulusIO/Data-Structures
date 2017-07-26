#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <queue>
#include <functional>

#include "Vertex.h"
using namespace std;
class Graph
{
	unordered_map<int, Vertex> _vertices;

public:

	void addVertex(Vertex vertex)
	{
		_vertices[vertex.getId()] = vertex;
	}

	//MA #12 TODO: IMPLEMENT!
	unordered_map<Vertex, int> computeShortestPath(Vertex *start)
	{
		//holds known distances
		unordered_map<Vertex, int> distances;

		//underlying heap
		priority_queue<Vertex, vector<Vertex>, PathWeightComparer> dijkstra_queue{};

		//reset start's path weight
		start->setPathWeight(0);

		//make sure that the starting vertex is in the graph
		
			//push on starting vertex
			
			//while queue not empty
			
				//Top of heap not known (in distances)?
			
					//make known
			
					//push on outgoing edges

		return distances;
	}
};

#endif
