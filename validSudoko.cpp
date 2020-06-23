#include <bits/stdc++.h>
using namespace std;

bool checkValid(vector < vector < char > > &board) {
  unordered_map < int, unordered_set < char > > rowHash;
  unordered_map < int , unordered_set < char > > colHash;
  unordered_map < string , unordered_set < char > > gridHash;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (rowHash[i].find(board[i][j]) == rowHash[i].end()) {
        rowHash[i].insert(board[i][j]);
      } else {
        return false;
      }

      if (colHash[j].find(board[i][j]) == colHash[j].end()) {
        colHash[j].insert(board[i][j]);
      } else {
        return false;
      }

      int rowNum = i / 3;
      int colNum = j / 3;
      string index = to_string(rowNum) + to_string(colNum);
      if (gridHash[index].find(board[i][j]) == gridHash[index].end()) {
        gridHash[index].insert(board[i][j]);
      } else {
        return false;
      }
      
    }
  }

  return true;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    vector < vector < char > > board = {{"5","3",".",".","7",".",".",".","."},
                                        {"6",".",".","1","9","5",".",".","."},
                                        {".","9","8",".",".",".",".","6","."},
                                        {"8",".",".",".","6",".",".",".","3"},
                                        {"4",".",".","8",".","3",".",".","1"},
                                        {"7",".",".",".","2",".",".",".","6"},
                                        {".","6",".",".",".",".","2","8","."},
                                        {".",".",".","4","1","9",".",".","5"},
                                        {".",".",".",".","8",".",".","7","9"}
                                      };

    cout<<checkValid(vector < vector < char > > &board)<<endl;


  }
  return 0;
}
