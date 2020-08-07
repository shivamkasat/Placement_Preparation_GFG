#include <bits/stdc++.h>
using namespace std;

int countTotalSetBits(int n) {
	int sum = 0;
	int numCount = 0;
	for (int i = 0; i < 32; i++) {
		numCount = 0;
		for (int j = 1; j <= n; j++) {
			if ((j >> i) & 1 != 0) {
				numCount++;
			}

		}

		sum = (sum % mod + (numCount % mod)) % mod;
	}

	return sum;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		cout<<countTotalSetBits(n)<<endl;
	}
	return 0;
}