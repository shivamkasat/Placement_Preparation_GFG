#include <bits/stdc++.h>
using namespace std;

int firstOccurance(vector < int > &nums, int item) {
  int low = 0;
  int high = nums.size() - 1;
  int mid = 0;
  int ans = -1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (nums[mid] == item) {
      ans = mid;
    }

    if (item <= nums[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int lastOccurance(vector < int > &nums, int item) {
  int low = 0;
  int high = nums.size() - 1;
  int mid = 0;
  int ans = -1;

  while (low <= high) {
    int mid = low + (high - low ) / 2;
    if (nums[mid] == item) {
      ans = mid;
    }

    if (item >= mid[nums]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }

  }

  return ans;
}

int main() {
  vector < int > nums = {2, 4, 8, 10, 10, 10, 18, 20};
  cout<<firstOccurance(nums, 10)<<endl;
  cout<<lastOccurance(nums, 10)<<endl;
  return 0;
}
