#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector < int > &nums, int size) {
	int i,j,p;
	i = j = p = 0;
	while (j < nums.size()) {
		while(nums[i] == nums[j] && j < nums.size()) {
			j++;
		}

		nums[p] = nums[i];
		i=j;
		p++;
	}

	return p;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		
		vector < int > nums(n, 0);
		
		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
		}

		sort(nums.begin(), nums.end());
		
		int lastIndex = removeDuplicates(nums, nums.size());
		
		for (int i = 0; i < lastIndex; i++) {
			printf("%d ", nums[i]);
		}	

		test--;
	}
}
