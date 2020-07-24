//---------------------------------------------------brute force solution which gives tle-----------------------------------------
class Solution {
    public:
    void fillMap(int start, vector < vector < int > > adjList, string labels, vector < bool > &visited, vector < int > &result, vector < int > &count) {
        visited[start] = true;
        for (auto x : adjList[start]) {
            if (visited[x] == false) {
              fillMap(x, adjList, labels, visited, result);
            }
        }

        count[labels[start] - 'a']++;
        result[start] = count[labels[start] - 'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector < vector < int > > adjList(n);
        for (auto x : edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }

        vector < bool > visited(n, false);
        vector < int > result(n, 0);
        vector < int > finalCount(26, 0);
        fillMap(0, adjList, labels, visited, result, finalCount);
        return result;
    }
};
//------------------------------------------------------- Accepted solution--------------------------------------------------------------
void fillMap(int start, vector < vector < int > > &adjList, vector < bool > &visited, vector < int > &result, vector < vector < int > > &count, string &labels) {
        visited[start] = true;
        for (auto x : adjList[start]) {
            if (visited[x] == false) {
                fillMap(x, adjList, visited, result, count, labels);
                for (int i = 0; i < 26; i++) {
                    count[start][i] += count[x][i];
                }
            }
        }

        count[start][labels[start] - 'a']++;
        result[start] = count[start][labels[start] - 'a'];
        cout<<"for start = "<<start<<" dp table is "<<endl;
        for (int i = 0; i < 26; i++) {
          cout<<count[start][i]<<" "<<endl;
        }
        cout<<endl;
        return;
}

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector < vector < int > >dp(n + 1, vector < int >(26, 0));
        vector < vector < int > > adjList(n);
        for (auto x : edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        vector < int > result(n, 0);
        vector < bool > visited(n, false);
        fillMap(0, adjList, visited, result, dp, labels);
        return result;
    }
