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
		vector < int > nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		if (nums[0] + nums[1] <= nums[n - 1]) {
			cout<<"0 1 "<<n - 1<<endl;
		}
	}
	return 0;
}