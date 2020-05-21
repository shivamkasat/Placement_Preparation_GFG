#include <bits/stdc++.h>
using namespace std;
void printscs(string &s1, string &s2, int n1, int n2, vector < vector < int > > &dp, string &path) {
  if (n1 == 0 && n2 == 0) {
    return;
  } else if (n1 == 0) {

    string sub= s2.substr(0, n2);
    reverse(sub.begin(), sub.end());
    path += sub;
    return;
  } else if (n2 == 0) {
    string sub = s1.substr(0, n1);
    reverse(sub.begin(), sub.end());
    path += sub;
    return;
  }

  if (s1[n1 - 1] == s2[n2 - 1]) {
    path.push_back(s1[n1 - 1]);
    printscs(s1, s2, n1 - 1, n2 - 1, dp, path);
  } else {
    if (dp[n1 - 1][n2] < dp[n1][n2 - 1]) {
      path.push_back(s1[n1 - 1]);
      printscs(s1, s2, n1 - 1, n2, dp, path);
    } else {
      path.push_back(s2[n2 - 1]);
      printscs(s1, s2, n1, n2 - 1, dp, path);
    }
  }
}

int scs(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();

  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));

  for (int i = 0; i < n1 + 1; i++) {
    dp[i][0] = i;
  }

  for (int j = 0; j < n2 + 1; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i < n1 + 1; i++) {
    for (int j = 1; j < n2 + 1; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      }
    }
  }

  for (int i = 0; i < n1 + 1; i++) {
    for (int j = 0; j < n2 + 1; j++) {
      printf("%3d", dp[i][j]);
    }
    printf("\n");
  }

  string path = "";
  printscs(s1, s2, n1, n2, dp, path);
  cout<<path<<" is the scs"<<endl;
  return dp[n1][n2];

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<scs(s1, s2)<<endl;
  }
  return 0;
}
