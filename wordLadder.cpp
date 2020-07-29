#include <bits/stdc++.h>
using namespace std;


int findSmallestPath(string startWord, string endWord, vector < string > &dict) {
  unordered_map < string, int > dist;
  unordered_map < string, bool > visited;


  for (auto x : dict) {
      dist[x] = INT_MAX;
      visited[x] = false;
  }
   dist[startWord] = 1;
  visited[startWord] = true;

  queue < string > q;
  q.push(startWord);
  string current;
  string tempWord;
  while (q.empty() != true) {
      current = q.front();
      q.pop();

      for (int i = 0; i < current.size(); i++) {
          tempWord = current;
          for (int j = 0; j < 26; j++) {
              tempWord[i] = 'a' + j;
              if (visited.find(tempWord) != visited.end() && visited[tempWord] == false) {
                  // cout<<tempWord<<" is tempWord"<<endl;
                  visited[tempWord] = true;
                  dist[tempWord] = dist[current] + 1;
                  q.push(tempWord);
                  if (tempWord == endWord) {
                      return dist[tempWord];
                  }
              }
          }
      }
  }

  return 0;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string startWord;
    string endWord;
    cin>>startWord;
    cin>>endWord;
    int n;
    cin>>n;
    vector < int > dict;
    string word;
    for (int i = 0; i < n; i++) {
      cin>>word;
      dict.push_back(word);
    }
    cout<<findSmallestPath(startWord, endWord, dict)<<endl;

  }
  return 0;
}
