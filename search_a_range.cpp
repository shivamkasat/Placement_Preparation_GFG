#include <bits/stdc++.h>
using namespace std;

int findFirstIndex(vector < int > &nums, int item) {
  int low = 0;
  int n = nums.size();
  int high = n - 1;
  int result = -1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (item <= nums[mid]) {
      if (item == nums[mid]) {
        result = mid;
      }
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result;

}

int findLastIndex(vector < int > &nums, int item) {
  int low = 0;
  int n = nums.size();
  int high = n - 1;
  int result = -1;
  int mid = 0;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (item >= nums[mid]) {
      if (item == nums[mid]) {
        result = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result;
}


vector < int > findSolution(vector < int > &nums, int item) {
  vector < int > result;
  int firstIndex = findFirstIndex(nums, item);
  int lastIndex = findLastIndex(nums, item);

  result.push_back(firstIndex);
  result.push_back(lastIndex);

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
    vector < int > result = findSolution(nums, item);
    cout<<result[0]<<" "<<result[1]<<endl;
  }
  return 0;
}
