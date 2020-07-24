class Solution {
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector < vector < int > > reverseGraph(n);
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                reverseGraph[graph[i][j]].push_back(i);
            }
        }

        vector < int > indegree(graph.size(), 0);
        for (int i = 0; i < reverseGraph.size(); i++) {
            for (int j = 0; j < reverseGraph[i].size(); j++) {
                indegree[reverseGraph[i][j]]++;
            }
        }

        queue < int > q;
        vector < bool > safeNodes(n, false);
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                safeNodes[i] = true;
                q.push(i);
            }
        }

        int current = 0;
        while (q.empty() != true) {
            current = q.front();
            q.pop();
            for (auto x : reverseGraph[current]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    safeNodes[x] = true;
                    q.push(x);
                }
            }
        }

        vector < int > result;
        for (int i = 0; i < safeNodes.size(); i++) {
            if (safeNodes[i] == true) {
                result.push_back(i);
            }
        }

        return result;
    }
};


// graph colouring solution
// unvisited node are colored white => (0);
// under visit nodes are colored grey => (1);
// visisted nodes are colored black => (2)

class Solution {
    public:
    bool dfs(int start, vector < int > &color, vector < vector < int > > &graph) {
        if (color[start] == 1) {
            return false;
        } else if (color[start] == 2) {
            return true;
        }

        color[start] = 1;
        bool result = true;
        for (auto x : graph[start]) {
            result = result && dfs(x, color, graph);
        }

        if (result == true) {
            color[start] = 2;
        }

        return result;
    }

    vector < int > eventualSafeNodes(vector < vector < int > > &graph) {
        vector < int > colors(graph.size(), 0);
        vector < int > result;
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i, colors, graph)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
