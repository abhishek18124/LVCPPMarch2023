/*

Computing SSSP using the BFS algorithm in an unweighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {

	map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

public :

	graph(bool isDirected = false) {
		this->isDirected = isDirected;
	}

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);

		if (!isDirected) {
			neighbourMap[v].push_back(u);
		}

	}

	void bfs(T s, T d) {

		map<T, int> distMap; // to store the mapping between vertices &
		// their shortest dist from the src vertex
		distMap[s] = 0;

		map<T, T> parentMap;
		parentMap[s] = s;

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			list<T> neighbourList = neighbourMap[front];
			for (T neighbour : neighbourList) {
				if (visited.find(neighbour) == visited.end()) {
					visited.insert(neighbour);
					q.push(neighbour);

					// since you are visiting 'neighbour' because of 'front'
					// we can say that 'front' is the parent of 'neighbour'
					// in the BFS tree

					distMap[neighbour] = distMap[front] + 1;
					parentMap[neighbour] = front;
				}
			}

		}

		for (pair<T, int> vertex : distMap) {
			T vertexLabel = vertex.first;
			int distance = vertex.second;
			cout << vertexLabel << " : " << distance << endl;
		}

		cout << endl;

		for (pair<T, T> vertex : parentMap) {
			T vertexLabel = vertex.first;
			T parentLabel = vertex.second;
			cout << vertexLabel << " : " << parentLabel << endl;
		}

		cout << endl;

		cout << "The length of the shortest-path b/w " << s << " and " << d << " : " << distMap[d] << endl;

		T temp = d;

		vector<T> shortestPath;

		while (parentMap[temp] != temp) {
			// cout << temp << "<-";
			shortestPath.push_back(temp);
			temp = parentMap[temp];
		}

		// cout << temp << endl;
		shortestPath.push_back(temp); // shortestPath.push_back(s)

		reverse(shortestPath.begin(), shortestPath.end());

		for (T vertex : shortestPath) {
			cout << vertex << " ";
		}

		cout << endl;

	}
};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');
	g.addEdge('E', 'H');
	g.addEdge('F', 'H');
	g.addEdge('G', 'I');
	g.addEdge('H', 'I');

	g.bfs('A', 'I');

	return 0;
}