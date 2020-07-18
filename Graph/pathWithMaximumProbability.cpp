double maxProbability(int n, vector < vector < int > > &edges, vector < double > &succProb, int start, int end) {
  vector < vector < pair < int, int > > > adjList(n);
  for (int i = 0; i < edges.size(); i++) {
    adjList[edges[i].first].push_back({edges[i].second, succProb[i]});
    adjList[edges[i].second].push_back({edges[i].first, succProb[i]});
  }
  vector < double > result(n, 0.0);
  queue < int > q;
  q.push(start);
  int current = 0;
  result[current] = 1;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    for (auto x : adjList[current]) {
        result[x.first] = result[current] * x.second;
        q.push(x.first);
    }
  }

  return result[end];
}
