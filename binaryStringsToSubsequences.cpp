#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector < int > belongsTo(n, 0);
		queue < pair < string, int > > endsWithOne;
		queue < pair < string , int > > endsWithZero;
		string temp = "";
		int tempNo;
		int subSequenceCount = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				if (endsWithOne.empty() != true) {
					temp = endsWithOne.front().first;
					tempNo = endsWithOne.front().second;
					endsWithOne.pop();
					temp.push_back('0');
					belongsTo[i] = tempNo;
					endsWithZero.push({temp, tempNo});
				} else {
					endsWithZero.push({"0", ++subSequenceCount});
					belongsTo[i] = subSequenceCount;
				}
			} else {
				if (endsWithZero.empty() != true) {
					temp = endsWithZero.front().first;
					tempNo = endsWithZero.front().second;
					endsWithZero.pop();
					temp.push_back('1');
					belongsTo[i] = tempNo;
					endsWithOne.push({temp, tempNo});
				} else {
					endsWithOne.push({"1", ++subSequenceCount});
					belongsTo[i] = subSequenceCount;
				}
			}
		}
		cout<<subSequenceCount<<endl;
		for (auto x : belongsTo) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}