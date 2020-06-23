#include <bits/stdc++.h>
using namespace std;

vector < vector < int > >  findSolution(vector < int > &nums, target) {
  int n = nums.size();
  vector < vector < int > > result;
  if (n < 4) {
      return result;
  }
  sort(nums.begin(), nums.end());
  unordered_map < int, bool > hmap;
  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;

      hmap.clear();
      for (int k = j + 1; k < n; k++) {
        if (hmap.find(target - (nums[i] + nums[j] + nums[k])) == hmap.end()) {
          hmap[nums[k]] = true;
        } else {
          if(hmap[target - (nums[i] + nums[j] + nums[k])] == true){
            result.push_back({nums[i], nums[j], target-(nums[i] + nums[j] + nums[k]), nums[k]});
            hmap[target - (nums[i] + nums[j] + nums[k])] = false;
          }
        }
      }
    }
  }

  return result;
}

vector < vector < int > > fourSum(vector < int > &nums, int target) {
  vector < vector < int > > result;
  int n = nums.size();
  if (n < 4) {
    return result;
  }
  sort(nums.begin(), nums.end());
  int elem = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;
      int p = j + 1;
      int q = n - 1;
      elem = target - (nums[i] + nums[j]);
      while (p < q) {
        if (nums[p] + nums[q] == elem) {
          result.push_back({nums[i], nums[j], nums[p], nums[q]});
          p++;
          q--;
          while (p < q && nums[p] == nums[p - 1]) {
            p++;
          }
        } else if (nums[p] + nums[q] > elem) {
          q--;
        } else {
          p++;
        }
      }
    }
  }

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
    result = findSolution(nums);
    for (auto x : result) {
      for (auto y : x) {
        cout<<y<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
