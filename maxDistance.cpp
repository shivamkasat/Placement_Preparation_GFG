#include <bits/std++.h>
using namespace std;

int maxDistance(vector < int >  &nums) {
  vector < int > index;
  int n = nums.size();
  priority_queue < pair < int, int >, vector < int >, greater < int > > heap;
  for (int i = 0; i < n; i++) {
    heap.push(make_pair(nums[i], i));
  }

  while (heap.empty() != true) {
    index.push_back(heap.top().second);
    heap.pop();
  }

  vector < int > sufIndex(n);
  sufIndex[n - 1] = index[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sufIndex[i] = max(sufIndex[i + 1], index[i]);
  }

  int maxDis = 0;
  for (int i = 0; i < n; i++) {
    maxDis = max(maxDis, sufIndex[i] - index[i]);
  }

  return maxDis;
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

    cout<<maxDistance(nums)<<endl;
  }
  return 0;
}
