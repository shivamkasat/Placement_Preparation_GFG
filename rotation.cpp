#include <bits/stdc++.h>
#define ll long long

using namespace std;

int findFirstNeg(vector < ll > &diff, ll left, ll right) 
{
	ll ans = -1;
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		if (diff[mid] < 0) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	
	}

	return ans;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		ll n;
		cin>>n;
		vector < ll > nums(n, 0);
		vector < ll > diff(n -1, 0);
		for (int i = 0; i < nums.size(); i++) {
			cin>>nums[i];
			if (i > 0) {
				diff[i -1] = nums[i] - nums[i - 1];
			}
			
		}
		
			
		cout<<"------------- printing diff ----------------------------------"<<endl;
		for (auto x : diff) {
			cout<<x<<" ";
		}

		cout<<endl<<"---------------------------------------------------------"<<endl;

		for (int i = 1; i < diff.size(); i++) {
			diff[i] += diff[i - 1];
		}
		
		cout<<"------------- printing diff after prefix sum------------"<<endl;
		for (auto x : diff) {
			cout<<x<<" ";
		}

		cout<<endl<<"---------------------------------------------------------"<<endl;

		ll firstNegIndex = findFirstNeg(diff, 0, diff.size() - 1);
		
		cout<<firstNegIndex + 1<<endl;

		test--;
	}
	return 0;
}
