#include <bits/stdc++.h>
using namespace std;

bool comp(pair < int, int > a, pair <int, int > b) {
  if (a.first > a.second) {
    return true
  } else if (a.first == b.first) {
    if (a.second > b.second) {
      return true;
    }
  }
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int num;
    vector < int > hmap(61, 0);
    for (int i = 0; i < n; i++) {
      cin>>num;
      hmap[num]++;
    }

    vector < pair < int, int> > freqAndNumber;
    for (int i = 1; i < 61; i++){
      if (hmap[i] != 0)
        freqAndNumber.push_back({hmap[i], i})
    }

    sort(freqAndNumber.begin(), freqAndNumber.end(), comp);
    for (auto itr = freqAndNumber.begin(); itr != freqAndNumber.end(); itr++) {
      for (int i = 0; i < freqAndNumber->first; i++) {
        cout<<itr->second<<" ";
      }
    }

    cout<<endl;

  }
  return 0;
}
