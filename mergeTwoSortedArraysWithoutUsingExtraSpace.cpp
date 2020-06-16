#include <bits/stdc++.h>
using namespace std;

void merge(vector < int > &list1, vector < int > &list2) {
  int n1 = list1.size();
  int n2 = list2.size();

  int last = 0;
  int j = 0;
  for (int i = n2 - 1; i >= 0; i--) {
    j = n1 - 2;
    last = list1[j + 1];
    while (j >= 0 && list1[j] >= list2[i]) {
      list1[j + 1] = list1[j];
      j--;
    }

    if (j != n1 - 2 || last > list2[i]) {
      list1[j + 1] = list2[i];
      list2[i] = last;
    }
  }
}

int main () {
  int test;
  cin>>test;
  while (test--) {
    int n1;
    cin>>n1;
    vector < int > list1;
    int data;
    for (int i = 0; i < n1; i++) {
      cin>>data;
      list1.push_back(data);
    }

    int n2;
    cin>>n2;
    vector < int > list2;
    for (int i = 0; i < n2; i++) {
      cin>>data;
      list2.push_back(data);
    }

    merge(list1, list2);

    for (int i = 0; i < n1; i++) {
      cout<<list1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n2; i++) {
      cout<<list2[i]<<" ";
    }
    cout<<endl;

  }
  return 0;
}
