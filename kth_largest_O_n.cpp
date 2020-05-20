#include <bits/stdc++.h>

using namespace std;

void swap (int &n1, int &n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

int partition(vector < int > &nums, int start, int end)
{
	int pivotElement = nums[end];
	int pivotIndex = start;
	for (int i = start; i < end; i++) {
		if (nums[i] < pivotElement) {
			swap(nums[pivotIndex], nums[i]);
			pivotIndex++;
		}
	}
	swap(nums[pivotIndex], nums[end]);
	return pivotIndex;
}

int quickSelect(vector < int > &nums, int start, int end, int k)
{
	int partitionIndex;
	int n = nums.size();
	if (start <= end) {
		partitionIndex = partition(nums, start, end);
		if (partitionIndex > n - k) {
			return quickSelect(nums, start, partitionIndex -1, k);
		} else if (partitionIndex < n - k) {
			return quickSelect(nums, partitionIndex + 1, end, k);
		} else {
			return nums[partitionIndex];
		}
	}
}

int main()
{
	int n, k;
	cin>>n>>k;
	vector < int > nums(n, 0);
	for (int i = 0; i < nums.size(); i++) {
		cin>>nums[i];
	}

	int result = quickSelect(nums, 0, nums.size() - 1, k);
	printf("%d ", result);
	
	return 0;
}
