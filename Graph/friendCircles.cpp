void dfs(int i, vector < vector < int > > &grid) {
  visited[i] = true;
  for (int j = 0; j < grid.size(); j++) {
    if (visited[j] == false && grid[i][j] == 1) {
      dfs(j, grid);
    }
  }
}
int findCirNum(vector < vector < int > > &grid) {
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;
  vector < bool > visited(rows, false);
  for (int i = 0; i < rows; i++) {
    if (visited[i] == false) {
      count += 1;
      dfs(int i, grid);
    }
  }
  return count;
}
