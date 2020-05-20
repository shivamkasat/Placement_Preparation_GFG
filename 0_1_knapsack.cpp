#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector < int > &values, vector < int > &weights, int n, int w, vector < vector < int > > &dp)
{
	if (n == 0 || w == 0) {
		dp[n][w] = 0;
		return 0;
	}
	
	if (dp[n][w] != 0) {
		return dp[n][w];
	}

	int incAns = 0, excAns = 0;

	if (weights[n - 1] <= w) {
		incAns = values[n - 1] + maxProfit(values, weights, n - 1, w - weights[n - 1], dp);
	}

	excAns = maxProfit(values, weights, n - 1, w, dp);

	dp[n][w] = max(incAns, excAns);
	return dp[n][w];		
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		int w;
		cin>>n;
		cin>>w;
		vector < int > values(n,0);
		vector < int > weights(n, 0);

		vector < vector < int > >dp(n + 1, vector < int >(w + 1, 0));
		
		for (int i = 0; i < n; i++) {
			cin>>values[i];
		}

		for (int i = 0; i < n; i++) {
			cin>>weights[i];
		}
		
		int maxVal = maxProfit(values, weights, n, w, dp);
		cout<<maxVal<<" is the maxProfit"<<endl;

		test--;
	}
	return 0;
}
