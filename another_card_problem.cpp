#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		float pc, pr;
		cin>>pc>>pr;
		int chef = ceil(pc / 9);
		int rick = ceil(pr / 9);
		if (chef < rick) {
			cout<<"0 "<<chef<<endl;
		} else {
			cout<<"1 "<<rick<<endl;
		} 
	}
	return 0;
}