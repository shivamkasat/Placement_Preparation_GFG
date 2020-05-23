#include <bits/stdc++.h>
using namespace std;

int palinLength(string &s1, int n1, int n2, vector < vector < int > > &dp) {
  if (n1 > n2) {
    return 0;
  } else if (n1 == n2) {
    return 1;
  }

  if (dp[n1][n2] != -1) {
    return dp[n1][n2];
  }

  if (s1[n1] == s1[n2]) {
    dp[n1][n2] = palinLength(s1, n1 + 1, n2 - 1, dp) + 2;
    return dp[n1][n2];
  } else {
    dp[n1][n2] =  max(palinLength(s1, n1 + 1, n2, dp), palinLength(s1, n1, n2 - 1, dp));
    return dp[n1][n2];
  }
}

int longestPalin(string &s1) {
  int n1 = 0;
  int n2 = s1.size() - 1;
  vector < vector < int > >dp(n2 + 1, vector < int >(n2 + 1, -1));
  int len = palinLength(s1, n1, n2, dp);
  return len;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    cin>>s1;
    cout<<longestPalin(s1);
  }

  return 0;
}
