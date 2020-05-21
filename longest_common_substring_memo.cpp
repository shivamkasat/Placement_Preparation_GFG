#include<bits/stdc++.h>
using namespace std;

int findlcs(string s1, string s2, int n1, int n2, vector < vector < int > > &dp) {
  if (n1 == 0 || n2 == 0) {
    return 0;
  }

  if (dp[n1][n2] != -1) {
    return dp[n1][n2];
  }

  if (s1[n1 - 1] == s2[n2 - 2]) {
    dp[n1][n2] = findlcs(s1, s2, n1 - 1, n2 - 1, dp) + 1;
    return dp[n1][n2];
  } else {
    findlcs(s1, s2, n1 - 1, n2, dp);
    findlcs(s1, s2, n1, n2 - 1, dp);
    dp[n1][n2] = 0;
    return dp[n1][n2];
  }
}


int lcs(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();

  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
  findlcs(s1, s2, n1, n2, dp);
  for (int i = 0; i < n1 + 1; i++) {
    for (int j = 0; j < n2 + 1; j++) {
      printf("%3d",dp[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<lcs(s1, s2)<<endl;
  }
  return 0;
}
