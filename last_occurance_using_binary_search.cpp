#include <bits/stdc++.h>

using namespace std;

int findLast(vector < int > &nums, int left, int right, int key)
{
	int ans = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == key) {
			ans = mid;
			left = mid + 1;
		} else if (key > nums[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans;
}

int main()
{
	int n, k;
	cin>>n>>k;

	vector < int > nums(n, 0);

	for (int i = 0; i < nums.size(); i++) {
		cin>>nums[i];
	}

	sort(nums.begin(), nums.end());

	cout<<findLast(nums, 0, nums.size() - 1, k);

	return 0;
}
