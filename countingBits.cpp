#include <bits/stdc++.h>
using namespace std;

vector < int > countBits(int n) {
	vector < int > dp(n + 1, 0);
	dp[1] = 1;
	dp[0] = 0;
	int lastPowerOfTwo = 0;
	for (int i = 2; i < n + 1; i++) {
		if (i & (i - 1) == 0) {
			dp[i] = 1;
			lastPowerOfTwo = i;
		} else {
			dp[i] = dp[lastPowerOfTwo] + dp[i - lastPowerOfTwo];
		}
	}
	return dp;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > result = countBits(n);
		for (auto x : result) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}