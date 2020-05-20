#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector < int > &nums, int left, int right, int key)
{
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == key) {
			return mid;
		} else if (key > nums[mid]) {
			left = mid + 1;
			return binarySearch(nums, left, right, key);
		} else {
			right = mid - 1;
			return binarySearch(nums, left, right, key);
		}
	} else {
		return -1;
	}
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

	cout<<binarySearch(nums, 0, nums.size() - 1, k);
	

	return 0;
}
