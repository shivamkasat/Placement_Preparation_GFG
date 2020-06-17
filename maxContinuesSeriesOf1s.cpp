#include <bits/stdc++.h>
using namespace std;

vector < int > maxSeries(vector < int > &nums, int maxFlips) {
  int i = 0;
  int j = 0;
  int count = 0;
  int maxLength = 0;
  int low = 0;
  int n = nums.size();

  while (j < n) {
    if (nums[j] == 1) {
      j++;
    } else {
      if (count < maxFlips) {
        count++;
        j++;
      } else {
        if (j - i > maxLength) {
          maxLength = j - i;
          low = i;
        }

        if (i != j) {
          if (nums[i] == 0) {
            count--;
          }
          i++;
        } else {
          i++;
          j++;
        }
      }
    }
  }

  if (j - i > maxLength) {
    maxLength = j - i;
    low = i;
  }


  vector < int > result;
  for (int i = low; i < low + maxLength; i++) {
    result.push_back(i);
  }

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

    int m;
    cin>>m;

    vector < int > result;
    result = maxSeries(nums, m);

    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;

  }
  return 0;
}
