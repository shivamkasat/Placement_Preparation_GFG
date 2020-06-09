#include <bits/stdc++.h>
using namespace std;

void arrange(vector < int > &nums, int i, int &prev, int &start) {
  if (i == start) {
    prev = -1 * nums[i];
    return;
  }

  arrange(nums, nums[i], prev, start);
  int temp = nums[i];
  nums[i] = prev;
  prev = -1 * temp;
}

void rearrange(vector < int > &nums) {
  int n = nums.size();
  int i = 0;
  while (i < n) {
    if (nums[i] > 0) {
      int prev = -1;
      int start = i;

      arrange(nums, nums[i], prev, start);
      nums[i] = prev;
    }
    i++;
  }
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
    rearrange(nums);
    for (int i = 0; i < nums.size(); i++) {
      cout<<nums[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
