#include <bits/stdc++.h>
using namespace std;

vector < int > maxSum(vector < int > &nums) {
	int sum = 0;
	int maxSum = 0;
	vector < int > result;
	vector < int > temp;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= 0) {
			sum += nums[i];
			temp.push_back(nums[i]);
		} else {
			if (sum > maxSum) {
				result = temp;
				maxSum = sum;
			} else if (sum == maxSum) {
				if (temp.size() > result.size()) {
					result = temp;
				}
			}
			temp.clear();
			sum = 0;
		}
	}

	if (sum > maxSum) {
		result = temp;
		maxSum = sum;
	} else if (sum == maxSum) {
		if (temp.size() > result.size()) {
			result = temp;
		}
	}				

	return result;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector < int > nums(n, 0);
	for (auto &x : nums) {
		cin>>x;
	}
	vector < int > result = maxSum(nums);
	for (auto x : result) {
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}