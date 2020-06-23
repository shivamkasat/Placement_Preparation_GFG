#include <bits/stdc++.h>
using namespace std;

vector < int > findSolution(vector < int > &nums) {
  unordered_map < int , vector < pair < int, int > > > hmap;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (hmap[nums[i] + nums[j]] == hmap.end()) {
        hmap[nums[i] + nums[j]].push_back({i, j});
      } else {
        if (hmap[nums[i] + nums[j]].first < i && hmap[nums[i] + nums[j]].second != i && hmap[nums[i] + nums[j]].second != j) {
          hmap[nums[i] + nums[j]].push_back({i, j});
        }
      }
    }
  }

  vector < int > result;

  for (auto itr = hmap.begin(); itr != hmap.end(); itr++) {
    if (itr->second.size() > 1) {
      if (result.empty() == true) {
        result = {itr->second[0].first, itr->second[0].second, itr->second[1].first, itr->second[1].second};
      } else {
        if (itr.second[0].first < result[0]) {
          result = {itr->second[0].first, itr->second[0].second, itr->second[1].first, itr->second[1].second};
        } else if (itr->second[0].first == result[0] && itr->second[0].second < result[1]) {
          result = {itr->second[0].first, itr->second[0].second, itr->second[1].first, itr->second[1].second};
        } else if (itr->second[0].first == result[0] && itr->second[0].second == result[1] && itr->second[1].first < result[2]) {
          result = {itr->second[0].first, itr->second[0].second, itr->second[1].first, itr->second[1].second};
        } else if (itr->second[0].first == result[0] && itr->second[0].second == result[1] && itr->second[1].first == result[2] && itr->second[1].first < result[3]) {
          result = {itr->second[0].first, itr->second[0].second, itr->second[1].first, itr->second[1].second};
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
    vector < int > result;
    result = findSolution(nums);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
