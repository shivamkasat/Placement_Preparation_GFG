#include <bits/stdc++.h>
#define fLoop(x) for(int i = 0; i < x; i++)
using namespace std;
void swap(int &num1, int &num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int partition(vector < int > &nums, int start, int end)
{
	int randomIndex = rand();
	printf("random index = %d", randomIndex);
	int pivotElement = nums[end];
	int pivotIndex = start;
	for (int i = start; i < end; i++) {
		if (nums[i] <= pivotElement) {
			swap(nums[i], nums[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(nums[pivotIndex], nums[end]);
	return pivotIndex;
}

void quickSort(vector < int > &nums, int start, int end)
{
	if(start < end) {
		int partitionIndex;

		partitionIndex = partition(nums, start, end);
		quickSort(nums, start, partitionIndex - 1);
		quickSort(nums, partitionIndex + 1, end);
	}
}



int main()
{
	vector < int > nums;
	int num, elem;

	cin>>num;
	
	for (int i = 0; i < num; i++) {
		cin>>elem;
		nums.push_back(elem);
	}
	
	srand(time(0));
	quickSort(nums, 0, nums.size() - 1);

	fLoop(nums.size())
		printf("%d ", nums[i]);

	return 0;
}
