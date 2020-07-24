int findSet(vector < int > &parent, int node1) {
  if (node1 == parent[node1]) {
    return node1;
  }

  return parent[node1] = findSet(parent[node1]);
}
void unionSet(vector < int > &parent, int node1, int node2) {
  int parent1 = findSet(node1);
  int parent2 = findSet(node2);
  if (parent1 != parent2) {
    parent[parent1] = parent2;
  }
}

bool equationsPossible(vector < string > &equations) {
  vector < int > parent(26, 0);
  for (int i = 0; i < 26; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < equations.size(); i++) {
    if (equations[i][1] == '=') {
      unionSet(parent, equations[i][0] - 'a', equations[i][3] - 'a');
    }
  }

  for (int i = 0; i < equations.size(); i++) {
    if (equations[i][1] == '!') {
      if (findSet(parent, equations[i][0] - 'a') == findSet(parent, equations[i][1])) {
        return false;
      }
    }
  }
  return true;
}
