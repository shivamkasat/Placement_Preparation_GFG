#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
		}

		int max = nums[0];
		unordered_map < int, int > hmap;

		for (int i = 1; i < nums.size() - 1; i++) {
			if (nums[i] >= max) {
				max = nums[i];
				if(hmap.find(max) == hmap.end()) {
					hmap.insert({max, i});
				} else {
					auto p = hmap.find(max);
					if (p->second < i) {
						hmap[max] = i;
					}
				}
			}
		}
		cout<<"----------"<<endl;
		for (auto x : hmap) {
			cout<<"{"<<x.first<<", "<<x.second<<"}"<<" ";
		}
		cout<<endl<<"---------"<<endl;	
		int ans = -1;
		int flag = 0;
		int min = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i > 0; i--) {
			if (nums[i] <= min) {
				min = nums[i];
				if (hmap.find(min) != hmap.end()) {
					auto p = hmap.find(min);
					if (p->first == min  && p->second == i) {
						ans = min;
					}
				}
			}
		}

		printf("%d\n", ans);

		test--;
	}
	return 0;
}
