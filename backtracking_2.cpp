
#include <iostream>
using namespace std;

/*
* A directed graph using adjacency list representation;
* every vertex holds a list of all neighbouring vertices
* that can be reached from it.
*/
class Edge {
public:
	// Construct the graph given the number of vertices...
	Edge(int vertices);
	// Specify an edge between two vertices
	void add_edge(int start, int end);
	// Call the recursive helper function to count all the
	// paths
	int count_paths(int start, int end, int vertices);

private:
	int m_vertices;
	list<int>* m_neighbours;
	void path_counter(int start, int end, int& path_count,
					vector<bool>& visited);
};

Edge::Edge(int vertices)
{
	m_vertices = vertices; // unused!!
	/* An array of linked lists - each element corresponds
	to a vertex and will hold a list of neighbours...*/
	m_neighbours = new list<int>[vertices];
}

void Edge::add_edge(int start, int end)
{
	m_neighbours[start].push_back(end);
}

int Edge::count_paths(int start, int end, int vertices)
{
	int path_count = 0;
	vector<bool> visited(vertices, false);
	path_counter(start, end, path_count, visited);
	return path_count;
}

/*
* A recursive function that counts all paths from src to
* dst. Keep track of the count in the parameter.
*/
void Edge::path_counter(int start, int end, int& path_count,
						vector<bool>& visited)
{
	// If we've reached the destination, then increment
	// count...
	visited[start] = true;
	if (start == end) {
		path_count++;
	}
	// ...otherwise recurse into all neighbours...
	else {
		for (auto neighbour : m_neighbours[src]) {
			if (!visited[neighbour])
				path_counter(neighbour, end, path_count,
							visited);
		}
	}
	visited[start] = false;
}

// Driver code
int main()
{
	// Create a graph given in the above diagram - see link
	Edge e(5);
	e.add_edge(0, 1);
	e.add_edge(0, 2);
	e.add_edge(0, 4);
	e.add_edge(1, 3);
	e.add_edge(1, 4);
	e.add_edge(2, 3);
	e.add_edge(2, 1);
	e.add_edge(3, 2);
	
	// Function call
	cout << e.count_paths(0, 4, 5);

	return 0;
}

