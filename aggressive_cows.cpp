#include <bits/stdc++.h>
using namespace std;

bool isValid(vector < int > &stalls, int cows, int dist) {
  int check = stalls[0] + dist;
  cows--;
  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] >= check) {
      cows--;
      check = stalls[i] + dist;
    }
  }

  if (cows > 0) {
    return false;
  } else {
    return true;
  }
}

int maxDist(vector < int > &stalls, int cows) {
  sort(stalls.begin(), stalls.end());
  int low = 0;
  int n = stalls.size();
  int high = stalls[n - 1] - stalls[0];
  int mid = 0;
  int result = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (isValid(stalls, cows, mid)) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int stallCount, cows;
    cin>>stallCount;
    cin>>cows;
    vector < int > stalls(stallCount, 0);
    for (int i = 0; i < stallCount; i++) {
      cin>>stalls[i];
    }

    cout<<maxDist(stalls, cows)<<endl;

  }
}
