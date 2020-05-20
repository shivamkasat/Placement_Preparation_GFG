#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		vector < int >arr(n, 0);
		vector < int > dp(n, 1);
		int maxSeq = 1;

		for (int i = 0; i < n; i++) {
			cin>>arr[i];
		}

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < j; i++) {
				if (arr[j] > arr[i]) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
			maxSeq = max(dp[j], maxSeq);
		}

		cout<<maxSeq<<endl;
		test--;
	}
}
