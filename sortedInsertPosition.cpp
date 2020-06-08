#include <bits/stdc++.h>
using namespace std;

int findIndex(vector < int > &nums, int item) {
  int n = nums.size();
  if (item < nums[0]) {
    return 0;
  }else if (item > nums[n - 1]) {
    return n;
  }

  int low = 0;
  int high = n - 1;
  int mid  = 0;
  int result = 0;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (item > nums[mid]) {
      low = mid + 1;
    } else {
      result = mid;
      high = mid - 1;
    }
  }

  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums;
    int num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }
    int item;
    cin>>item;
    cout<<findIndex(nums, item)<<endl;
  }
  return 0;
}
