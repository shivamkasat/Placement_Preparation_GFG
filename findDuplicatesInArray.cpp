#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector < int > &nums) {
  int duplicate = -1;
  int temp = nums[0];
  int index = nums[0];
  while (1) {
    index = nums[0];
    if (nums[index] == index) {
      return index;
    }

    temp = nums[index];
    nums[index] = index;
    nums[0] = temp;
  }
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

    cout<<findDuplicate(nums)<<endl;
  }
  return 0;
}
