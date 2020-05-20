#include <bits/stdc++.h>

using namespace std;

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

		vector < int > result(n,0);
		result[n - 1] = -1;
		
		for (int i = n - 1,j = n - 1; i > 0; i--, j--) {
			if (nums[i] > result[j]) {
				result[j - 1] = nums[i];	
			} else {
				result[j - 1] = result[j];
			}
		}

		for (int i = 0; i < n; i++) {
			printf("%d ", result[i]);
		}

		test--;
	}

	return 0;
}
