class comp {
public:
  bool operator()(int a, int b) {
    return a > b;
  }
};

int dfs(int start, vector < bool > &visited, vector < vector < int > > &adjList, vector < int > &maxDist) {
  visited[start] = true;
  priority_queue < int, vector < int > > maxD;

  for (auto x : adjList[start]) {
    if (visited[x] == false) {
      maxD.push(dfs(x, visited, adjList, maxDist));
    }
  }

  if (maxD.empty() == true) {
    maxDist[start] = 0;
    return 1;
  } else if (maxD.size() == 1) {
    maxDist[start] = (maxD.top());
    return maxDist[start] + 1;
  } else {
   int maxB = maxD.top();
    maxD.pop();
    maxDist[start] = (maxB + maxD.top());
    return (maxB + 1);
  }
}

int Solution::solve(vector<int> &nodes) {
   vector < vector < int > >adjList(nodes.size());
  int rootNode = 0;
  for (int i = 0; i < nodes.size(); i++) {
    if (nodes[i] == -1) {
      rootNode = i;
      continue;
    }

    adjList[i].push_back(nodes[i]);
    adjList[nodes[i]].push_back(i);
  }

  int maxSize = 0;
  vector < int > maxDist(nodes.size(), 0);
  vector < bool > visited(nodes.size(), false);
  int someSol = dfs(rootNode, visited, adjList, maxDist);

  for (auto x : maxDist) {
    maxSize = max(x, maxSize);
  }

  return maxSize;

}
