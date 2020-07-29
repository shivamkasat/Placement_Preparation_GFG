#include <bits/stdc++.h>
using namespace std;

int checkPossible(int n, vector < vector < int > > edges) {
  vector < vector < int > > adjList(n + 1);
  vector < int > indegree(n + 1, 0);
  for (int i = 0; i < edges.size(); i++) {
    indegree[edges[i][1]]++;
    adjList[edges[i][0]].push_back(edges[i][1]);
  }

  queue < int > q;
  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int current;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    for (auto neigh : adjList[current]) {
      indegree[neigh]--;
      if (indegree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }

  int possible = 1;
  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] > 0) {
      possible = 0;
      break;
    }
  }

  return possible;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int dep;
    cin>>dep;
    vector < vector < int > > edges(dep, vector < int >(2, 0));
    for (int i = 0; i < dep; i++) {
      cin>>edges[i][0]>>edges[i][1];
    }
    cout<<checkPossible(n, edges)<<endl;

  }
  return 0;
}
