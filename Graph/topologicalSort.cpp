vector < int > topoSort(int V, vector < int > adj[]) {
  vector < int > indegree(V, 0);
  for (int i = 0; i < V; i++) {
    for (auto y : x) {
      indegree[y]++;
    }
  }

  queue < int > q;

  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int current = 0;
  vector < int > result;

  while (q.empty() != true) {
    current = q.front();
    result.push_back(current);
    q.pop();
    for (auto x : adj[current]) {
      indegree[x]--;
      if (indgree[x] == 0) {
        q.push(x);
      }
    }
  }

  return result;
}
