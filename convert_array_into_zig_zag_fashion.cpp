#include <bits/stdc++.h>
using namespace std;

void swap (int &n1, int &n2)
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

		int flag = 1;

		for (int i = 0; i < nums.size() - 1; i++) {
			if (flag == 1) {
				if (nums[i + 1] < nums[i]) {
					swap(nums[i + 1], nums[i]);
				}
				flag = 0;
			} else {
				if (nums[i + 1] > nums[i]) {
					swap(nums[i + 1], nums[i]);
				}
				flag = 1;
			}
		}
	
		for (int i = 0; i < nums.size(); i++) {
			cout<<nums[i]<<" ";
		}

		test--;
	}

	return 0;
}
