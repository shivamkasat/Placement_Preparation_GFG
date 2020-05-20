#include <bits/stdc++.h>

using namespace std;

class Graph {
	int V;
	unordered_map < string, list < string > > adjList;
	
public :
	Graph(int v) {
		V = v;
	}

	void addEdge(string start, string dest, bool isBidirect = true) {
		adjList[start].push_back(dest);
		if (isBidirect == true) {
			adjList[dest].push_back(start);
		}
	}

	void printGraph() {
		for (auto itr = adjList.begin(); itr != adjList.end(); itr++) {
			cout<<(itr->first)<<"->";
			for (auto x : itr->second) {
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
};

int main() 
{
	Graph g(4);
	g.addEdge("jaipur", "agra");
	g.addEdge("jaipur", "delhi");
	g.addEdge("jaipur", "prayagraj");
	g.addEdge( "delhi", "prayagraj");

	g.printGraph();
	return 0;
}
