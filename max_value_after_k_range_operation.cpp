#include <bits/stdc++.h>

using namespace std;

int findMax(vector < int > &nums)
{
	int max = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		max = max < nums[i] ? nums[i] : max;
	}
	return max;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		int m;
		cin>>n;
		cin>>m;
		
		vector < int > nums(n, 0);
		
		while (m > 0) {
			
			int left, right, inc;
			cin>>left>>right>>inc;

			nums[left] += inc;

			if (right < nums.size() - 1) {
				nums[right + 1] -= inc;
			}
		
			m--;
		}
		
		for (int i = 0; i < nums.size() - 1; i++) {
			nums[i + 1] += nums[i];
		}
		
		int result = findMax(nums);
		
		cout<<result;

		test--;
	}
}
