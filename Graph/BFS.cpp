vector < int > bfs(vector < int > g[], int N) {
  vector < int > traversed;
  vector < bool > visited(N, false);
  queue < int > q;
  q.push_back(0);
  visited[0] = true;
  travesed.push_back(0);
  int current = 0;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    for (auto x : g[currnet]) {
      if (visited[x] == false) {
        visited[x] = true;
        traversed.push_back(x);
        q.push(x);
      }
    }
  }

  return traversed;
}
