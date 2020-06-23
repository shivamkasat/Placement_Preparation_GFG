#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;



int maxChocs(vector < int > &chocs, int a) {
  priority_queue < int > pq;
  for (int i = 0; i < chocs.size(); i++) {
    pq.push(chocs[i]);
  }

  int chocsEat = 0;
  int choc = 0;
  for (int i = 0; i < a; i++) {
    choc = pq.top();
    pq.pop();
    chocsEat = ((chocsEat % mod) + (choc % mod)) % mod;
    pq.push(floor(choc / 2));
  }

  return chocsEat;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > chocs(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>chocs[i];
    }

    int a;
    cin>>a;

    cout<<maxChocs(chocs, a)<<endl;
  }
  return 0;
}
