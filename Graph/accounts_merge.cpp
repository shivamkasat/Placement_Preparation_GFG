class Solution {
    public:void dfs(int start, vector < vector < int > > &adjList, map < int, set < string > > &nameToMail, vector < bool > &visited, vector < vector < string > > &accounts, int origin) {
        visited[start] = true;
        for (int i = 1; i < accounts[start].size(); i++) {
            nameToMail[origin].insert(accounts[start][i]);
        }
        for (auto x : adjList[start]) {
            if (visited[x] == false) {
                dfs(x, adjList, nameToMail, visited, accounts, origin);
            }
        }
    }
    vector < vector < string > > accountsMerge(vector < vector < string > > &accounts) {
        vector < vector < int > >adjList(accounts.size());
        unordered_map < string, int > mailToIndex;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mailToIndex.find(accounts[i][j]) != mailToIndex.end()) {
                    adjList[i].push_back(mailToIndex[accounts[i][j]]);
                    adjList[mailToIndex[accounts[i][j]]].push_back(i);
                } else {
                    mailToIndex[accounts[i][j]] = i;
                }
            }
        }

        map < int, set < string > > nameToMail;
        vector < bool > visited(accounts.size(), false);
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false) {
                dfs(i, adjList, nameToMail, visited, accounts, i);
            }
        }

        vector < vector < string > > ans;
        vector < string > tempAns;
        for (auto x : nameToMail) {
            tempAns.clear();
            tempAns.push_back(accounts[x.first][0]);
            for (auto mail : x.second) {
                tempAns.push_back(mail);
            }
            ans.push_back(tempAns);
        }

        return ans;
    }
};
