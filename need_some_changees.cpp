#include <bits/stdc++.h>
using namespace std;

void swap (int &n1, int &n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

void swapElements(vector < int > &nums, int arrSize)
{
	for (int i = 0; i < nums.size() - 2; i++) {
		swap(nums[i], nums[i + 2]);
	}
}
int main()
{
	int n;
	cin>>n;
	vector < int > nums(n, 0);
	for (int i = 0; i < nums.size(); i++) {
		cin>>nums[i];
	}

	swapElements(nums, nums.size());

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
		

	return 0;
}
