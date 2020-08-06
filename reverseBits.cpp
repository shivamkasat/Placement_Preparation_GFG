#include <bits/stdc++.h>
using namespace std;
unsigned int reverseBits(unsigned int n) {
	int res;
	if (n & 1 == 0) {
		res = 0;
	} else {
		res = 1;
	}
	n = n >> 1;
	unsigned int lastBit;
	for (int i = 0; i < 31; i++) {
		lastBit = n & 1;
		res = res<<1;
		res = res | lastBit;
	}

	return res;
}
int main() {
	unsigned int n;
	cin>>n;
	cout<<reverseBits(n);
	return 0;
}