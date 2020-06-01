#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > mergeInterval(vector < vector < int > > &intervals, vector < int > newInterval) {

  int i = 0;
  int n = intervals.size();
  int j = n - 1;
  vector < vector < int > > result;
  vector < int > tempMerged;
  while (i < n && newInterval[0] > intervals[i][1]) {
    i++;
  }
  cout<<"i = "<<i<<endl;

  while (j >= i && newInterval[1] < intervals[j][0]) {
    j--;
  }

  cout<<"j = "<<j<<endl;

  if (i <= j) {
    cout<<"entered merging condition"<<endl;
    //merge intervals
    int k = 0;
    while (k < i) {
      result.push_back(intervals[k]);
      k++;
    }

    int p = newInterval[0];
    int q = newInterval[1];

    if (p < intervals[i][0]) {
      tempMerged.push_back(p);
    } else {
      tempMerged.push_back(intervals[i][0]);
    }

    if (q > intervals[j][1]) {
      tempMerged.push_back(q);
    } else {
      tempMerged.push_back(intervals[j][1]);
    }

    result.push_back(tempMerged);

    k = j + 1;
    while (k < n) {
      result.push_back(intervals[k]);
      k++;
    }

  } else {
    cout<<"entered inserting condition"<<endl;
    int k = 0;
    bool inserted = false;
    while (k < n) {
      if (newInterval[1] < intervals[k][0] && inserted == false) {
        inserted = true;
        result.push_back(newInterval);
      }
      result.push_back(intervals[k]);
      k++;
    }

    if (inserted == false) {
      result.push_back(newInterval);
    }
  }

  return result;

}

int main() {
  int test;
  cin>>test;
  while(test--) {
    int n;
    int first;
    int second;
    cin>>n;
    vector < int > path;
    vector < vector < int > > intervals;
    for (int i = 0; i < n; i++) {
      path.clear();
      cin>>first;
      path.push_back(first);
      cin>>second;
      path.push_back(second);
      intervals.push_back(path);
    }
    vector < int > newInterval;
    cin>>first;
    cin>>second;
    newInterval.push_back(first);
    newInterval.push_back(second);
    vector < vector < int > > result;

    result = mergeInterval(intervals, newInterval);
    for (int i = 0; i < result.size(); i++) {
      cout<<"{"<<result[i][0]<<", "<<result[i][1]<<"}"<<endl;
    }
    cout<<endl;

  }
  return 0;
}
