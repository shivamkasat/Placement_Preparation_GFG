#include <bits/stdc++.h>
using namespace std;

void findNextPerm(vector < int > &nums) {
	int n = nums.size();
	int i = n - 2;
	for (; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			break;
		}
	}

	if (i == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}

	sort(nums, i + 1, n);
	int j = i + 1	
	for (; j < n; j++) {
		if (nums[j] > nums[i]) {
			break;
		}
	}
	swap(nums[i], nums[j]);
	return;
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
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		vector < int > result;
		result = findNextPerm(nums);
		for (auto x : result) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}