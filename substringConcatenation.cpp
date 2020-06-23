#include <bits/stdc++.h>
using namespace std;
// better solution is to use rabin karp -> create a hash out of the w
vector < int > checkSent(string sentence, vector < string > &words) {
  unordered_map < string , int > hmap;
  for (int i = 0; i < words.size(); i++) {
    hmap[words[i]]++;
  }

  vector < int > result;
  unordered_map < string , int > tempHash;
  int n = sentence.length();
  int i = 0;
  int j = 0;
  int len = words[0].length();
  string temp = "";
  while (i < n) {
    tempHash = hmap;
    while (j < n) {
      temp = sentence.substr(j, len);
      if (tempHash.find(temp) != tempHash.end()) {
        tempHash[temp]--;
        if (tempHash[temp] == 0) {
          tempHash.erase(temp);
        }
      } else {
        break;
      }
      j += len;
      if (tempHash.empty() == true) {
        break;
      }
    }

    if (tempHash.empty() == true) {
      result.push_back(i);
      i = j;
    } else {
      i = i + 1;
    }
  }

  return result;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < string > words;
    string word;
    for (int i = 0; i < n; i++) {
      cin>>word;
      words.push_back(word);
    }

    string sentence;
    cin>>sentence;

    vector < int > result;
    result = checkSent(sentence, words);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<endl;
    }

  }
  return 0;
}

vector Solution::findSubstring(string s,
  const vector & a) {
  vector res;
  int n = s.size();
  int l = (a.size()) * (a[0].size());
  int w = a[0].size();
  unordered_map < string, int > m, temp;
  for (auto it: a)
    m[it]++;
  for (int i = 0; i < n - l + 1; i++) {
    for (int j = i; j < i + l; j += w) {
      string x = s.substr(j, w);
      temp[x]++;
    }
    if (m == temp) {
      res.push_back(i);
    }
    temp.clear();
  }
  return res;
}
