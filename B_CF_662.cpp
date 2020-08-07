#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector < int > count(100001, 0);
	set < pair < int, int > > moreThanFour;
	set < pair < int, int > > moreThanTwo; 
	int plankSize;

	for (int i = 0; i < n; i++) {
		cin>>plankSize;
		count[plankSize]++;
	}

	for (int i = 0; i < n; i++) {
		if (count[i] >= 4) {
			moreThanFour.insert({count[i], i});
		} else if (count[i] >= 2) {
			moreThanTwo.insert({count[i], i});
		}
	}

	int q;
	cin>>q;
	char sym;
	for (int i = 0; i < q; i++) {
		cin>>sym;
		cin>>plankSize;
		if (sym == '+') {
			if (count[plankSize] >= 4) {
				moreThanFour.erase({count[plankSize], plankSize});
				moreThanFour.insert({count[plankSize] + 1, plankSize});
			} else if (count[plankSize] == 3) {
				moreThanTwo.erase({count[plankSize], plankSize});
				moreThanFour.insert({count[plankSize] + 1, plankSize});
			} else if (count[plankSize] == 2) {
				moreThanTwo.erase({count[plankSize], plankSize});
				moreThanTwo.insert({count[plankSize] + 1, plankSize});
			} else if (count[plankSize] == 1) {
				moreThanTwo.insert({count[plankSize] + 1, plankSize});
			}
			count[plankSize]++;
		} else {
			if (count[plankSize] > 4) {
				moreThanFour.erase({count[plankSize], plankSize});
				moreThanFour.insert({count[plankSize] - 1, plankSize});
			} else if (count[plankSize] == 4) {
				moreThanFour.erase({count[plankSize], plankSize});
				moreThanTwo.insert({count[plankSize] - 1, plankSize});
			} else if (count[plankSize] == 3) {
				moreThanTwo.erase({count[plankSize], plankSize});
				moreThanTwo.insert({count[plankSize] - 1, plankSize});
			} else if (count[plankSize] == 2) {
				moreThanTwo.erase({count[plankSize], plankSize});
			}
			count[plankSize]--;
		}

		if (moreThanFour.size() < 1) {
			cout<<"NO"<<endl;
		} else if (moreThanFour.size() >= 2) {
			cout<<"YES"<<endl;
		} else if (moreThanFour.size() == 1) {
			if (moreThanFour.begin()->first >= 8) {
				cout<<"YES"<<endl;
			} else {
				int rem = moreThanFour.begin()->first - 4;
				if (rem >= 2 && moreThanTwo.size() >= 1) {
					cout<<"YES"<<endl;
				} else if (moreThanTwo.size() >= 2) {
					cout<<"YES"<<endl;
				} else {
					cout<<"NO"<<endl;
				}
			}
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}