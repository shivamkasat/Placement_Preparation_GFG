vector < int > maxDistance(vector < vector < int > > &grid) {
  queue < pair < int, int > >q;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 1) {
        q.push({i, j});
      }
    }
  }

  pair < int, int > current;
  int i = 0;
  int j = 0;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    i = current.first;
    j = current.second;

    if (i + 1 < rows && grid[i + 1][j] == 0) {
      grid[i + 1][j] = grid[i][j] + 1;
      q.push({i + 1, j});
    }

    if (j + 1 < cols && grid[i][j + 1] == 0) {
      grid[i][j + 1] = grid[i][j] + 1;
      q.push({i, j + 1});
    }

    if (i - 1 >= 0 && grid[i - 1][j] == 0) {
      grid[i - 1][j] = grid[i][j] + 1;
      q.push({i - 1, j});
    }

    if (j - 1 >= 0 && grid[i][j - 1] == 0) {
      grid[i][j - 1] = grid[i][j] + 1;
      q.push({i, j - 1});
    }
  }

  int maxDist = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      maxDist = max(maxDist, grid[i][j]);
    }
  }

  if (maxDist == 1) {
    return -1;
  }
  return maxDist - 1;
}
