#include <bits/stdc++.h>
using namespace std;

int findMaxDistance(vector < int > &nums) {
  unordered_map < int, vector < int > > hmap;
  int maxDistance = 0;
  for (int i = 0; i < nums.size(); i++) {
    hmap[nums[i]].push_back(i);
  }

  sort(nums.begin(), nums.end());
  vector < int > sortedIndex;
  for (int i = 0; i < nums.size(); i++) {
    sortedIndex.push_back(hmap[nums[i]].front);
    hmap[nums[i]].pop_front();
  }

  int i = 0;
  int j = 0;
  while (i < n && j < n) {
    while (j < n && sortedIndex[j] > sortedIndex[i]) {
      j++;
    }

    maxDistance = max(maxDistance, j - i);
    i = j;
  }

  maxDistance = max(maxDistance, j - i)

  if (maxDistance <= 0) {
    return -1;
  }
  return maxDistance;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < nums.size(); i++) {
      cin>>nums[i];
    }

    cout<<findMaxDistance(nums);
  }
  return 0;
}
