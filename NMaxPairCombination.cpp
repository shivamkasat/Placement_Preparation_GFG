#include <bits/stdc++.h>
using namespace std;

vector < int > findKMaxCombs(vector < int > &numsa, vector < int > &numbs, int k) {
  sort(numsa.begin(), numsa.end(), greater < int >);
  sort(numsb.begin(), numsb.end(), greater < int >);

  priority_queue < pair < int, pair < int, int > > > pq;
  set < pair < int, int > > hset;
  pair < int, pair < int, int > > temp;
  vector < int > result;
  int n = numsa.size();
  int i = 0;
  int j = 0;

  pq.push({numsa[0] + numsb[0], {0, 0}});
  hset.insert({0, 0});

  for (int count = 0; count < k; count++) {
    temp = pq.top();
    pq.pop();
    result.push_back(temp.first);

    i = temp.second.first;
    j = temp.second.second;

    if ( i + 1 < n && hset.find({i + 1, j}) == hset.end()) {
      pq.push({numsa[i + 1] + numsb[j], {i + 1, j}});
      hset.insert({i + 1, j});
    }

    if (j + 1 < n && hset.find({i, j + 1}) == hset.end()) {
      pq.push({numsa[i] + numsb[j + 1], {i, j + 1}});
      hset.insert({i, j + 1});
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
    vector < int > numsa(n, 0);
    vector < int > numsb(n, 0);

    for (int i = 0; i < n; i++) {
      cin>>numsa[i];
    }

    for (int i = 0; i < n; i++) {
      cin>>numsb[i];
    }

    int k;
    cin>>k

    vector < int > result;
    result = findKMaxCombs(numsa, numsb, k);
    for (auto x : result) {
      cout<<x<<" ";
    }
    cout<<endl;


  }
  return 0;
}
