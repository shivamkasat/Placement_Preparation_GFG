#include <bits/stdc++.h>
using namespace std;

int check(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector < vector < int > > &dp) {
  if (n1 == 0 && n2 == 0 && n3 == 0) {
    return true;
  }

  if (dp[n1][n2] != -1) {
      return dp[n1][n2];
  }

  int first = 0;
  int second = 0;

  if (n1 > 0 && s1[n1 - 1] == s3[n3 - 1]) {
    first = check(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
  }

  if (n2 > 0 && s2[n2 - 1] == s3[n3 - 1]) {
    second = check(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
  }

  dp[n1][n2] = first == 1 || second == 1 ? 1 : 0;
  return dp[n1][n2];
}
bool isInterleave(string &s1, string &s2, string &s3) {
  int n1 = s1.length();
  int n2 = s2.length();
  int n3 = s3.length();
  if (n1 + n2 != n3) {
   return false;
  }
   vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
   int res = check(s1, s2, s3, n1, n2, n3, dp);
   return res == 1;
  return check(s1, s2, s3, n1, n2, n3);
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    string s3;
    cin>>s3;
    cout<<isInterleave(s1, s2, s3)<<endl;
  }
  return 0;
}
