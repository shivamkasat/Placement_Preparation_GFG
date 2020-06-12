#include <bits/stdc++.h>
using namespace std;

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector < vector < char > > grid(n, vector < char >(m, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin>>grid[i][j];
      }
    }

    int doubleTiles = 0;
    int singleTiles = 0;

    for (int i = 0; i < n; i++){
      int j = 0;
      while(j < m) {
        if (j + 1 < m && grid[i][j] == '.' && grid[i][j + 1] == '.') {
          // cout<<grid[i][j]<<" "<<grid[i][j + 1]<<endl;
          doubleTiles++;
          j += 2;
        } else if (grid[i][j] == '.'){
          singleTiles++;
          j += 1;
        } else {
          j += 1;
        }
      }
    }

    // cout<<"singleTiles = "<<singleTiles<<"doubleTiles = "<<doubleTiles<<endl;

    if (2 * x <= y) {
      cout<<((singleTiles + (doubleTiles * 2)) * x)<<endl;
    } else {
      cout<<(singleTiles * x + doubleTiles * y)<<endl;
    }

  }
  return 0;
}
