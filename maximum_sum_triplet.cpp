#include <bits/stdc++.h>
#define ll long long
using namespace std;

// O(n2) solution it will give TLE.
int maxSumTriplet(vector < int > &nums) {
	int n = nums.size();
	int leftMax;
	int rightMax;
	ll maxTriplet = INT_MIN;
	for (int j = 1; j < n - 1; j++) {
		leftMax = INT_MIN;
		rightMax = INT_MIN;
		for (int i = 0; i < j; i++) {
			if (nums[i] < nums[j] && leftMax < nums[i]) {
				leftMax = nums[i];
			}
		}

		for (int i = j + 1; i < n; i++) {
			if (nums[i] > nums[j] && nums[i] > rightMax) {
				rightMax = nums[i];
			}
		}

		if (leftMax != INT_MIN && rightMax != INT_MIN) {
			maxTriplet = leftMax + rightMax + nums[j];
		}
	}

	return maxTriplet;
}

int getMaxTriplet(vector < int > &nums) {
	int n = nums.size();
	vector < int > rightMax(nums.size(), 0);
	rightMax[n - 1] = nums[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		rightMax[i] = max(nums[i], rightMax[i + 1]);
	}

	set < int > leftMax;
	leftMax.insert(nums[0]);
	int maxTriplet = 0;
	for (int i = 1; i < n - 1; i++) {
		auto itr = lower_bound(leftMax.begin(), leftMax.end(), nums[i]);
		leftMax.insert(nums[i]);
		if (itr == leftMax.begin() || rightMax[i + 1] <= nums[i]) {
			continue;
		}
		itr--;
		maxTriplet = max(maxTriplet, *itr + rightMax[i + 1] + nums[i]);
	}

	return maxTriplet;

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
		cout<<maxSumTriplet(nums)<<endl;
	}
	return 0;
}