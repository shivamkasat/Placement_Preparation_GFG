#include <bits/stdc++.h>
using namespace std;


int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (auto &x : nums) {
			cin>>x;
		}
		sort(nums.begin(), nums.end());
		string ans = "YES";
		for (int i = 0; i < n - 1; i++) {
			if (nums[i + 1] - nums[i] > 1) {
				ans = "NO";
				break;
			}
		}

		cout<<ans<<endl;

	}
	return 0;
}