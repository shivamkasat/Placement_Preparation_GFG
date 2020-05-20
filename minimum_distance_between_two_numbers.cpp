#include <bits/stdc++.h>

using namespace std;

int minDistance(vector < int > &nums, int n1, int n2)
{
	int n1Index = -1;
	int n2Index = -1;
	int minDistance = nums.size(); 

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == n1) {
			n1Index = i;
		}

		if (nums[i] == n2) {
			n2Index = i;
		}
		if (nums[n1Index] == n1 && nums[n2Index] == n2)
			minDistance = abs(n2Index - n1Index) < minDistance ? abs(n1Index - n2Index) : minDistance;	
	}

	if (minDistance < nums.size()) {
		return minDistance; 
	} else {
		return -1;
	}
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
		
		int n1, n2;
		cin>>n1>>n2;

		cout<<minDistance(nums, n1, n2)<<endl;

		test--;
	}
	return 0;
}
