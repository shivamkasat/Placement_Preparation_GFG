#include <bits/stdc++.h>
using namespace std;

int findFirstMissingPositive(vector < int > &nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		while (nums[i] > 0 && nums[i] - 1 < n && nums[i] != i + 1) swap(nums[i], nums[nums[i] - 1]);
	}

	cout<<"after arranging"<<endl;
	for (auto x : nums) {
		cout<<x<<" ";
	}
	cout<<endl;

	int ans = n + 1;
	for (int i = 0; i < n; i++){
		if (nums[i] != i + 1) {
			ans = i + 1;
			break;
		}
	}

	return ans;
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
		vector < int > nums(n, 0);
		for (auto &x : nums) {
			cin>>x;
		}

		cout<<findFirstMissingPositive(nums)<<endl;
	}
	return 0;
}