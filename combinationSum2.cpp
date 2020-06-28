#include <bits/stdc++.h>
using namespace std;

void combs(vector < int > &nums, int target, vector < vector < int > > &result, vector < int > &path, int sum, int index) {
  if (sum == target) {
    result.push_back(path);
    return;
  } else if (sum > target) {
    return;
  }

  for (int i = index; i < nums.size(); i++) {
    if (i > index && nums[i] == nums[i - 1]) continue;
    sum += nums[i];
    path.push_back(nums[i]);
    combs(nums, target, result, path, sum, i + 1);
    sum -= nums[i];
    path.pop_back();
  }

}

vector < vector < int > > makeCombs(vector < int > &nums, int target) {
  vector < vector < int > > result;
  sort(nums.begin(), nums.end());
  vector < int > path;
  int sum = 0;
  combs(nums, target, result, path, sum, 0);
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

    int target;
    cin>>target;

    vector < vector < int > > result;
    result = makeCombs(nums, target);
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }

  }
  return 0;
}
