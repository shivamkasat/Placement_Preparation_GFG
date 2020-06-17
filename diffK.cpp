#include <bits/stdc++.h>
using namespace std;

bool findK(vector < int > &nums, int k) {
  int i = 0;
  int j = 1;
  int n = nums.size();
  int diff = 0;
  while (j < n) {
    while (j + 1 < n && (nums[j] - nums[i]) < k) {
      j++;
    }

    while (i + 1 < j && (nums[j] - nums[i]) > k) {
      i++;
    }

    if (j < n && nums[j] - nums[i] == k) {
      return true;
    } else {
      j++;
    }
  }

  return false;
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
    int k;
    cin>>k;
    cout<<findK(nums, k)<<endl;
  }
  return 0;
}
