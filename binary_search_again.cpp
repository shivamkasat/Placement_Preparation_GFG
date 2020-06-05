#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector < int > &nums, int low, int high, int item) {
  if (low > high) {
    return -1;
  }

  int mid = low + (high - low) / 2;
  if (nums[mid] == item) {
    return mid;
  }

  if (item > nums[mid]) {
    return binarySearch(nums, mid + 1, high, item);
  } else {
    return binarySearch(nums, low, mid - 1, item);
  }

}

int itrBinarySearch(vector < int > &nums, int item) {
  int low = 0;
  int high = nums.size() - 1;
  int ans = -1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (nums[mid] == item) {
      ans = mid;
      break;
    } else if (item > nums[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}



int main() {
  int n;
  cin>>n;
  vector < int > nums;
  int num;
  for (int i = 0; i < n; i++) {
    cin>>num;
    nums.push_back(num);
  }
  int items;
  cin>>items;
  int item;
  for (int i = 0; i < items; i++) {
    cin>>item;
    // cout<<binarySearch(nums, 0, n - 1, item)<<endl;
    cout<<itrBinarySearch(nums, item)<<endl;
  }
  return 0;
}
