#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		if (n == 1) {
			cout<<"1";
		} else if (n == 2) {
			cout<<"2"<<endl;
		} else {
			cout<<n - 1<<endl;
		}
	}
	return 0;
}