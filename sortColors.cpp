#include <bits/stdc++.h>
using namespace std;

void sortColors(vector < int > &nums) {
  int n = nums.size();
  int i = 0;
  int j = n - 1;
  int k = 0;

  while (k <= j) {
    while (i < j && nums[i] == 0) {
      i++;
    }

    while (j >= i && nums[j] == 2) {
      j--;
    }

    if (nums[k] == 0) {
      if (i < k) {
        swap(nums[i], nums[k]);
      } else {
        k++;
      }
    } else if (nums[k] == 2) {
      if (k < j) {
        swap(nums[k], nums[j]);
      }
    } else {
      k++;
    }

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

    sortColors(nums);
    for (int i = 0; i < n; i++) {
      cout<<nums[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
