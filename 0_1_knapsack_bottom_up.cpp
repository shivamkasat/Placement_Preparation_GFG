#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector < int > &values, vector < int > &weights, int W) {
	vector < vector < int > >dp(values.size() + 1, vector < int >(W + 1, 0));
	for (int i = 0; i <= values.size(); i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
				continue;
			}
			
			int insAns = 0, exAns = 0;

			if (weights[i - 1] <= w) {
				insAns = values[i - 1] + dp[i - 1][w - weights[i - 1]];
			}

			exAns = dp[i - 1][w];

			dp[i][w] = max(insAns, exAns);
				
		}
	}

	for(auto x : dp) {
		for (auto y : x) {
			cout<<y<<" ";
		}
		cout<<endl;
	}

	return dp[values.size()][W];
}

int main() 
{
	int test;
	cin>>test;
	while (test > 0) {
		int N;
		cin>>N;
		int W;
		cin>>W;

		vector < int > values(N, 0);
		vector < int > weights(N, 0);

		for (int i = 0; i < N; i++) {
			cin>>values[i];
		}

		for (int i = 0; i < N; i++) {
			cin>>weights[i];
		}

		cout<<maxProfit(values, weights,W)<<endl;

		test--;
	}
	return 0;
}
