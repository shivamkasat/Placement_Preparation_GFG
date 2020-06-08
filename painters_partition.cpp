#include <bits/stdc++.h>
#define ll long long
#define mod 10000003
using namespace std;

bool isValid(vector < ll > &boards, ll painters, ll cost, ll minTime) {
  ll neededPainters = 1;
  ll totTime = 0;
  for (int i = 0; i < boards.size(); i++) {
    if (boards[i] * cost > minTime) {
      return false;
    }

    totTime = totTime + cost * boards[i];

    if (totTime > minTime) {
      neededPainters++;
      totTime = boards[i] * cost;
    }
  }

  if (neededPainters > painters) {
    return false;
  } else {
    return true;
  }
}

int minCost(vector < int > &b, int p, int c) {
  vector < ll > boards(b.begin(), b.end());
  ll painters = p;
  ll cost = c;
  ll low = 0;
  ll high = 0;
  ll mid = 0;
  ll result = 0;
  for (int i = 0; i < boards.size(); i++) {
    low = low > cost * boards[i] ? low : cost * boards[i];
    high = high + cost * boards[i];
  }

  cout<<"low = "<<low<<" high = "<<high<<endl;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (isValid(boards, painters, cost, mid)) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result % mod;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > boards(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>boards[i];
    }

    int painters, cost;
    cin>>painters>>cost;

    cout<<minCost(boards, painters, cost)<<endl;

  }
  return 0;
}
