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

		int k;
		cin>>k;

		int count = 0;
		int maxCount = 0;
		int windowSize = 0;
		for(int i = 0; i < nums.size(); i++) {
			if (nums[i] <= k) {
				windowSize++;
			}
		}

		//cout<<"window size"<<windowSize<<endl;

		for (int i = 0; i < windowSize; i++) {
			if (nums[i] <= k) {
				count++;
			}
		}

		maxCount = count;

		//cout<<"initial count in window "<<count<<endl;
		
		//cout<<"first interval is "<<nums[0]<<","<<nums[windowSize - 1]<<endl;
		for (int i = 0, j = i + windowSize - 1; j < nums.size() - 1; i++, j++) {
			if (nums[i] <= k) {
				count--;
			}

			if (nums[j + 1] <= k) {
				count++;
			}
		
			//cout<<"interval is ["<<nums[i + 1]<<", "<<nums[j + 1]<<"]";	
			//cout<<i + 1<<" iteration count = "<<count<<endl;
			maxCount = count > maxCount ? count : maxCount;
		}

		printf("%d\n", windowSize - maxCount);


		test--;
	}
	return 0;
}
