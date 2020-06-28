#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector < string > &board) {
  int n = board.size();
  for (int i = 0; i < n; i++) {
    if (board[i][col] == 'Q' && (i != row)) {
      return false;
    }
  }

  for (int j = 0; j < n; j++) {
    if (board[row][j] == 'Q' && (j != col)) {
      return false;
    }
  }

  for (int i = row, j = col; i < board.size() && j < board.size(); i++, j++) {
    if (board[i][j] == 'Q' && (i != row && j != col)) {
      return false;
    }
  }

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q' && (i != row && j != col)) {
      return false;
    }
  }

  for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
    if (board[i][j] == 'Q' && (i != row && j != col)) {
      return false;
    }
  }

  for (int i = row, j = col; j < board.size() && i >= 0; j++, i--) {
    if (board[i][j] == 'Q' && (i != row && j != col)) {
      return false;
    }
  }


  return true;
}

void solveQueens(int n, vector < vector < string > > &result, vector < string > &board, int index) {
  if (index == board.size()) {
    result.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (isValid(index, i, board)) {
      board[index][i] = 'Q';
      solveQueens(n, result, board, index + 1);
      board[index][i] = '.';
    }
  }

}

vector < vector < string > > placeQueens(int n) {
  vector < vector < string > > result;
  // if (n < 4) {
  //   return result;
  // }
  string temp(n, '.');
  vector < string > board(n, temp);
  int index = 0;
  solveQueens(n, result, board, index);
  return result;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < vector < string > > result;
    result = placeQueens(n);
    for (int i = 0; i < result.size(); i++) {
      cout<<i + 1<<" placement order"<<endl;
      for (int j = 0; j < result[i].size(); j++) {
        for (int k = 0; k < result[i][j].size(); k++) {
          cout<<result[i][j][k];
        }
        cout<<endl;
      }
      cout<<"------------"<<endl;
    }

  }
  return 0;
}
