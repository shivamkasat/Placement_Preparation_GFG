#include <bits/stdc++.h>
using namespace std;

void makePermutations(vector < int > &nums, vector < vector < int > > &result, int index) {
  if (index == nums.size()) {
    result.push_back(nums);
    return;
  }

  for (int i = index; i < nums.size(); i++) {
    swap(nums[i], nums[index]);
    makePermutations(nums, result, index + 1);
    swap(nums[i], nums[index]);
  }

}

vector < vector < int > > findPermutations(vector < int > &nums) {
  vector < vector < int > > result;
  int index = 0;
  makePermutations(nums, result, index);
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
    vector < vector < int > > result;
    result = findPermutations(nums);
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
