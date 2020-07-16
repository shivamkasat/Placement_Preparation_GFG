#include <bits/stdc++.h>
using namespace std;

int calcCost(vector < int > &nums, int i, int j, vector < vector < int > > &dp) {
  if (i >= j) {
    return 0;
  }

  if (dp[i][j] != INT_MAX) {
    return dp[i][j];
  }

  // int minCost = INT_MAX;
  int tempAns = INT_MAX;
  for (int k = i; k < j; k++) {
    tempAns = calcCost(nums, i, k, dp) + calcCost(nums, k + 1, j, dp) + nums[i - 1] * nums[k] * nums[j];
    dp[i][j] = min(dp[i][j], tempAns);
  }

  return dp[i][j];
}

int findMinCost(vector < int > &nums) {
  int i = 1;
  int j = nums.size() - 1;
  vector < vector < int > > dp(nums.size() + 1, vector < int >(nums.size() + 1, INT_MAX));
  return calcCost(nums, i, j, dp);
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }

    cout<<findMinCost(nums);
  }
  return 0;
}
