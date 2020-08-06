#include <bits/stdc++.h>
using namespace std;

vector < string > checkBreak(string &word, unordered_set < string > hset, int startIndex, unordered_map < int, vector < string > > &dp) {
	vector < string > result;
	if (startIndex == word.length()) {
	     result.push_back("");
		return result;
	}

	if (dp.find(startIndex) != dp.end()) {
		return dp[startIndex];
	}

	string newWord = "";
	for (int i = startIndex; i < word.length(); i++) {
		newWord.push_back(word[i]);
		vector < string > suffix;
		if (hset.find(newWord) != hset.end()) {
			suffix = checkBreak(word, hset, i + 1);
			for (auto x : suffix) {
				result.push_back(newWord + (x.empty() == true ? "" : "_") + x);
			}
		}
	}

	dp[startIndex] = result;
	return result;
}

vector < string > wordBreak(string word, vector < string > &dict) {
	unordered_set < string > hset(dict.begin(), dict.end());
	unordered_map < int, vector < string > > dp;
	return checkBreak(word, hset, 0, dp);
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		string word;
		cin>>word;
		int count;
		cin>>count;
		vector < string > dict;
		string dictWord;
		for (int i = 0; i < count; i++) {
			cin>>dictWord;
			dict.push_back(dictWord);
		}
		vector < string > result = wordBreak(word, dict);
		for (auto x : result) {
		     cout<<x<<endl;
		}

	}
	return 0;
}