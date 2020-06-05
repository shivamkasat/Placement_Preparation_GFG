#include <bits/stdc++.h>
using namespace std;

int findIndex(vector < int > &nums, int item) {

  if (nums.size() == 0) {
    return -1;
  } else if (nums.size() == 1) {
    if (nums[0] != item) {
      return -1;
    } else {
      return 0;
    }
  }


  int low = 0;
  int n = nums.size();
  int high = n - 1;
  int index = -1;
  int mid = 0;

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] < nums[(mid + 1) % n] && nums[mid] < nums[(mid + n - 1) % n]) {
      index = mid;
      break;
    } else if (nums[mid] < nums[high]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout<<"index of the lowest element"<<index<<endl;


  if (item >= nums[index] && item <= nums[n - 1]) {
    low = index;
    high = n - 1;
  } else {
    low = 0;
    high = index - 1;
  }

  int itemIndex = -1;
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] == item) {
      itemIndex = mid;
      break;
    } else if (item > nums[mid]) {
      low = mid + 1;
    } else {
      high = mid -1;
    }
  }

  return itemIndex;
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

    int item;
    cin>>item;

    cout<<findIndex(nums, item)<<endl;
  }
  return 0;
}
