#include <bits/stdc++.h>
using namespace std;

int findPerfectPeak(vector < int > &nums) {
	int n = nums.size();
	if (n == 1) {
		return 1;
	}
	vector < int > left(n, 0);
	left[0] = nums[0];
	vector < int > right(n, 0);
	right[n - 1] = nums[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(nums[i], left[i - 1]);
	}

	for (int i = n - 2; i >= 0; i--) {
		right[i] = min(right[i + 1], nums[i]);
	}


	for (int i = 1; i < n - 1; i++) {
		if (nums[i] > left[i - 1] && nums[i] < right[i + 1]) {
			return 1;
		}
	}

	return 0;

}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		cout<<findPerfectPeak(nums)<<endl;
	}
	return 0;
}