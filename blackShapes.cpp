void dfs(int i, int j, vector < vector < char > > &grid) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 'O') {
    return;
  }

  grid[i][j] = 'O';
  dfs(i + 1, j, grid);
  dfs(i, j + 1, grid);
  dfs(i - 1, j, grid);
  dfs(i, j - 1, grid);

}
int findBlackShapes(vector < vector < char > > &grid) {
  int count = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 'X') {
        count++;
        dfs(i, j, grid);
      }
    }
  }

  return count;
}
