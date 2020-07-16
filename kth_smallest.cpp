#include <bits/stdc++.h>
using namespace std;
// for submission in gfg you got to make it randomized partition.
int partition(vector < int > &nums, int low, int high) {
  cout<<"low = "<<low<<"high = "<<high<<endl;
  if (low == high) {
    return low;
  }
  swap(nums[low], nums[high]);
  int pivotElem = nums[high];
  int i = low;
  int j = high - 1;
  while (i <= j) {
    cout<<"stuck here"<<endl;
    while (i <= j && nums[i] <= pivotElem) {
      i++;
    }
    while (i <= j && nums[j] >= pivotElem) {
      j--;
    }
    if (i <= j) {
      swap(nums[i], nums[j]);
    }
  }
  cout<<"at the end i = "<<i<<endl;
  swap(nums[i], nums[high]);
  return i;
}

int findKthSmallest(vector < int > &nums, int k) {
  int low = 0;
  int high = nums.size() - 1;
  while (low <= high) {
    int pivotIndex = partition(nums, low, high);
    cout<<"pivotIndex = "<<pivotIndex<<endl;
    if (pivotIndex + 1 == k) {
      return nums[pivotIndex];
    } else if (k < pivotIndex + 1) {
      high = pivotIndex - 1;
    } else {
      low = pivotIndex + 1;
    }
  }
  return -1;
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
    int k;
    cin>>k;
    cout<<findKthSmallest(nums, k)<<endl;
  }
  return 0;
}
