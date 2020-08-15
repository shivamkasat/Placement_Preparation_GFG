#include <bits/stdc++.h>
using namespace std;

void dfs(int start, int rootStart, int day, int parent, int totalPopu, vector < int > &population, vector < int > &fruits, vector < bool > &visited, vector < int > &result, vector < vector < int > > &adjList) {
	if (fruits[start] > 0) {
     	fruits[start] -= min(fruits[start], population[rootStart]);
     	if (fruits[start] <= 0) {
     		result[start] = day;
     	}
	}
	for (auto neigh : adjList[start]) {
		if (visited[neigh] == false && neigh != parent) {
			visited[neigh] = true;
			dfs(neigh, rootStart, day, start, totalPopu + population[neigh], population, fruits, visited, result, adjList);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < vector < int > >adjList(n + 1);
		int u, v;
		for (int i = 0; i < n - 1; i++) {
			cin>>u;
			cin>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		vector < int > cityOrder;
		int city;
		for (int i = 0; i < n; i++) {
			cin>>city;
			cityOrder.push_back(city);
		}

		vector < int > population(n + 1, 0);
		for (int i = 1; i < n + 1; i++) {
			cin>>population[i];
		}

		vector < int > fruits(n + 1, 0);
		for (int i = 1; i < n + 1; i++) {
			cin>>fruits[i];
		}

		vector < int > result(n + 1, -1);
		vector < bool > visited(n + 1, false);
		int day = 1;
		for (auto x : cityOrder) {
			visited[x] = true;
			dfs(x, x, day, x, population[x], population, fruits, visited, result, adjList);
			day++;
		}

		for (int i = 1; i < n + 1; i++) {
			cout<<result[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}