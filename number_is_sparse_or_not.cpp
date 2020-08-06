#include <bits/stdc++.h>
using namespace std;

bool checkSparse(int n) {
	if (n & (n >> 1)) {
		return false;
	}	
	return true;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		cout<<checkSparse(n)<<endl;
	}
	return 0;
}