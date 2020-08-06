#include <bits/stdc++.h>
using namespace std;

int findProd(vector < int > &nums, int startIndex, int endIndex) {
	if (startIndex + 1 == endIndex) {
		return nums[startIndex];
	} else if (startIndex == endIndex) {
		return 0;
	}

	vector < int > newNums;
	for (int i = startIndex; i < endIndex; i++) {
		newNums.push_back(nums[i]);
	}

	int firstNegIndex = -1;
	int lastNegIndex = -1;
	int currentProd = 1;
	vector < int > dp(newNums.size(), 1);
	for (int i = 0; i < newNums.size(); i++) {
		if (nums[i] < 0) {
			if (firstNegIndex == -1) {
				firstNegIndex = i;
			} 
			lastNegIndex = i;
		}
		currentProd = currentProd * newNums[i];
		dp[i] = currentProd;
	}

	int n = newNums.size();
	if (dp[n - 1] > 0) {
		return dp[n - 1];
	} 

	int maxProd = INT_MIN;
	maxProd = max(maxProd, dp[n - 1] / dp[firstNegIndex]);
	if (lastNegIndex > 0)
		maxProd = max(maxProd, dp[lastNegIndex - 1])
	return maxProd;
}

int findMaxProd(vector < int > &nums) {
	int startIndex = 0;
	int endIndex = 0;
	while (endIndex < nums.size()) {
		if (nums[endIndex] == 0) {
			maxProd = max(maxProd, findProd(nums, startIndex, endIndex));
			startIndex = endIndex;
		}
		endIndex++;
	}

	maxProd = max(maxProd, findProd(nums, startIndex, endIndex));
	return maxProd;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums;
		int num;
		for (int i = 0; i < n; i++) {
			cin>>num;
			nums.push_back(num);
		}
		cout<<findMaxProd(nums)<<endl;
	}
	return 0;
}