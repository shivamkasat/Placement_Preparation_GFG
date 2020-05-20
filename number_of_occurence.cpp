#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		
		int n, key;
		cin>>n>>key;

		vector < int > nums(n, 0);

		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
		}

		vector < int > :: iterator firstOccr;

		firstOccr = lower_bound(nums.begin(), nums.end(), key);

		if (firstOccr == nums.end()) {
			printf("-1");	
		} else {
			vector < int > :: iterator lastOccr;
			lastOccr = upper_bound(nums.begin(), nums.end(), key);
			int count = (int ) (lastOccr - firstOccr);
			printf("%d ", count);
		}
		printf("\n");
		test--;
	}

	return 0;
}
