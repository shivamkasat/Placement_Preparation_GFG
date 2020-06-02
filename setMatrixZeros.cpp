#include <bits/stdc++.h>
using namespace std;

void setZeros(vector < vector < int > > &mat) {
  int m = mat.size();
  int n = mat[0].size();
  vector < int > rowZeros(m, 1);
  vector < int > colZeros(n, 1);
  for (int i = 0; i < m ; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        rowZeros[i] = 0;
        colZeros[j] = 0;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = mat[i][j] * rowZeros[i] * colZeros[j];
    }
  }

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int m,n;
    cin>>m>>n;
    vector < vector < int > > mat(m, vector < int >(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin>>mat[i][j];
      }
    }

  setZeros(mat);
  }
  return 0;
}
