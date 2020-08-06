#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

vector < int > solve(int a, int b, int c, int d) {
	vector < int > result;
	if (a == 0 || b == 0 || c == 0) {
		return result;
	}
	int limit = 1e6 + 1;
	vector < int > dp(limit , 0);
	dp[0] = 0;
	dp[a] = 1;
	dp[b] = 1;
	dp[c] = 1;
	for (int i = 1; i < limit; i++) {
		if (i % a == 0 && dp[i / a] == 1) {
			dp[i] = 1;
		} else if (i % b == 0 && dp[i / b] == 1) {
			dp[i] = 1;
		} else if (i % c == 0 && dp[i / c] == 1) {
			dp[i] = 1;
		}

		if (dp[i] == 1) {
			result.push_back(i);
			d--;
			if (d == 0) {
				break;
			}
		}
	}

	return result;


}

int main() {
	int test;
	cin>>test;
	while(test--) {
		int a;
		int b;
		int c;
		cin>>a>>b>>c;
		int d;
		cin>>d;
		vector < int > result;
		result = solve(a, b, c, d);
		for (auto x : result) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}