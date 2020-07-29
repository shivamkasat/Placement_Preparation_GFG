//dfs gets acceptd but bfs gives memory limit exceed
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector < string > &board, string searchWord, int i, int j, int index) {
  if (index == searchWord.size()) {
    return true;
  } else if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != searchWord[index]) {
    return false;
  }

  bool left = dfs(board, searchWord, i, j - 1, index + 1);
  bool right = dfs(board, searchWord, i, j + 1, index + 1);
  bool up = dfs(board, searchWord, i - 1, j, index + 1);
  bool down = dfs(board, searchWord, i + 1, j, index + 1);

  return left || right || up || down;
}

bool findBoard(vector < string > &board, string searchWord) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == searchWord[0]) {
        if (dfs(board, searchWord, i, j, 0) == true) {
          return true;
        }
      }
    }
  }

  return false;
}
//
// bool isValid(int i, int j, vector < string > &board, string &searchWord, int index) {
//   if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != searchWord[index]) {
//     return false;
//   }
//
//   return true;
// }
//
// bool exist(vector < string > &board, string searchWord) {
//   unordered_map < char, vector < pair < int, int > > > hmap;
//   int lastIndex = searchWord.length() - 1;
//   for (int i = 0; i < board.size(); i++) {
//     for (int j = 0; j < board[i].size(); j++) {
//       hmap[char(board[i][j])].push_back({i, j});
//     }
//   }
//
//   queue < pair < int, pair <int, int > > > q;
//
//   for (auto p : hmap[char(searchWord[0])]) {
//     q.push({p.first, {p.second, 0}});
//   }
//
//   pair < int, pair < int, int > > pp;
//   int i;
//   int j;
//   int index;
//   while (q.empty() != true) {
//     pp = q.front();
//     i = pp.first;
//     j = pp.second.first;
//     index = pp.second.second;
//     q.pop();
//     if (index == lastIndex) {
//       return true;
//     }
//
//     if (isValid(i + 1, j, board, searchWord, index + 1)) {
//       q.push({i + 1, {j, index + 1}});
//     }
//
//     if (isValid(i - 1, j, board, searchWord, index + 1)) {
//       q.push({i - 1, {j, index + 1}});
//     }
//
//     if (isValid(i, j + 1, board, searchWord, index + 1)) {
//       q.push({i, {j + 1, index + 1}});
//     }
//
//     if (isValid(i, j - 1, board, searchWord, index + 1)) {
//       q.push({i, {j - 1, index + 1}});
//     }
//
//   }
//
//   return false;
// }

int main() {
  int test;
  cin>>test;
  while (test--) {
    vector < string > board;
    int wordCount;
    cin>>wordCount;
    string word;
    for (int i = 0; i < wordCount; i++) {
      cin>>word;
      board.push_back(word);
    }
    int searchCount;
    string searchWord;
    cin>>searchCount;
    while (searchCount--) {
      cin>>searchWord;
      cout<<findBoard(board, searchWord)<<endl;
      // cout<<exist(board, searchWord)<<endl;
    }
  }
  return 0;
}
