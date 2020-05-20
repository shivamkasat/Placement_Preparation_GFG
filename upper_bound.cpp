#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector < int > &nums, int left, int right, int key)
{
	int ans = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > key) {
			ans = mid;
			right = mid - 1;
		} else if (nums[mid] <= key) {
			left = mid + 1;
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

	int index = lower_bound(nums, 0, nums.size() - 1, k);
	
	if (index == -1) {
		cout<<"no such number"<<endl;	
	} else {
		cout<<nums[index]<<endl;
	}
	return 0;
}
