#include <bits/stdc++.h>
using namespace std;

int countPossible(vector < int > &weights, int total) {
	unordered_map < int, int > hmap;
	int count = 0;
	for (int i = 0; i < weights.size(); i++) {
		if (hmap.find(total - weights[i]) != hmap.end() && hmap[total - weights[i]] > 0) {
			count++;
			hmap[total - weights[i]]--;
		} else {
			hmap[weights[i]]++;
		}
	}
	return count;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > weights(n, 0);
		for (auto &w : weights) {
			cin>>w;
		}
		int count = 1;
		int maxCount = 1;
		for (int i = 2; i <= 100; i++) {
			count = countPossible(weights, i);
			maxCount = max(maxCount, count);
		}
	}
	return 0;
}