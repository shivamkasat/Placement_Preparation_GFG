#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll h, n;
	cin>>h>>n;
	ll attack;
	while (n--) {
		cin>>attack;
		h-=attack;
	}

	if (h > 0) {
		cout<<"No"<<endl;
	} else {
		cout<<"Yes"<<endl;
	}

	return 0;
}
