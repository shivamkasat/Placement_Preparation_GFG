class Solution {
public:
    int findSet(vector < int > &parent, int node1) {
      if (parent[node1] == node1) {
        return node1;
      }

      return parent[node1] = findSet(parent, parent[node1])
    }

    void unionSet(vector < int > &parent, int node1, int node2) {
      int parent1 = findSet(parent, node1);
      int parent2 = findSet(parent, node2);
      if (parent1 != parent2) {
        parent[parent1] = parent2;
      }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
      vector < int > parent(n, 0);
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
      int extraCables = 0;
      for (auto connection : connections) {
        if (findSet(parent, connection[0]) == findSet(parent, connection[1])) {
          extraCables++;
        } else {
          unionSet(parent, connection[0], connection[1]);
        }
      }
      unordered_set < int > hset;
      for (int i = 0; i < parent.size(); i++) {
        hset.insert(findSet(parent[i]));
      }
      int connectedComp = hset.size();

      if (connectedComp == 1) {
        return 0;
      } else if (extraCables < connectedComp - 1) {
        return -1;
      } else {
        return connectedComp - 1;
      }
    }
};
