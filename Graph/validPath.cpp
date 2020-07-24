#include <bits/stdc++.h>
using namespace std;
//not correct solution! not able to find the error!
//do try again!
//manhattan distance and euclidean distance me farak hota hai bhai!
bool isValid(int i, int j, int x, int y, vector < int > &xcord, vector < int > &ycord, int radius, vector < vector < int > > &grid) {
  if (i < 0 || j < 0 || i > x || j > y || grid[i][j] == 1) {
    return false;
  }

  for(int k = 0; k < xcord.size(); k++) {
    if ((i - xcord[k]) * (i - xcord[k]) + (j - ycord[k]) * (j - ycord[k]) <= radius * radius) {
      return false;
    }
  }
  return true;
}
string solve(int x, int y, int circles, int radius, vector < int > &xcord, vector < int >&ycord) {
  queue < pair < int, int > >q;
  vector < int > dx = {1, 0, -1, 0, 1, -1, 1, -1};
  vector < int > dy = {0, 1, 0, -1, 1, -1, -1, 1};
  vector < vector < int > >grid(x + 1, vector < int >(y + 1, 0));
  if (isValid(0, 0, x, y, xcord, ycord, radius, grid)) {
    q.push({0, 0});
  } else {
    return "NO";
  }
  pair < int, int > current;
  int i;
  int j;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    i = current.first;
    j = current.second;
    grid[i][j] = 1;
    if (i == x && j == y) {
      return "YES";
    }

    for (int k = 0; k < 8; k++) {
      if (isValid(i + dx[k], j + dy[k], xcord, ycord, radius, grid)) {
        q.push({i + dx[k], j + dy[k]});
      }
    }
  }

  return "NO";
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int x;
    cin>>x;
    int y;
    cin>>y;
    int circles;
    cin>>circles;
    int radius;
    cin>>radius;
    vector < int > xcord(circles, 0);
    vector < int > ycord(circles, 0);
    for (int i = 0; i < circles; i++) {
      cin>>xcord[i];
    }

    for (int j = 0; j < circles; j++) {
      cin>>ycord[j];
    }

    cout<<solve(x, y, circles, radius, xcord, ycord)<<endl;
  }
  return 0;
}
35
26
6
8
25 33 28 16 15 11
19 7 3 24 17 2
