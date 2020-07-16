void bfs(vector < vector < int > > &rooms, vector < bool > &visited, int start) {
  if (visited[start] == true) {
    return;
  }
  visited[start] = true;
  for (auto x : rooms[start]) {
    bfs(rooms, visited, x);
  }
}
bool canVisitAllRooms(vector < vector < int > > &rooms) {
  int n = rooms.size();
  vector < bool > visited(n, false);
  int start = 0;
  dfs(rooms, visited, start);
  // int result = true;
  for (int i = 1; i < n; i++) {
    if (visited[i] == false) {
      return false;
    }
  }

  return true;
}
