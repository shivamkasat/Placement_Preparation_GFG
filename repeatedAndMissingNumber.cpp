#include <bits/stdc++.h>
using namespace std;

vector < int > findRepeatedAndMissingNumber(vector < int > &nums) {
	int xored = nums[0];
	int n = nums.size();
	vector < int > result;
	for (int i = 1; i < n; i++) {
		xored ^= nums[i];
	}
	for (int i = 1; i <= n; i++) {
		xored ^= i;
	}

	int right_most_set = xored & ~(xored - 1);
	int x = 0;
	int y = 0;

	for (int i = 0; i < n; i++) {
		if ((nums[i] & right_most_set) != 0) {
			x ^= nums[i];
		} else {
			y ^= nums[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if ((i & right_most_set) != 0) {
			x ^= i;
		} else {
			y ^= i;
		}
	}

	result.push_back(x);
	result.push_back(y);
	return result;
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
		result = findRepeatedAndMissingNumber(nums);
		for (auto x : result) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}