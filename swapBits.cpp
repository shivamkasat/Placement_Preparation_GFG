#include <bits/stdc++.h>
using namespace std;

int swapBits(int n) {
	int mask = 3;
	int copy = num;
	while (copy != 0) {
		if ((copy & 3 == 1) || (copy & 3 == 2)) {
			num = num ^ mask;
		}
		mask <<= 2;
		copy >>= 2;
	}

	return num;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		cout<<swapBits(n)<<endl;
	}
	return 0;
}