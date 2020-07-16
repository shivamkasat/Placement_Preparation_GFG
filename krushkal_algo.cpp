#include <bits/stdc++.h>
using namespace std;

void findMST(vector < vector < int > > &graph, vector < bool > &visited, vector < int > &keys, vector < int > &parent) {
  int v = graph.size();
  for (int k = 0; k < v; k++) {
    int minKey = INT_MAX;
    int minIndex = INT_MAX;
    for (int i = 0; i < v; i++) {
      if (keys[i] < minKey && visited[i] == false) {
        minKey = keys[i];
        minIndex = i;
      }
    }

    int u = minIndex;
    visited[u] = true;
    for (int i = 0; i < v; i++) {
      if (visited[i] == false && graph[u][i] < keys[i]) {
        keys[i] = graph[u][i];
        parent[i] = u;
      }
    }
  }
}

void printMST(vector < vector < int > > &graph) {
  int v = graph.size();
  vector < bool > visited(v, false);
  vector < int > keys(v, INT_MAX);
  vector < int > parent(v, -1);
  keys[0] = 0;
  findMST(graph, visited, keys, parent);
  for (int i = 0; i < v; i++) {
    printf("%d - %d, %d", parent[i], i, graph[i][parent[i]]);
  }
}

int main() {
  vector < vector < int > >graph(5, vector < int >(5, -1));
  graph[0] = {0,2,0,6,0};
  graph[1] = {2,0,3,8,5};
  graph[2] = {0,3,0,0,7};
  graph[3] = {6,8,0,0,9};
  graph[4] = {0,5,7,9,0};
  printMST(graph);
  return 0;
}
