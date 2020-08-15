#include <bits/stdc++.h>
using namespace std;

int firstIndexOfMatch(string &str, string &ptr) {
	if (ptr.length() > str.length()) {
		return -1;
	}
	vector < int > prefixTable(ptr.length(), 0);
	int i = 0;
	int j = 1;
	while (j < ptr.length()) {
		if (ptr[i] == ptr[j]) {
			prefixTable[j] = i + 1;
			i++;
			j++;
		} else {
			if (i == 0) {
				prefixTable[j] = 0;
				j++;
			} else {
				i = prefixTable[i - 1];
			}
		}
	}

	i = 0;
	j = 0;
	int firstIndex = 0;
	while (i < str.length() && j < ptr.length()) {
		if (str[i] == ptr[i]) {
			i++;
			j++;
		} else {
			if (j == 0) {
				i++;
				firstIndex = i;
			} else {
				j = prefixTable[j - 1];
			}
		}
	}

	if (j == n) {
		return firstIndex;
	} 

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		string str;
		string ptr;
		cin>>str;
		cin>>ptr;
		cout<<firstIndexOfMatch(str, ptr)<<endl;
	}
	return 0;
}