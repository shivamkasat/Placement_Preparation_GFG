#include <bits/stdc++.h>
using namespace std;

int findFloor(vector < int > &nums, int item) {
  int low = 0;
  int high = nums.size() - 1;
  int ans = -1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (nums[mid] <= item) {
      ans = nums[mid];
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
    vector < int > nums;
    int num;
    // cin>>num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }
    int item;
    cin>>item;

    cout<<findFloor(nums, item)<<endl;

  }
  return 0;
}
