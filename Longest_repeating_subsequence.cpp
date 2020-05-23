#include <bits/stdc++.h>
using namespace std;

int findRepeat(string s1, int n1, int n2, vector < vector < int > > &dp) {
  if (n1 == 0 || n2 == 0)
  {
    return 0;
  }

  if (dp[n1][n2] != -1) {
    return dp[n1][n2];
  }

  if (s1[n1 - 1] == s1[n2 - 1] && n1 != n2) {
    dp[n1][n2] =  findRepeat(s1, n1 - 1, n2 - 1, dp) + 1;
    return dp[n1][n2];
  } else {
    dp[n1][n2] = max(findRepeat(s1, n1 - 1, n2, dp), findRepeat(s1,n1, n2 -1, dp));
    return dp[n1][n2];
  }
}

int longestReapet(string s1) {
  if (s1.length() < 2) {
    return 0;
  }
  int n1 = s1.length() - 1;
  int n2 = s1.length() - 1;
  vector <vector < int > > dp(s1.length() + 1, vector < int >(s1.length() + 1, -1));
  return findRepeat(s1, n1 + 1, n2 + 1, dp);
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    cin>>s1;
    cout<<longestReapet(s1)<<endl;
  }
  return 0;
}
