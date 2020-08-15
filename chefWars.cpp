#include <bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin>>test;
	while (test--) {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		int h;
		int p;
		cin>>h;
		cin>>p;
		if (h == 0) {
			cout<<"1"<<endl;
			continue;
		}
		if (p == 0) {
			cout<<"0"<<endl;
			continue;
		}

		while (h > 0 && p > 0) {
			h = h - p;
			if (h == 0) {
				cout<<"1"<<endl;
				break;
			}
			p = p / 2;
			if (p == 0) {
				cout<<"0"<<endl;
				break;
			}
		}

	}
	return 0;
}