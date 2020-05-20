#include <bits/stdc++.h>

using namespace std;

int findMaxDiff(vector < int > &diff) {
	int differ = diff[0];
	int maxDiff = diff[0];

	for (int i = 1; i < diff.size(); i++) {
		differ = max(differ + diff[i], diff[i]);
		maxDiff = max(maxDiff, differ);
	}

	if (maxDiff > 0) {
		return maxDiff;
	}

	return -1;
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

		vector < int > diff;

		for (int i = 1; i < nums.size(); i++) {
			diff.push_back(nums[i] - nums[i - 1]);
		}
		
		int maxDiff;
		maxDiff = findMaxDiff(diff);	
		cout<<maxDiff<<endl;

		test--;
	}
	return 0;
}
