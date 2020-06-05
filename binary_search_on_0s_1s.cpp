#include <bits/stdc++.h>
using namespace std;

int findIndexFirstOne(vector < int > &nums) {
  int low = 0;
  int high = nums.size() - 1;
  int mid = 0;
  int ans = -1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (nums[mid] == 1) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int findLastIndexZero(vector < int > &nums) {
  int low = 0;
  int high = nums.size() - 1;
  int ans = -1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] == 0) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

int main () {
  vector < int > nums = {0, 0, 0, 0, 0, 1, 1, 1};
  cout<<findIndexFirstOne(nums);
  cout<<findLastIndexZero(nums);
  return 0;
}
