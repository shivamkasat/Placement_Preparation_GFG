#include <bits/stdc++.h>
using namespace std;

int minSteps(vector < int > &xCords, vector < int > &yCords) {
	int x = xCords[0];
	int y = yCords[0];
	int minSteps = 0;
	for (int i = 1; i < xCords.size(); i++) {
		minSteps += max(abs(xCords[i] - x), abs(yCords[i] - y));
		x = xCords[i];
		y = yCords[i];
	}

	return minSteps;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > xCords(n, 0);
		vector < int > yCords(n, 0);
		for (auto &x : xCords) {
			cin>>x;
		}

		for (auto &y : yCords) {
			cin>>y;
		}

		cout<<minSteps(xCords, yCords)<<endl;
	}
	return 0;
}