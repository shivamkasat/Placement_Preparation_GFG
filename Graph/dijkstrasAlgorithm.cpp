// cannot be used with negetive weighted graph, in that case it may or may not give correct answer.
// complexity is O(ElogV)

vector < int > dijkstra(vector < pair < int , int > adj[], int n, int start) {
  vector < int > keys(n, INT_MAX);
  keys[start] = 0;
  vector < bool > visited(n, false);
  set < pair < int, int > > minCostMap;
  minCostMap.insert({0, start});
  int currentElem = 0;
  int currentCost = 0;
  while (minCostMap.empty() != true) {
    currentElem = minCostMap.begin()->second;
    currentCost = minCostMap.begin()->first;
    visited[currentElem] = true;
    for (auto x : adj[currentElem]) {
      if (keys[x] > currentCost + x.second && visited[x] == false) {
        if (minCostMap.find({keys[x], x}) != minCostMap.end()) {
          minCostMap.erase(x);
        }
        keys[x] = currentCost + x.second;
        minCostMap.insert({currentCost + x.second, x});
      }
    }
  }
  return keys;
}
