#include <bits/stdc++.h>
using namespace std;

void waveArray(vector < int > &nums) {
  if (nums.size() < 2) {
    return;
  }
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int temp;
  for (int i = 1; i < n; i += 2) {
    temp = nums[i - 1];
    nums[i - 1] = nums[i];
    nums[i] = temp;
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

    waveArray(nums);

    for (int i = 0; i < n; i++) {
      cout<<nums[i]<<" ";
    }

    cout<<endl;

  }
  return 0;
}
