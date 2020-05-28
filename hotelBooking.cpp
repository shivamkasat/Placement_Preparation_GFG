#include <bits/stdc++.h>
using namespace std;

bool bookingPossible(vector < int > &arrival, vector < int > &departure, int k) {
  bool result = true;
  int n = arrival.size();
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());
  int arri = k;
  int depi = 0;
  int depj = k - 1;

  while (arri < n) {
    if (arrival[arri] > departure[depi]) {
      result = false;
      break;
    }

    arri++;
    depi++;
    depj++;
  }

  return result;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > arrival(n, 0);
    vector < int > departure(n, 0);
    int k;
    for (int i = 0; i < n; i++) {
      cin>>arrival[i];
    }

    for (int i = 0; i < n; i++) {
      cin>>departure[i];
    }

    cin>>k;
    cout<<bookingPossible(arrival, departure, k)<<endl;

  }
  return 0;
}
