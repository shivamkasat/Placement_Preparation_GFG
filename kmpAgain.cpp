#include <bits/stdc++.h>
using namespace std;

int findFirstIndex(string s, string p) {
  int n = s.length();
  int m = p.length();
  //creating lps table => longest prefix suffix table
  //length of the longest suffix which is also a prefix
  // or it tells us which index to check if there is a mismatch
  int i = 0;
  int j = 1;
  vector < int > lps(m, 0);
  lps[i] = 0;
  while (j < m) {
    if (p[i] == p[j]) {
      lps[j] = i + 1;
      i++;
      j++;
    }

    if (i != 0 && p[i] != p[j]) {
      lps[j] = 0;
      j++;
    } else if (p[i] != p[j]) {
      i = lps[i - 1];
    }
  }

  for (int i = 0 ; i < m; i++) {
    cout<<lps[i]<<" ";
  }
  cout<<endl;

  i = 0;
  j = 0;

  // cout<<"string s = "<<s<<"string p = "<<p<<endl;

  while(i < n) {
    // cout<<"starting matching from i = "<<i<<" j = "<<j<<endl;
    while (i < n && j < m && s[i] == p[j]) {
      i++;
      j++;
    }

    if (j == m) {
      cout<<"j == m reached"<<endl;
      return i - m;
    }

    if (i == n) {
      cout<<"i == n reached"<<endl;
      return -1;
    }

    if (j != 0) {
      j = lps[j - 1];
    } else {
      i++;
    }
  }
  return -1;
}

int main() {
  int test;
  cin>>test;
  while(test--) {
    string s;
    string p;
    cin>>s;
    cin>>p;
    cout<<findFirstIndex(s, p)<<endl;
  }
  return 0;
}
