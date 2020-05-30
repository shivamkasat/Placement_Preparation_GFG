#include <bits/stdc++.h>
using namespace std;

void merge(vector < int > &nums, int low, int mid, int high, long long &count) {
  vector < int > temp(high - low + 1, 0);
  int i = low;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= high) {
    if (nums[i] > nums[j]) {
      count += (mid - i + 1);
      temp[k] = nums[j];
      j++;
      k++;
    } else {
      temp[k] = nums[i];
      i++;
      k++;
    }
  }

  while (i <= mid) {
    temp[k] = nums[i];
    i++;
    k++;
  }

  while (j <= high) {
    temp[k] = nums[j];
    j++;
    k++;
  }

  for (int i = low, k = 0; i <= high; i++, k++) {
    nums[i] = temp[k];
  }

}

void findInversionCount(vector < int > &nums, int low, int high, long long &count) {
  if (low >= high) {
    return;
  }

  int mid = low + (high - low) / 2;

  findInversionCount(nums, low, mid, count);
  findInversionCount(nums, mid + 1, high, count);
  merge(nums, low, mid, high, count);
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

    int count = 0;
    findInversionCount(nums, 0, n - 1, count);
    cout<<count<<endl;
    // for (int i = 0; i < n; i++) {
    //   cout<<nums[i]<<" ";
    // }
  }
  return 0;
}
