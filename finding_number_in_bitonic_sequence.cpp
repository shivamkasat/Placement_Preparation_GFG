#include <bits/stdc++.h>

using namespace std;

int findPeak(vector < int > &nums)
{
	int start = 0;
	int end = nums.size() - 1;
	int ans = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < 0) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int reverseLowerBound(vector < int > &nums, int left, int right, int k)
{
	int ans = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= k) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans;

}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		vector < int > diff(n -1, 0);

		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
			if (i > 0) {
				diff[i - 1] = nums[i] - nums[i - 1];
			}
		}

		int k;
		cin>>k;

		int peakIndex = findPeak(diff);
		//cout<<"peakIndex = "<<peakIndex<<endl;
		int ans = -1;
		
		auto itr = lower_bound(nums.begin(), nums.begin() + peakIndex, k);
		int foundIndex = reverseLowerBound(nums, peakIndex + 1, nums.size() - 1, k);
		
		if (*itr == k) {
			ans = int (itr - nums.begin());
		} else if (nums[foundIndex] == k) {
			ans = foundIndex;	
		}

		cout<<ans<<endl;

		test--;
	}
	return 0;
}
