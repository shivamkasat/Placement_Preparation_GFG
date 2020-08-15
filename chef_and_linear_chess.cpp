#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		int k;
		cin>>k;
		int p;
		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin>>p;
			if (k % p == 0) {
				ans = min(ans, (k / p) - 1);
			}
		}

		if (ans == INT_MAX) {
			cout<<"-1"<<endl;
		} else {
			cout<<ans<<endl;
		}
	}
	return 0;
}