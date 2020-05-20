#include <bits/stdc++.h>

using namespace std;

void swap(int &n1, int &n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
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
		
		int i = 0; 
		int j = nums.size() - 1;

		while (i < j) {
			while (nums[i] != 1 && i < j) {
				i++;
			}

			while (nums[j] != 0 && j > i) {
				j--;
			}
			
			swap(nums[i], nums[j]);
			
			i++;
			j--;

		}

		for (int i = 0; i < nums.size(); i++) {
			printf("%d ", nums[i]);
		}

		test--;
	}
	return 0;
}
