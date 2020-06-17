#include <bits/stdc++.h>
using namespace std;

int removeElement(vector < int > &nums, int elem) {
  int n = nums.size();
  int i = 0;
  int j = 0;

  while (i < n && j < n) {
    while (i < n && nums[i] != elem) {
      i++;
    }

    while (j < n && nums[j] == elem) {
      j++;
    }

    if (i < n && j < n) {
      if (i < j){
        swap(nums[i], nums[j]);
      }
      else {
        j = i + 1;
      }
    }

  }

  i = 0;
  while (i < n && nums[i] != elem) {
    i++;
  }

  return i;


}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++ ) {
      cin>>nums[i];
    }

    int elem;
    cin>>elem;

    int k = removeElement(nums, elem);
    for (int i = 0; i < k; i++) {
      cout<<nums[i];
    }
    // cout<<"end"<<endl;
  }
  return 0;
}
