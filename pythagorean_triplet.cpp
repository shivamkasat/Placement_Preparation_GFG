#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		
		int n;
		cin>>n;
		unordered_set < int > hmap;
		vector < int > nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
			hmap.insert(nums[i] * nums[i]);
		}

		int ans = false;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if ( hmap.find((nums[i] * nums[i]) + (nums[j] * nums[j])) != hmap.end()) {
					ans = true;
					break;
				} 
			}
		}
		
		if (ans == true) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}

	

		test--;
	}
	return 0;
}
