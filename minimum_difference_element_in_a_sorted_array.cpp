#include <bits/stdc++.h>
using namespace std;

int minDiffElem(vector < int > &nums, int item) {
  int elem;
  int diff = INT_MAX;
  int low = 0;
  int n = nums.size();
  int high = n - 1;
  int mid = 0;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (abs(item - nums[mid]) < diff) {
      diff = abs(item - nums[mid]);
      elem = nums[mid];
    }

    if (mid + 1 <= high && abs(nums[mid + 1] - item) <= diff) {
      low = mid + 1;
    } else if (mid - 1 >= low && abs(nums[mid - 1] - item <= diff)) {
      high = mid - 1;
    } else {
      break;
    }
  }

  return elem;

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

    cout<<minDiffElem(nums, item);
  }
  return 0;
}
