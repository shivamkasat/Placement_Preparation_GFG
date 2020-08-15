#include <bits/stdc++.h>
using namespace std;

string generateResult(string &str, string &ptr) {
	vector < int >charCount(26, 0);
	for (auto x : str) {
		charCount[x - 'a']++;
	}

	int firstChar = ptr[0] - 'a';
	char c = ptr[0];
	bool smallerThanFirst = false;
	for (auto x : ptr) {
		charCount[x - 'a']--;
	}

	for (auto x : ptr) {
		if (x < c) {
			smallerThanFirst = true;
			break;
		} else if (x > c) {
			break;
		}
	}

	string result = "";

	for (int i = 0; i < firstChar; i++) {
		for (int j = 0; j < charCount[i]; j++) {
			result.push_back('a' + i);
		}
	}

	if (smallerThanFirst == false) {
		for (int i = 0; i < charCount[firstChar]; i++) {
			result.push_back(firstChar + 'a');
		}
	}

	result = result + ptr;

	if (smallerThanFirst) {
		for (int i = 0; i < charCount[firstChar]; i++) {
			result.push_back(firstChar + 'a');
		}	
	}

	for (int i = firstChar + 1; i < 26; i++) {
		for (int j = 0; j < charCount[i]; j++) {
			result.push_back('a' + i);
		}
	}

	return result;


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
		cout<<generateResult(str, ptr)<<endl;
	}
	return 0;
}

