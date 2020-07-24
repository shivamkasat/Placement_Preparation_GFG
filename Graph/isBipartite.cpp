bool isBipartite(vector < vector < int > > &graph) {
  int n = graph.size();
  vector < int > color(n, 0);
  queue < int > q;
  int current = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] != 0)
      continue;
    q.push(i);
    color[i] = 1;
    while(q.empty() != true) {
      current = q.front();
      q.pop();
      for (auto x : graph[current]) {
        if (color[x] == 0) {
          color[x] = -1 * color[current];
          q.push(x);
        } else if (color[x] == color[current]) {
          return false;
        }
      }
    }
  }

  return true;
}
