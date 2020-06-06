#include <bits/stdc++.h>
using namespace std;

int findPeakElementIndex(vector < int > &nums) {
  if (nums[0] > nums[1]) {
    return 0;
  } else if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
    return nums.size() - 1;
  }

  int low = 1;
  int n = nums.size();
  int high = n - 2;
  int mid = 0;
  int ans = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid + 1] < nums[mid] && nums[mid - 1] < nums[mid]) {
      ans = mid;
      break;
    } else if (nums[mid + 1] > nums[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }


  }

  return ans;

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

    cout<<findPeakElementIndex(nums)<<endl;

  }
  return 0;
}
