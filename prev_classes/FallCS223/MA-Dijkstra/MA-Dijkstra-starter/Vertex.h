#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Vertex
{
private:
	int _id;
	static int _id_counter;
	unordered_map<Vertex *, int> _edges;

	//cheater method for tracking path weight
	int _path_weight = 0;

public:

	Vertex()
	{
		_id_counter++;
		_id = _id_counter;
	}

	Vertex(int id)
	{
		if (id >= _id_counter)
		{
			_id_counter = id + 1;
		}
		_id = id;
	}

	int getPathWeight() const
	{
		return _path_weight;
	}

	void setPathWeight(int weight)
	{
		_path_weight = weight;
	}

	int getId() const
	{
		return _id;
	}

	void addEdge(Vertex *vertex, int weight)
	{
		_edges[vertex] = weight;
	}

	int getEdgeWeight(Vertex *edge)
	{
		return _edges[edge];
	}

	unordered_map<Vertex *, int> &getEdges()
	{
		return _edges;
	}

	void removeEdge(Vertex *vertex)
	{
		_edges.erase(vertex);
	}
};

int operator==(const Vertex &lhs, const Vertex &rhs)
{
	return lhs.getId() == rhs.getId();
}

bool operator<(const Vertex &lhs, const Vertex &rhs)
{
	return lhs < rhs;
}

bool operator>(const Vertex &lhs, const Vertex &rhs)
{
	return lhs > rhs;
}

class PathWeightComparer
{
public:
	bool operator()(const Vertex lhs, const Vertex rhs)
	{
		return (lhs.getPathWeight() > rhs.getPathWeight());
	}
};

//hashing algorithm must exist in STD namespace
namespace std {

	template <>
	struct hash<Vertex>
	{
		//provide a hash (convert grocery item into integer)
		std::size_t operator()(const Vertex& item) const
		{
			size_t hash_val = 0;

			//to hash INTs using the STL
			hash<int> int_hash{};

			//define hashing algorithm.  Ours is pretty easy...
			hash_val = int_hash(item.getId());

			//add others as necessary
			return hash_val;
		}
	};
}


int Vertex::_id_counter = 0;
#endif