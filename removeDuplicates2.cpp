#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector < int > &nums) {
  int n = nums.size();
  if (n < 3) {
    return n;
  }

  int i = 0;
  int j = 2;
  int k = 2;
  int index = 0;
  int item = 0;

  while (j < n) {
    if (nums[i] != nums[j]) {
      if (k != 2) {
        nums[index] = item;
      }
      index = k;
      item = nums[j];
      k++;
    }
    i++;
    j++;
  }

  if (k != 2) {
    nums[index] = item;
  }

  return k;

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

    int k = removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
      cout<<nums[i];
    }
    cout<<endl;


  }
}
