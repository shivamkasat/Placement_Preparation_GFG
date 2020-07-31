#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, vector < string > &grid) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return false;
  }

  return true;
}

int minCost(int rows, int cols, vector < string > &grid) {
  vector < vector < int > >minCost(rows, vector < int >(cols, INT_MAX));
  vector < vector < bool > >visited(rows, vector < bool >(cols, false));
  minCost[0][0] = 0;
  set < pair < int, pair < int, int > > > s;
  s.insert({0, {0, 0}});
  pair < int , int > currentPos;
  int currentCost = 0;
  int i, j;
  while (s.empty() != true) {
    currentCost = s.begin()->first;
    currentPos = s.begin()->second;
    i = currentPos.first;
    j = currentPos.second;
    visited[i][j] = true;
    s.erase({currentCost, currentPos});

    if (isValid(i, j + 1, grid) && visited[i][j + 1 == false]) {
      if (grid[i][j] == 'R' && minCost[i][j + 1] > minCost[i][j]) {
        if (s.find({minCost[i][j + 1], {i, j + 1}}) != s.end()) {
          s.erase({minCost[i][j + 1], {i, j + 1}});
        }
        minCost[i][j + 1] = minCost[i][j];
        s.insert({minCost[i][j + 1], {i, j + 1}});
      } else if (minCost[i][j + 1] > minCost[i][j] + 1) {
        if (s.find({minCost[i][j + 1], {i, j + 1}}) != s.end()) {
          s.erase({minCost[i][j + 1], {i, j + 1}});
        }
        minCost[i][j + 1] = minCost[i][j] + 1;
        s.insert({minCost[i][j + 1], {i, j + 1}});
      }
    }

    if (isValid(i, j - 1, grid) && visited[i][j - 1] == false) {
      if (grid[i][j] == 'L' && minCost[i][j - 1] > minCost[i][j]) {
        if (s.find({minCost[i][j - 1], {i, j - 1}}) != s.end()) {
          s.erase({minCost[i][j - 1], {i, j - 1}});
        }
        minCost[i][j - 1] = minCost[i][j];
        s.insert({minCost[i][j - 1], {i, j - 1}});
      } else if (minCost[i][j - 1] > minCost[i][j] + 1) {
        if (s.find({minCost[i][j - 1], {i, j - 1}}) != s.end()) {
          s.erase({minCost[i][j - 1], {i, j - 1}});
        }
        minCost[i][j - 1] = minCost[i][j] + 1;
        s.insert({minCost[i][j - 1], {i, j - 1}});
      }
    }

    if (isValid(i - 1, j, grid) && visited[i - 1][j] == false) {
      if (grid[i][j] == 'U' && minCost[i - 1][j] > minCost[i][j]) {
        if (s.find({minCost[i - 1][j], {i - 1, j}}) != s.end()) {
          s.erase({minCost[i - 1][j], {i - 1, j}});
        }
        minCost[i - 1][j] = minCost[i][j];
        s.insert({minCost[i - 1][j], {i - 1, j}});
      } else if (minCost[i - 1][j] > minCost[i][j] + 1) {
        if (s.find({minCost[i - 1][j], {i - 1, j}}) != s.end()) {
          s.erase({minCost[i - 1][j], {i - 1, j}});
        }
        minCost[i - 1][j] = minCost[i][j] + 1;
        s.insert({minCost[i - 1][j], {i - 1, j}});
      }
    }

    if (isValid(i + 1, j, grid) && visited[i + 1][j] == false) {
      if (grid[i][j] == 'D' && minCost[i + 1][j] > minCost[i][j]) {
        if (s.find({minCost[i + 1][j], {i + 1, j}}) != s.end()) {
          s.erase({minCost[i + 1][j], {i + 1, j}});
        }
        minCost[i + 1][j] = minCost[i][j];
        s.insert({minCost[i + 1][j], {i + 1, j}});
      } else if (minCost[i + 1][j] > minCost[i][j] + 1) {
        if (s.find({minCost[i + 1][j], {i + 1, j}}) != s.end()) {
          s.erase({minCost[i + 1][j], {i + 1, j}});
        }
        minCost[i + 1][j] = minCost[i][j] + 1;
        s.insert({minCost[i + 1][j], {i + 1, j}});
      }
    }
  }

  cout<<"-------"<<endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout<<minCost[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"-------"<<endl;

  return minCost[rows - 1][cols - 1];

}

int main() {
  int rows;
  int cols;
  cin>>rows;
  cin>>cols;
  vector < string > grid(rows);
  for (int i = 0; i < rows; i++) {
    cin>>grid[i];
  }
  cout<<minCost(rows, cols, grid);
  return 0;
}
