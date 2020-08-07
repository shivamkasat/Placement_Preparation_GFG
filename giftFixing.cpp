#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > oranges(n, 0);
		vector < int > candies(n, 0);
		int minCandies = INT_MAX;
		int minOranges = INT_MAX;
		for (auto &x : candies) {
			cin>>x;
			minCandies = min(minCandies, x);
		}

		for (auto &x : oranges) {
			cin>>x;
			minOranges = min(minOranges, x);
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			result += max((candies[i] - minCandies), (oranges[i] - minOranges));
		}
		cout<<result<<endl;
	}
	return 0;
}