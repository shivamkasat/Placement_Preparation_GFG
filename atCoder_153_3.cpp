#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll h, k;
	cin>>h>>k;

	if (k > h) {
		cout<<0<<endl;
		return 0;
	}
	vector < int > health;
	ll data;
	for (ll i = 0; i < h; i++) {
		cin>>data;
		health.push_back(data);
	}

	sort(health.begin(), health.end(), greater < ll >());

	for (int i = 0; i < k; i++) {
		health[i] = 0;
	}

	ll sum = 0;
	for (int i = 0; i < health.size(); i++) {
		sum+= health[i];
	}

	cout<<sum<<endl;
	return 0;
}
