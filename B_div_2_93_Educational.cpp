#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		string str;
		cin>>str;
		priority_queue < int, vector < int > > pq;
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				pq.push(count);
				count = 0;
			} else {
				count++;
			}
		}

		if (str[str.length() - 1] == '1') {
			pq.push(count);
		} 

		int ans = 0;
		while (pq.empty() != true) {
			ans += pq.top();
			pq.pop();
			if (pq.empty() != true) {
				pq.pop();
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}