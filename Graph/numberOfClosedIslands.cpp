int dfs(int i, int j, vector < vector < int > > &grid) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return 0;
  } else if (grid[i][j] == 1 || grid[i][j] == -1) {
    return 1;
  }

  grid[i][j] = -1;
  return dfs(i + 1, j, grid) * dfs(i, j + 1, grid) * dfs(i - 1, j, grid) * dfs(i, j - 1, grid);
}
int closedIsland(vector < vector < int > > &grid) {
  int rows = grid.size();
  int cols = grid[0].size();
  if (rows <= 1 || cols <= 1) {
    return 0;
  }
  int islandCount = 0;
  for (int i = 1; i < rows - 1; i++) {
    for (int j = 1; j < cols - 1; j++) {
      if (grid[i][j] == 0)
        islandCount += dfs(i, j, grid);
    }
  }
  return islandCount;
}
