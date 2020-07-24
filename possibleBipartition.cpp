bool possibleBipartition(int N, vector < vector < int > > &disLikes) {
  vector < vector < int > >adjList(N + 1);
  for (auto edge : dislikes) {
    adjList[edge[0]].push_back(edge[1]);
    adjList[edge[1]].push_back(edge[0]);
  }

  vector < int > color(N + 1, 0);

  for (int i = 1; i < N + 1; i++) {
    if (color[i] != 0) {
      continue;
    }

    color[i] = 1;
    queue < int > q;
    q.push(i);
    int current = 0;
    while (q.empty() != true) {
      current = q.front();
      q.pop();
      for (auto neigh : adjList[current]) {
        if (color[neigh] != 0) {
          if (color[neigh] == color[current]) {
            return false;
          }
        } else {
          color[neigh] = -1 * color[current];
          q.push(neigh);
        }
      }
    }
  }

  return true;
}
