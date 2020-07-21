#include <bits/stdc++.h>
using namespace std;

class unionFind {
  int *parent;
  public :
  void unionFind(int n) {
    parent = (int *) malloc(sizeof(int) * n);
  }

  int find(int node) {
    if (node == parent[node]) {
      return node;
    }
    return parent[node] = find(parent[node]);
  }

  int union(int node1, int node2) {
    int parent1 = find(node1);
    int parent2 = find(node2);
    if (parent1 < parent2) {
      parent[node2] = parent1;
    } else if (parent2 < parent1){
      parent[node1] = parent2;
    }
  }


};

int main() {
  return 0;
}
