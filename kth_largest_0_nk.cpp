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


int findKthLargest(vector<int>& nums, int k) {

	for (int i = 0; i < k - 1; i++) {

		int intMax = nums[0], intMaxIndex = 0;

		for (int i = 0; i < nums.size(); i++) {
			intMaxIndex = intMax < nums[i] ? i : intMaxIndex;
			intMax = intMax < nums[i] ? nums[i] : intMax;
		}
		
		swap(nums[intMaxIndex], nums[nums.size() - 1]);

		nums.pop_back();

	}

	int kMax = nums[0];

	for (int i = 0; i < nums.size(); i++) {
		kMax = kMax < nums[i] ? nums[i] : kMax;
	}

	return kMax;       
}

int main()
{
	vector < int > nums;
	int num, elem, k;

	cin>>num>>k;

	for (int i = 0; i < num; i++) {
		cin>>elem;
		nums.push_back(elem);
	}

	int result;
	result = findKthLargest(nums, k);

	printf("%d ", result);

	return 0;
}
