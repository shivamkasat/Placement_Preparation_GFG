#include <bits/stdc++.h>
using namespace std;

int dfs(int start, vector < int > &weights, vector < vector < int > > &adjList, vector < int > &totalWeight, vector < bool > &visited) {
  visited[start] = true;
  int total = 0;
  for (auto neigh : adjList[start]) {
    if (visited[neigh] == false) {
      total = total + dfs(neigh, weights, adjList, totalWeight, visited);
    }
  }
  totalWeight[start] = total + weights[start - 1];
  return totalWeight[start];
}

int findMaxProduct(vector < int > &weights, vector < vector < int > > &edgeList) {
  //createAdjacancy List
  int mod = 1e9 + 7;
  vector < vector < int > >adjList(weights.size() + 1);
  for (int i = 0; i < edgeList.size(); i++) {
    adjList[edgeList[i][0]].push_back(edgeList[i][1]);
    adjList[edgeList[i][1]].push_back(edgeList[i][0]);
  }


  vector < int > totalWeight(weights.size() + 1, 0);
  vector < bool > visited(weights.size() + 1, false);
  int rootSum = dfs(1, weights, adjList, totalWeight, visited);

  cout<<"rootSum = "<<rootSum<<endl;

  cout<<"printing totalWeights"<<endl;
  for (int i = 0; i < totalWeight.size(); i++) {
      cout<<totalWeight[i]<<" ";
  }
  cout<<endl;

  int result = INT_MIN;
  for (int i = 0; i < edgeList.size(); i++) {
    result = max(result, (((rootSum - totalWeight[edgeList[i][0]]) % mod) * (totalWeight[edgeList[i][0]] % mod) % mod));
    result = max(result, (((rootSum - totalWeight[edgeList[i][1]]) % mod) * (totalWeight[edgeList[i][1]] % mod) % mod));

  }
  return result;
}

int main() {
  int n;
  cin>>n;
  vector < int > weights(n, 0);
  for (int i = 0; i < n; i++) {
    cin>>weights[i];
  }
  int edges;
  cin>>edges;
  vector < vector < int > >edgeList(edges, vector < int >(2, 0));
  for (int i = 0; i < edges; i++) {
    cin>>edgeList[i][0]>>edgeList[i][1];
  }
  cout<<findMaxProduct(weights, edgeList)<<endl;
  return 0;
}
