//minimum cuts to make all partition palindromic
#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &s, int i, int j) {
  if (i >= j) {
    return true;
  }

  if (s[i] != s[j]) {
    return false;
  }

  return isPalin(s, i + 1, j - 1);
}

int minCuts(string &s, int i, int j, vector < vector < int > > &dp) {
  // cout<<"HI i = "<<i<<" j = "<<j<<endl;
  if (i >= j) {
    return 0;
  } else if (isPalin(s,i,j)) {
    return 0;
  }

  if (dp[i][j] != INT_MAX) {
    return dp[i][j];
  }

  // int minimumCuts = INT_MAX;
  int tempCuts = INT_MAX;
  int left = INT_MAX;
  int right = INT_MAX;
  for (int k = i; k < j; k++) {
    if (dp[i][k] != INT_MAX) {
      left = dp[i][k];
    } else {
      left = minCuts(s, i, k, dp);
      dp[i][k] = left;
    }

    if (dp[k + 1][j] != INT_MAX) {
      right = dp[k + 1][j];
    } else {
      right = minCuts(s, k + 1, j, dp);
      dp[k + 1][j] = right;
    }

    tempCuts = left + right + 1;
    dp[i][j] = min(dp[i][j], tempCuts);
  }

  return dp[i][j];
}

int findMinCuts(string &s) {
  int i = 0;
  int j = s.size() - 1;
  vector < vector < int > >dp(s.length() + 1, vector < int >(s.length() + 1, INT_MAX));
  return minCuts(s, i, j, dp);
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    cout<<findMinCuts(s)<<endl;
  }
  return 0;
}
