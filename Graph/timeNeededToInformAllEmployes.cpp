int numOfMinutes(int n, int headID, vector < int > &manager, vector < int > &informTime) {
  vector < vector < int > > adjList(n);
          for (int i = 0; i < manager.size(); i++) {
              if (manager[i] != -1)
                  adjList[manager[i]].push_back(i);
          }

          queue < int > q;
          q.push(headID);
          vector < int > minRequired(n, INT_MAX);
          minRequired[headID] = 0;
          int current = 0;
          while (q.empty() != true) {
              current = q.front();
              q.pop();
              for (auto v : adjList[current]) {
                  minRequired[v] = minRequired[current] + informTime[current];
                  q.push(v);
              }
          }
          int result = 0;
          for (auto x : minRequired) {
              result = max(x, result);
          }

          return result;
}
