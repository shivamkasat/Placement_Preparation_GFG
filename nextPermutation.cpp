#include <bits/stdc++.h>
using namespace std;

void findNextPerm(vector < int > &nums) {
  // find the first index which is not increasing
  int n = nums.size();
  int i = n - 2;
  while (i >= 0) {
    if (nums[i] < nums[i + 1]) {
      break;
    }
    i--;
  }

  if (i == -1) {
    sort(nums.begin(), nums.end());
    return;
  }

  int temp;
  for (int j = n - 1; j > i; j--) {
    if (nums[j] > nums[i]) {
      temp = nums[j];
      nums[j] = nums[i];
      nums[i] = temp;
      break;
    }
  }
  sort(nums.begin() + i + 1, nums.end());
  return;

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


    findNextPerm(nums);
    for (int i = 0; i < nums.size(); i++) {
      cout<<nums[i]<<" ";
    }
    cout<<endl;

  }
  return 0;
}
