#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &s, int i, int j) {
  if (i > j) {
    return true;
  }

  if (s[i] != s[j]) {
    return false;
  }

  return isPalin(s, i + 1, j - 1);
}


void makePartitions(string &s, vector < vector < string > > &result, vector < string > &path, int index) {
  if (index == s.length()) {
    result.push_back(path);
    return;
  }

  for (int i = index; i < s.length(); i++) {
    if (isPalin(s,index, i)) {
      // cout<<"substring form i = "<<index<<" j = "<<i<<" is palindrome"<<endl;
      path.push_back(s.substr(index, i - index + 1));
      makePartitions(s, result, path, i + 1);
      path.pop_back();
    }
  }

}

vector < vector < string > > findPalindromicPartitioning(string &s) {
  vector < vector < string > > result;
  vector < string > path;
  int index = 0;
  makePartitions(s, result, path, index);
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    vector < vector < string > > result;
    result = findPalindromicPartitioning(s);
    cout<<"printing result"<<endl;
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
