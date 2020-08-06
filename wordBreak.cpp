#include <bits/stdc++.h>
using namespace std;

bool checkBreak(string word, unordered_set < string > &dict, int startIndex) {
	if (startIndex == word.length()) {
		return true;
	}

	bool ans = false;
	for (int i = startIndex; i < word.size(); i++) {
		if (dict.find(word.substr(startIndex, i - startIndex + 1)) != dict.end()) {
			ans = ans || checkBreak(word, dict, i + 1);
		}
	}

	return ans;
}

bool wordBreak(string s, vector < string > &wordDict) {
	unordered_set < string >dict(wordDict.begin(), wordDict.end());
	return checkBreak(s, dict, 0);
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		string word;
		cin>>word;
		int dictSize;
		cin>>dictSize;
		vector < string > dict;
		string dictWord;
		for (int i = 0; i < dictSize; i++) {
			cin>>dictWord;
			dict.push_back(dictWord);
		}
		cout<<wordBreak(word, dict);
	}
	return 0;
}