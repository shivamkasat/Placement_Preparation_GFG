#include <bits/stdc++.h>
using namespace std;

class comp {
     public:
	bool operator()(pair < int, int > a, pair < int, int > b) {
		return (a.first - floor(a.first / 2)) * a.second > (b.first - floor(b.first / 2)) * b.second; 
	}
};

multiset < pair < int, int >, comp > hset;
int sum; 
int N = 1e5 + 5;
vector < pair < int, int > > adjList[N];
bool visited[N];
int dfs(int start, vector < bool > &visited) {
	visited[start] = true;

	int leafNodes = 0;
	int totalLeafNodes = 0;
	for (auto x : adjList[start]) {
		if(visited[x.first] == false) {
			leafNodes = dfs(x.first, visited);
			totalLeafNodes += leafNodes;
			sum += x.second * leafNodes;
			hset.insert({x.second, leafNodes});
		}
	}
	
	if (totalLeafNodes == 0) {
	     totalLeafNodes = 1;
	}

	return totalLeafNodes;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		int limit;
		cin>>limit;
		for (int i = 1; i < n + 1; i++) {
		    adjList[i].clear();
		}
		int u, v, w;
		for (int i = 0; i < n - 1; i++) {
			cin>>u>>v>>w;
			adjList[u].push_back({v, w});
			adjList[v].push_back({u, w});
		}
		sum = 0;
		hset.clear();
		memset(visited, false, sizeof(visited));
		int totalLeafNodes = dfs(1, visited);
		pair < int, int > top;
		int ans = 0;
		while (sum > limit) {
			ans++;
			top = *hset.begin();
			hset.erase(top);
			sum -= (top.first * top.second);
			top.first /= 2;
			if (top.first) {
			     sum += top.first * top.second;
			     hset.insert(top);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}