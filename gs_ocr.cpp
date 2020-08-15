#include <bits/stdc++.h>
using namespace std;

bool checkMatch(string &str, string &ptr, int s, int p) {
	if (s == 0 && p == 0) {
		return true;
	} else if (s != 0 && p == 0) {
		return false;
	} else if (s == 0 && p != 0) {
		if (ptr[p - 1] == '@') {
			return checkMatch(str, ptr, s, p - 1);
		} else {
			return false;
		}
	}

	if (ptr[p - 1] == '$') {
		return checkMatch(str, ptr, s - 1, p - 1);
	} else if (ptr[p - 1] != '@') {
		if (str[s - 1] == ptr[p - 1]) {
			return checkMatch(str, ptr, s - 1, p - 1);
		} else {
			return false;
		}
	} else {
		bool first = checkMatch(str, ptr, s - 1, p);
		bool second = checkMatch(str, ptr, s, p - 1);
		return (first || second);
	}
}

bool isMatch(string &str, string &ptr) {
	int s = str.length();
	int p = ptr.length();
	return checkMatch(str, ptr, s, p);
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
		cout<<isMatch(str, ptr)<<endl;
	}
	return 0;
}