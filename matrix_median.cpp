// binary search on answer amazing question!
#include <bits/stdc++.h>
using namespace std;

int matrixMedian(vector < vector < int > > &mat) {
  int low = mat[0][0];
  int high = mat[0][0];
  int n = mat.size();
  int m = mat[0].size();
  int mid = 0;

  for (int i = 0; i < n; i++) {
    low = min(low, mat[i][0]);
    high = max(high, mat[i][m - 1]);
  }

  int required = (n * m) / 2 + 1;

  while (low < high) {
    mid = low + (high - low) / 2;
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += (upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin());
    }

    if (count < required) {
      low = mid + 1;
    } else {
      high = mid;
    }

  }

  return low;


}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n, m;
    cin>>n>>m;
    vector < vector < int > >mat(n, vector < int >(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin>>mat[i][j];
      }
    }

    cout<<matrixMedian(mat)<<endl;
  }
  return 0;
}
