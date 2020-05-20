#include <bits/stdc++.h>
#define ll long long

using namespace std;

int findFirstNeg(vector < ll > &diff)
{
	int firstNegIndex = -1;
	for(int i = 0; i < diff.size(); i++) {
		if (diff[i] < 0) {
			firstNegIndex = i;
			break;
		}
	}

	return firstNegIndex;
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
		
		
		/*		
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
		*/

		ll firstNegIndex = findFirstNeg(diff);
		int rotationCount = firstNegIndex + 1;
		cout<<rotationCount<<endl;		

		test--;
	}
	return 0;
}
