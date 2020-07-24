int dfs(int start, int maxDist, vector < vector < pair < int, int > > > &adjList, int &count) {
  if (maxDist < 0) {
    return;
  }

  count++;
  for (auto neigh : adjList[start]){
    dfs(neigh.first, maxDist - neigh.second, adjList, count);
  }
}

int findTheCity(int n, vector < vector < int > > &edges, int limit) {
  vector < vector < pair < int, int > > > adjList(n);
  for (auto edge : edges) {
    adjList[edge[0]].push_back({edge[1], edge[2]});
    adjList[edge[1]].push_back({edge[0], edge[2]});
  }
  vector < int > nodeCount(n, 0);
  int count = 0;
  for (int i = 0; i < n; i++) {
    count = 0;
    dfs(i, limit, adjList, count);
    nodeCount = count - 1;
  }

  int maxNeigh = 0;
  for (auto x : nodeCount) {
    maxNeigh = max(maxNeigh, x);
  }
  return maxNeigh;
}
