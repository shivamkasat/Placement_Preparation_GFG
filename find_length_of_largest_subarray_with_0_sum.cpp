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
		vector < int > preSum(n + 1, 0);

		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
			preSum[i + 1] = preSum[i] + nums[i];
		}

		int maxLength = 0;
		unordered_map < int, int > hmap;
		int length = 0;
		for (int i = 0; i < preSum.size(); i++) {
			if (hmap.find(preSum[i]) == hmap.end()) {
				hmap[preSum[i]] = i;	
			} else {
				length = i - hmap[preSum[i]];
				maxLength = length > maxLength ? length : maxLength;	
			}
		}
		
		/*
		cout<<endl<<"----------printing preSum------"<<endl;
		for (auto x : preSum) {
			cout<<x<<" ";
		}

		cout<<endl<<"--------------------------------"<<endl;


		cout<<"-------------printing hmap-----"<<endl;
		for (auto x : hmap) {
			cout<<"{"<<x.first<<", "<<x.second<<"}"<<endl;
		}
		*/
		printf("%d\n", maxLength);
		test--;
	}
}
