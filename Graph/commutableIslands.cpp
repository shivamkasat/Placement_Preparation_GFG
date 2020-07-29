#include <bits/stdc++.h>
using namespace std;

int findSet(vector < int > &parent, int node1) {
  if (parent[node1] == node1) {
    return node1;
  }

  return parent[node1] = findSet(parent, parent[node1]);
}

void unionSet(vector < int > &parent, int node1, int node2) {
  int parent1 = findSet(parent, node1);
  int parent2 = findSet(parent, node2);

  if (parent1 != parent2) {
    parent[parent1] = parent2;
  }
}

class comp {
  public:
  bool operator()(pair < int, pair <int, int > > &a, pair < int, pair <int, int > > &b) {
    return a.first > b.first;
  }
};

int solve(int N, vector < vector < int > > &bridges) {
  vector < int > parent(N + 1, 0);
  for (int i = 0; i < N + 1; i++) {
    parent[i] = i;
  }
  priority_queue < pair < int, pair < int, int > >, vector < pair < int, pair < int, int > > >, comp >pq;
  for (int i = 0; i < bridges.size(); i++) {
    pq.push(make_pair(bridges[i][2], make_pair(bridges[i][0], bridges[i][1])));
  }
  int minCost = 0;
  pair < int, pair <int , int > > current;
  while (pq.empty() != true) {
    current = pq.top();
    pq.pop();
    if (findSet(parent, current.second.first) != findSet(parent, current.second.second )) {
      minCost += current.first;
      unionSet(parent, current.second.first, current.second.second);
    }
  }

  return minCost;
}

int main() {
  int test;
  cin>>test;
  while(test--) {
    int n;
    cin>>n;
    int bridge;
    cin>>bridge;
    vector < vector < int > > bridges(bridge, vector < int >(3, 0));
    for (int i = 0; i < bridge; i++) {
      cin>>bridges[i][0];
      cin>>bridges[i][1];
      cin>>bridges[i][2];
    }
    cout<<solve(n, bridges)<<endl;
  }
}
