#include <bits/stdc++.h>
using namespace std;

// int binary_exp(int a, int n, int m) {
//   if (a == 0) {
//     return 0;
//   } else if (n == 0) {
//     return 1;
//   } else if (n % 2 == 0) {
//     return (binary_exp(a, n / 2, m) * binary_exp(a, n / 2, m)) % m;
//   } else {
//     return (binary_exp(a, n - 1, m) * a) % m;
//   }
// }
//
// int binary_pow(int a, int n, int m) {
//   int result = binary_exp(a, n, m);
//   if (result < 0) {
//     return (result + m) % m;
//   }
//   return result;
// }

int binary_exp(int x, int y, int z) {
  long long int a = x;
  long long int n = y;
  long long int m = z;
  if (a == 0) {
    return 0;
  } else if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    int result = binary_exp(a, n / 2, m);
    return (((result + m) % m) * ((result + m) % m) % m);
  } else {
    int result = ((binary_exp(a, n - 1, m) * a) + m) % m;
    return result;
  }
}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int a;
    cin>>a;
    int n;
    cin>>n;
    int m;
    cin>>m;
    cout<<binary_exp(a, n, m)<<endl;
  }
}
