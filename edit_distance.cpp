#include <bits/stdc++.h>
using namespace std;

int findDistance(string &s1, string &s2, int n1, int n2, vector < vector < int > > &dp) {
  if (n1 == 0) {
    return n2;
  } else if (n2 == 0){
    return n1;
  }

  if (dp[n1][n2] != -1) {
    return dp[n1][n2];
  }

  if (s1[n1 - 1] == s2[n2 - 1]) {
    dp[n1][n2] = findDistance(s1, s2, n1 - 1, n2 - 1, dp);
  } else {
    int rep = findDistance(s1, s2, n1 - 1, n2 - 1, dp);
    int ins = findDistance(s1, s2, n1, n2 - 1, dp);
    int del = findDistance(s1, s2, n1 - 1, n2, dp);
    dp[n1][n2] = min(rep, min(ins, del)) + 1;
  }

  return dp[n1][n2];
}

int findEditDistance(string &s1, string &s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
  return findDistance(s1, s2, n1, n2, dp);
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<findEditDistance(s1, s2)<<endl;
  }
  return 0;
}
