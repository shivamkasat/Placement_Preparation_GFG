#include <bits/stdc++.h>
using namespace std;

int main() {
  int test;
  cin>>test;
  while (test--) {
    int hot, cold, temp;
    cin>>hot>>cold>>temp;
    if (temp == hot) {
      cout<<"1"<<endl;
    } else if (2 * temp <= hot + cold ) {
      cout<<"2"<<endl;
    } else {
      long long int x = (temp - cold) / (2 * temp - (hot + cold));
      long long int y = x + 1;
      long double temp1 = ((hot * x) + ((x - 1) * cold)) / (1.0 * (2 * x - 1));
      long double temp2 = ((hot * (y)) + ((y - 1) * cold)) / (1.0 * (2 * y - 1));

      if (abs(temp1 - temp) <= abs(temp2 - temp)) {
        cout<<(2 * x - 1)<<endl;
      } else {
        cout<<(2 * y - 1)<<endl;
      }
    }
  }
  return 0;
}
