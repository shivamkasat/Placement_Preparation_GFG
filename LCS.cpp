#include <bits/stdc++.h>
using namespace std;

void getLCS(string &s1, string &s2, int n1, int n2, vector <vector < int > > &dp, string &result, string &path) {
  if (n1 == 0 || n2 == 0) {
    result = path;
    return;
  }

  if (s1[n1- 1] == s2[n2 - 1]) {
    path.push_back(s1[n1 - 1]);
    getLCS(s1, s2, n1 - 1, n2 - 1, dp, result, path);
  } else {
    if (dp[n1 - 1][n2] > dp[n1][n2 - 1]) {
      getLCS(s1, s2, n1 - 1, n2, dp, result, path);
    } else {
      getLCS(s1, s2, n1, n2 - 1, dp, result, path);
    }
  }
}

int findLCS(string &s1, string &s2, int n1, int n2, vector < vector < int > > &dp) {
  if (n1 == 0 || n2 == 0) {
    return 0;
  }

  if (dp[n1][n2] != -1) {
    return dp[n1][n2];
  }

  if (s1[n1 - 1] == s2[n2 - 1]) {
    dp[n1][n2] = findLCS(s1, s2, n1 - 1, n2 - 1, dp) + 1;
    return dp[n1][n2];
  }

  dp[n1][n2] = max(findLCS(s1, s2, n1 - 1, n2, dp), findLCS(s1, s2, n1, n2 - 1, dp));
  return dp[n1][n2];
}

int LCS(string &s1, string &s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
  string path = "";
  string result = "";
  int lengthLCS = findLCS(s1, s2, n1, n2, dp);
  getLCS(s1, s2, n1, n2, dp, result, path);
  reverse(result.begin(), result.end());
  cout<<"longest common subsequence is "<<result<<endl;
  return lengthLCS;
}

int LCSItr(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();

  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));

  for (int i = 0; i < n1 + 1; i++) {
    for (int j = 0; j < n2 + 1; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }

      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string result = "";
  string path = "";

  getLCS(s1, s2, n1, n2, dp, result, path);
  reverse(result.begin(), result.end());
  cout<<"from iterative longest common subsequence is "<<result<<endl;

  return dp[n1][n2];

}



int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<LCS(s1, s2)<<endl;
    cout<<"iterative one"<<endl;
    cout<<LCSItr(s1, s2);
  }
  return 0;
}
