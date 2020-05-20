#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int ropeLength;
		cin>>ropeLength;
		vector < int >dp(ropeLength+1, -1);
		vector < int >cuts(3, 0);
		int minLength = INT_MAX;	
		
		for (int i = 0; i < 3; i++) {
			cin>>cuts[i];
			minLength = min(minLength, cuts[i]);
		}

		// initializiing base cases
		dp[0] = 0;
		for (int i = 1; i < minLength; i++) {
			dp[i] = -1;
		}
		

		for (int i = 0; i <= ropeLength; i++) {
			for (int j = 0;j < 3; j++) {
				if (i >= cuts[j]) {
					if(dp[i - cuts[j]] != -1) {
						dp[i] = max(dp[i], 1 + dp[i - cuts[j]]);
					}
				}
			}
		}

		cout<<(dp[ropeLength] == -1 ? 0 : dp[ropeLength])<<endl;

		test--;
	}
	return 0;
}
