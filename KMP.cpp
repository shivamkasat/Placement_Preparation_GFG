#include <bits/stdc++.h>
using namespace std;

int findFirstIndex(string s, string p) {
  int n = s.length();
  int m = p.length();

  if (n == 0 && m != 0) {
    return -1;
  } else if (n != 0 && m == 0) {
    return 0;
  } else if (n == 0 && m == 0) {
    return 0;
  }

  vector < int > lps(m, 0);
  lps[0] = 0;
  int i = 0;
  int j = 1;
  while (j < m) {
    if (p[i] == p[j]) {
      lps[j] = i + 1;
      i++;
      j++;
    } else if (i == 0 && p[i] != p[j]) {
      lps[j] = 0;
      j++;
    } else {
      i = lps[i - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    cout<<lps[i]<<" ";
  }
  cout<<endl;

  i = 0;
  j = 0;
  while (i < n) {
    while (i < n && j < m && s[i] == p[j]) {
      i++;
      j++;
    }

    if (j == m) {
      // cout<<"i = "<<i<<"m = "<<m<<endl;
      return (i - m);
    }

    if (i == n) {
      return -1;
    }

    if (j != 0) {
      j = lps[j - 1];
    } else {
      i++;
    }


  return -1;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    string p;
    cin>>s>>p;
    cout<<findFirstIndex(s, p)<<endl;
  }
  return 0;
}
