#include <bits/stdc++.h>
#define ll long long 
using namespace std;


//O(n2) solution! below there is O(n) solution
int partitionsPossible(vector < int > &nums) {
	ll sum = 0;
	int n = nums.size();
	vector < int > sums;
	for (auto x : nums) {
		sum += x;
		sums.push_back(sum);
	}

	if (sum % 3 != 0) {
		return false;
	}

	int partSum = sum / 3;
	int count = 0;
	for (int i = 0; i < n - 2; i++) {
		if (sum[i] != partSum) continue;
		for (int j = i + 1; j < n - 1; j++) {
			if (sum[i] == 2 * partSum) {
				count++;
			}
		}
	}

	return count;

}

//O(n) solution

int countPartions(vector < int > &nums) {
	ll sum = 0;
	int n = nums.size();
	vector < int > sums;
	for (auto x : nums) {
		sum += x;
		sums.push_back(sum);
	}

	if (sum % 3 != 0) {
		return 0;
	}

	int partSum = sum / 3;

	vector < int > count(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (sums[i] == 2 * partSum) {
			count[i] = 1 + count[i + 1];
		} else {
			count[i] = count[i + 1];
		}
	}

	int result = 0;

	for (int i = 0; i < n - 2; i++) {
		if (sums[i] == partSum) {
			result += count[i + 1];
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		cout<<partitionsPossible(nums)<<endl;
	}
	return 0;
}