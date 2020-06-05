#include <bits/stdc++.h>
using namespace std;

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

		int count = 0;
		int i = 0;
		int j = n - 1;
		int leftSum = nums[i];
		int rightSum = nums[j];

		while (i < j) {
			while (i < j && leftSum < rightSum) {
				i++;
				leftSum += nums[i];
				count++;
			}

			while (j > i && rightSum < leftSum) {
				j--;
				rightSum += nums[j];
				count++;
			}

			while ( i < j && leftSum == rightSum) {
				i++;
				j--;
				leftSum = nums[i];
				rightSum = nums[j];
			}
		}

		cout<<count<<endl;
	}
	return 0;
}
