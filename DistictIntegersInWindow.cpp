#include <bits/stdc++.h>
using namespace std;

vector < int > findSolution(vector < int > &nums, int k) {
  vector < int > result;
  int n = nums.size();
  if (k > n) {
    return result;
  }
  unordered_map < int , int > hmap;
  for (int i = 0; i < k; i++) {
    hmap[nums[i]]++;
  }

  result.push_back(hmap.size());
  int p = 1;
  int q = k;
  while (q < n) {
    hmap[nums[p - 1]]--;
    if (hmap[nums[p - 1]] == 0) {
      hmap.erase(nums[p - 1]);
    }
    hmap[nums[q]]++;
    result.push_back(hmap.size());
    p++;
    q++;
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

    int k;
    cin>>k;

    vector < int > result;
    result = findSolution(nums);
    for (auto x : result) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}
