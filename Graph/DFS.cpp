void doDFS(vector < int > g[], vector < bool > &visited, int start, vector < int > &traversed) {
  visited[start] = true;
  traversed.push_back(start);
  for (auto x : g[start]) {
    if (visited[x] == false) {
      dfs(g, visited, x, traversed);
    }
  }
}

vector < int > dfs(vector < int > g[], int N) {
  vector < bool > visited(N, false);
  int start = 0;
  vector < int > traversed;
  doDFS(g, visited, start, traversed);
  return traversed;
}
