#include <bits/stdc++.h>
using namespace std;

int countElemInRange(vector < int > &nums, int low, int high) {
  int i = 0;
  int j = 0;
  int sum = nums[0];
  int count = 0;

  while (j < n) {
    if (sum >= low && sum <= high) {
      count++;
    }

    if (sum > )

  }

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

    int low;
    int high;
    cin>>low>>high;

    cout<<countElemInRange(nums, low, high)<<endl;
  }
  return 0;
}
