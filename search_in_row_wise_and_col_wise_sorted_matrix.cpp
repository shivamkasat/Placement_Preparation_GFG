#include <bits/stdc++.h>
using namespace std;

int checkElem(vector < vector < int > > &mat, int elem) {
  int m = mat.size();
  int n = mat[0].size();

  int i = 0;
  int j = n - 1;

  while (j >= 0 && i < m) {
    if (mat[i][j] == elem) {
      return 1;
    } else if (mat[i][j] < elem) {
      i++;
    } else {
      j--;
    }
  }

  return 0;

}

int main () {
  int test;
  cin>>test;
  while (test--) {
    int m, n;
    cin>>m>>n;
    vector < vector < int > >mat(m, vector < int >(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin>>mat[i][j];
      }
    }

    int elem;
    cin>>elem;

    cout<<checkElem(mat, elem)<<endl;
  }
  return 0;
}
