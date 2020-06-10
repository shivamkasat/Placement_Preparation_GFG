#include <bits/stdc++.h>
using namespace std;

string findPrefix(string s1, string s2) {
  string prefix = "";
  int len = min(s1.length(), s2.length());
  for (int i = 0; i < len; i++) {
    if (s1[i] == s2[i]) {
      prefix.push_back(s1[i]);
    } else {
      break;
    }
  }
  return prefix;
}

string longestPrefix(vector < string > &strs) {
  int n = strs.size();
  if (n == 1) {
    return strs[0];
  }
  string prefix = "";
  prefix = findPrefix(strs[0], strs[1]);

  for (int i = 2; i < n; i++) {
    prefix = findPrefix(prefix, strs[i]);
  }
  return prefix;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < string > strs(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>strs[i];
    }
    cout<<longestPrefix(strs)<<endl;
  }
  return 0;
}
