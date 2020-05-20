#include <bits/stdc++.h>

using namespace std;

bool checkFour(vector < int > &nums, int sum) 
{
	unordered_map < int, int > hmap;

	for (int i = 0; i < nums.size(); i++) {
		hmap[nums[i]]++;
	}

	cout<<"---------- printing hmap -------"<<endl;
	for (auto x : hmap) {
		cout<<x.first<<", "<<x.second;
	}
	cout<<"--------------------------------"<<endl;

	int reqVal = sum;
	cout<<reqVal<<"is reqVal"<<endl;
	for (int i = 0; i < nums.size(); i++) {
		hmap[nums[i]]--;
		reqVal -= nums[i];
		cout<<reqVal<<"is reqVal"<<endl;
		for (int j = i + 1; j < nums.size(); j++) {
			hmap[nums[j]]--;
			reqVal -= nums[j];
			cout<<reqVal<<"is reqVal"<<endl;
			for (int k = j + 1; k < nums.size(); k++) {
				hmap[nums[k]]--;
				reqVal -= nums[k];
				cout<<reqVal<<"is reqVal"<<endl;
				if (hmap.find(reqVal) != hmap.end() && hmap[reqVal] > 0) {
					return true;
				} else {
					hmap[nums[k]]++;
					reqVal += nums[k];
				}
			}
			hmap[nums[j]]++;
			reqVal += nums[j];	
		}
		reqVal += nums[i];
		hmap[nums[i]]++;
	}

	return false;
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
		int sum;
		cin>>sum;
			
		bool result;
		result = checkFour(nums, sum);

		if (result == true) {
			cout<<"1"<<endl;
		} else {
			cout<<"0"<<endl;
		}

		test--;
	}
	return 0;
}
