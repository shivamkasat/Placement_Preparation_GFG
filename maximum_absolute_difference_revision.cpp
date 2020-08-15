#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maximumAbsoluteDiff(vector < int > &nums) {
     int n = nums.size();
	vector < ll > valPlusIndex(n, 0);
	ll plusMax = nums[0];
	ll plusMin = nums[0];
	ll minusMax = nums[0];
	ll minusMin = nums[0];
	vector < ll > valMinusIndex(n, 0);
	valPlusIndex[0] = nums[0];
	valMinusIndex[0] = nums[0];
	for (int i = 1; i < n; i++) {
		valPlusIndex[i] = nums[i] + i;
		valMinusIndex[i] = nums[i] - i;
		plusMax = max(plusMax, valPlusIndex[i]);
		plusMin = min(plusMin, valPlusIndex[i]);
		minusMax = max(minusMax, valMinusIndex[i]);
		minusMin = min(minusMin, valMinusIndex[i]);
	}

	ll max1 = plusMax - plusMin;
	ll max2 = minusMax - minusMin;

	int result =  max((int)max1, (int)max2);
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
		cout<<maximumAbsoluteDiff(nums)<<endl;
	}	
	return 0;
}