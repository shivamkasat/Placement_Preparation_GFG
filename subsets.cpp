#include <bits/stdc++.h>
using namespace std;

void subsets(vector < int > &nums, vector < vector < int > > &result, vector < int > &path, int index) {
  if (index == nums.size()) {
    result.push_back(path);
    return;
  }

  // choose the element
  path.push_back(nums[index]);
  subsets(nums, result, path, index + 1);
  path.pop_back();

  //do not choose the element;
  subsets(nums, result, path, index + 1);

}

vector < vector < int > > makeSubsets(vector < int > &nums) {
  vector < vector < int > > result;
  vector < int > path;
  int index = 0;
  subsets(nums, result, path, index);
  return result;
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
    vector < vector < int > > result;
    result = makeSubsets(nums);
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
