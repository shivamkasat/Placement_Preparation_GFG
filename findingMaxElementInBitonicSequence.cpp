#include <bits/stdc++.h>
using namespace std;

int findMaxElemIndex(vector < int > &nums) {
  int low = 1;
  int n = nums.size();
  int high = n - 2;
  int mid = 0;
  int ans = -1;



  while (low <= high) {
    mid = low + (high - low) / 2;
    if (nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1]) {
      ans = mid;
      break;
    } else if (nums[mid + 1] > nums[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  if (ans != -1) {
    return ans;
  }

  if (nums[0] > nums[1]) {
    return 0;
  } else if (nums[n - 1] > nums[n - 2]) {
    return n - 1;
  }

  return 0;
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
    cout<<findMaxElemIndex(nums);
  }
  return 0;
}
