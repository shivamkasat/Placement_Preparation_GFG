#include <bits/stdc++.h>
using namespace std;

//Smart Solution
int diffBitsSum(vector < int > &nums) {
	int setCount = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] & 1 != 0) {
				setCount++;
			}
			nums[j] >>= 1;
		}
		sum = (sum % mod + (nums.size() * setCount) % mod) % mod;
	}	
	return sum;
}


// Trivial approach
// int diffBitsSum(vector < int > &nums) {
// 	unordered_map < int, int > hmap;
// 	int sum = 0;
// 	int mod = 1e9 + 7;
// 	int xoredVal;
// 	for (int i = 0; i < nums.size(); i++) {
// 		for (int j = 0; j < nums.size(); j++) {
// 			xoredVal = nums[i] ^ nums[j];
// 			if (xoredVal != 0) {
// 				if (hmap.find(xoredVal) != hmap.end()) {
// 					sum = (sum % mod + hmap[xoredVal] % mod) % mod;
// 				} else {
// 					hmap[xoredVal] = __builtin_popcount(xoredVal);
// 					sum = (sum % mod + hmap[xoredVal] % mod) % mod;	
// 				}
// 			}
// 		}
// 	}

// 	return sum;
// }

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (auto &x: nums) {
			cin>>x;
		}
		cout<<diffBitsSum(nums)<<endl;
	}
	return 0;
}