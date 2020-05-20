#include <bits/stdc++.h>

using namespace std;

class Graph {
	list < int > *adjList;
	int V;	
	public:
	
	Graph(int v) {
		V = v;
		adjList = new list < int >[v];
	}

	void addEdge(int start, int dest, bool isBidirect = true) {
		adjList[start].push_back(dest);
		if (isBidirect) {
			adjList[dest].push_back(start);
		}
	}

	void printGraph() {
		for (int i = 0; i <= V; i++) {
			printf("%d->", i);
			for (int x : adjList[i]) {
				printf("%d,",x);
			
			}
		
			printf("\n");
		}
	}

	void bfs(int start) {
		bool *visited = new bool[V];
		queue < int > q;
		q.push(start);
		visited[start] = true;
		printf("%d ", start);

		while (q.empty() != true) {
			int temp = q.front();
			//visited[temp] = true;
			//cout<<temp<<endl;
			for (auto x : adjList[temp] ) {
				if (visited[x] == false) {
					q.push(x);
					visited[x] =true;
					printf("%d ", x);
				}
			}
			q.pop();
			
		}
	}

	void dfsUtil(int start, bool *visited) {
		visited[start] = true;
		cout<<start<<" ";
		for (auto x : adjList[start]) {
			if (visited[x] == true) {
				continue;
			}
			dfsUtil(x, visited);
		}
		return;
	}

	void dfs(int start) {
		bool *visited = new bool[V];
		dfsUtil(start, visited);
	}
	
	void topoUtil(int start, vector < bool > &visited, stack < int > &st) {
		visited[start] = true;
		for (auto x : adjList[start]) {
			if (visited[x] == false) {
				topoUtil(x, visited, st);
			}
		}

		st.push(start);
	}

	void toposort(int start) {
		stack < int > st;
		vector < bool > visited(V + 1, false);

		//topoUtil(start, visited, st);
		/*
		while (st.empty() != true) {
			cout<<st.top()<<" ";
			st.pop();
		}
		*/
	}
};

int main() {
	Graph g(8);
	Graph dG(4);
	/*	
	g.addEdge(0,4);
	g.addEdge(0,6);
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(6,2);
	g.addEdge(6,3);
	g.addEdge(1,5);
	g.addEdge(2,5);
	g.addEdge(2,7);
	g.addEdge(3,7);
	*/
	
	dG.addEdge(2, 1, false);
	dG.addEdge(2, 3, false);
	dG.addEdge(1, 4, false);
	dG.addEdge(3, 4, false);	
	
	dG.printGraph();
	
	/*
	cout<<endl;
	cout<<"printing bfs traversal"<<endl;
	g.bfs(0);
	cout<<endl;
	cout<<"printing dfs traversal"<<endl;
	g.dfs(0);
	*/
	cout<<"toposort "<<endl;
	dG.toposort(2);
	return 0;
}
