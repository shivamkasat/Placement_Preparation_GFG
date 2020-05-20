#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n, k;
		cin>>n>>k;
		int data;
		bool ans = false;
		unordered_set < int > hmap;
		for (int i = 0; i < n; i++) {
			cin>>data;
			if (hmap.find(k - data) != hmap.end()) {
				ans = true;
				break;
			} else {
				hmap.insert(data);
			}	
		}

		/*
		cout<<"printing hmap"<<endl;
		for (auto x : hmap) {
			cout<<x<<" ";
		}
		*/
		if (ans == true) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		
		test--;
	}
	return 0;
}
