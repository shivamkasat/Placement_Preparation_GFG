#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int maxPoints(vector < vector < int > > points) {
  int n = points.size();
  if (n < 2) {
    return n;
  }
  int maxCount = 0;
  int diffy = 0;
  int diffx = 0;
  int gcdp = 0;
  unordered_map < string, int > hmap;
  for (int i = 0; i < n; i++) {
    hmap.clear();
    int dup = 0;
    for (int j = i + 1; j < n; j++) {
      if (points[i].first == points[j].first && points[i].second == points[j].second) {
        dup++;
        continue;
      } else {
        diffy = points[j].second - points[i].second;
        diffx = points[j].first - points[i].first;
        gcdp = gcd(diffy, diffx);
        hmap[to_string(diffy/gcdp) + "_" + to_string(diffx/gcdp)]++;
      }
    }
    ans = max(ans, dup);
    for (auto x : hmap) {
      ans = max(ans, x.second + dup);
    }
  }

  return ans;

}


//O(n3)
int findMaxPoints(vector < int > &X, vector < int > &Y) {
  int n = X.size();
  int maxCount = 0;
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (X[i] == X[j] && Y[i] == Y[j]) continue;
      count = 0;
      for (int k = 0; k < n; k++) {
        if((X[j] - X[i]) * (Y[k] - Y[i]) == (Y[j] - Y[i]) * (X[k] - X[i])) {
          cout<<"x1 = "<<X[i]<<" x2 = "<<X[j]<<" x3 = "<<X[k]<<endl;
          cout<<"y1 = "<<Y[i]<<" y2 = "<<Y[j]<<" y3 = "<<Y[k]<<endl;
          count++;
        }
      }
      maxCount = max(maxCount, count);
    }
  }

  if (maxCount == 0) {
    return n;
  }

  return maxCount;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > Xs(n, 0);
    vector < int > Ys(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>Xs[i];
    }

    for (int i = 0; i < n; i++) {
      cin>>Ys[i];
    }

    cout<<findMaxPoints(Xs, Ys)<<endl;

  }
  return 0;
}
