#include <bits/stdc++.h>

using namespace std;

int findFirst(vector < int > &nums, int left, int right, int key)
{
	int ans = -1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == key) {
			ans = mid;
			right = mid - 1;
		} else if(key > nums[mid]) {
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

	cout<<findFirst(nums, 0, nums.size() - 1, k);
	

	return 0;
}
