#include <bits/stdc++.h>
using namespace std;

void preetyPrint(int A) {
  int n = 1 + (A - 1) * 2;
  vector < vector < int > > mat(n, vector < int >(n, A));
  int left = 0;
  int right = 0;
  int val = A;
  for (int i = 1; i <= n / 2; i++) {
    mat[i] = mat[i - 1];
    left = i;
    right = n - i - 1;
    val--;
    while(left <= right) {
      mat[i][left] = val;
      left++;
    }
  }

  for (int i = n - 1; i > n / 2; i--) {
    mat[i] = mat[n - i - 1];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int A;
    cin>>A;
    preetyPrint(A);
  }
}
